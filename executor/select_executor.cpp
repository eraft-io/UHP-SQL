// Copyright 2015 The uhp-sql Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "../network/common.h"
#include "../network/eof.h"
#include "../network/field.h"
#include "../network/ok.h"
#include "../network/stream_socket.h"
#include "../network/string_utils.h"
#include "executor.h"

namespace uhp_sql
{

  bool Executor::AnalyzeSelectStatement(const hsql::SelectStatement *stmt,
                                        hsql::OperatorType &op_type,
                                        std::string &query_tab,
                                        std::string &query_feild,
                                        std::string &query_value, uint64_t &limit,
                                        uint64_t &offset)
  {
    query_tab = stmt->fromTable->name;
    hsql::Expr *expr = stmt->whereClause;
    if (!expr)
    {
      // SELECT * FROM tab; scan all data
      return false;
    }
    switch (expr->type)
    {
    case hsql::kExprOperator:
    {
      op_type = expr->opType;
      query_feild = expr->expr->name;
      query_value = expr->expr2->name;
      break;
    }
    default:
      break;
    }
    if (stmt->limit != nullptr)
    {
      limit = static_cast<uint64_t>(stmt->limit->limit->ival);
    }
    else
    {
      limit = 0;
    }
    return true;
  }

  std::vector<TableColumn> Executor::DecodeRowResult(std::string res, std::string tab)
  {
    std::vector<std::string> cols = StringSplit(res, "$$");
    std::map<int, std::string> indexColMap = Executor::dbmsContext->GetCurDB()
                                                 ->GetTable(tab)
                                                 ->GetIndexColMap();
    std::vector<TableColumn> row;
    for (uint64_t i = 0; i < cols.size(); i++)
    {
      TableColumn newCol(
          indexColMap[i],
          Executor::dbmsContext->GetCurDB()->GetTable(tab)->GetColType(
              indexColMap[i]),
          cols[i]);
      row.push_back(std::move(newCol));
    }
    return std::move(row);
  }

  std::vector<std::vector<TableColumn> > Executor::SelectRowsFromPMemKV(
      hsql::OperatorType &op_type, std::string &query_tab,
      std::string &query_feild, std::string &query_value, uint64_t &limit,
      uint64_t &offset)
  {
    std::vector<std::vector<TableColumn> > rows = {};
    switch (op_type)
    {
    case hsql::kOpEquals:
    {
      std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
      std::string key =
          "data_" + dbName + "_" + query_tab + "_p_" + query_value;
      std::string result;
      redisReply *reply = static_cast<redisReply *>(
          redisCommand(pmemRedisContext, "GET %s", key.c_str()));
      if (reply->str != nullptr)
      {
        result = std::string(reply->str);
        freeReplyObject(reply);
      }
      else
      {
        return rows;
      }
      std::cout << "select res: " << result << std::endl;
      auto row = DecodeRowResult(result, query_tab);
      rows.push_back(std::move(row));
      break;
    }
    case hsql::kOpGreater:
    {
      std::cout << " limit " << limit << std::endl;
      std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
      std::string key =
          "data_" + dbName + "_" + query_tab + "_p_" + "*";

      redisReply *reply = (redisReply *)redisCommand(Executor::GetContext(),
                                                     "SCAN 0 MATCH %s COUNT 100", key.c_str());
      if (reply->element != nullptr)
      {
        if (reply->element[1]->elements == 0)
        {
          return rows;
        }
        for (int i = 0; i < reply->element[1]->elements;)
        {
          if (limit != 0 && i > limit * 2)
          {
            break;
          }
          std::string pkey = reply->element[1]->element[i++]->str;
          std::string rowVal = reply->element[1]->element[i++]->str;
          if (pkey.compare(std::string("data_" + dbName + "_" + query_tab + "_p_" + query_value)) > 0)
          {
            std::cout << "return " << pkey << " to cli " << std::endl;
            auto row = DecodeRowResult(rowVal, query_tab);
            rows.push_back(std::move(row));
          }
        }
        if (reply)
        {
          freeReplyObject(reply);
        }
      }
      break;
    }
    case hsql::kOpLike:
    {
      std::cout << " LIKE " << std::endl;
      std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
      if (query_value.back() == '%')
      {
        query_value.pop_back();
      }
      std::string key =
          "data_" + dbName + "_" + query_tab + "_p_" + query_value + "*";

      redisReply *reply = (redisReply *)redisCommand(Executor::GetContext(),
                                                     "SCAN 0 MATCH %s COUNT 100", key.c_str());
      if (reply->element != nullptr)
      {
        if (reply->element[1]->elements == 0)
        {
          return rows;
        }
        for (int i = 0; i < reply->element[1]->elements;)
        {
          if (limit != 0 && i > limit * 2)
          {
            break;
          }
          std::string pkey = reply->element[1]->element[i++]->str;
          std::string rowVal = reply->element[1]->element[i++]->str;
          std::cout << "return " << pkey << " to cli " << std::endl;
          auto row = DecodeRowResult(rowVal, query_tab);
          rows.push_back(std::move(row));
        }
        if (reply)
        {
          freeReplyObject(reply);
        }
      }
      break;
    }
    default:
      break;
    }
    return rows;
  }

  bool Executor::SendResultSetToClient(
      Client *cli, uint8_t seq,
      std::vector<std::vector<TableColumn> > &result_set,
      std::string &query_tab)
  {
    // std::cout << "res name : " << result_set[0][0].GetColName() << std::endl;
    std::string dbname = Executor::dbmsContext->GetCurDB()->GetDbName();
    seq = 1;
    UnboundedBuffer reply_;
    // Result Set Header
    std::vector<uint8_t> header;
    uint8_t fieldcount =
        Executor::dbmsContext->GetCurDB()->GetTable(query_tab)->GetColCount();
    header.push_back(1);
    header.push_back(0);
    header.push_back(0);
    header.push_back(seq);
    header.push_back(fieldcount);
    reply_.PushData(std::string(header.begin(), header.end()).c_str(),
                    header.size());
    cli->SendPacket(reply_);
    reply_.Clear();
    seq++;
    // Field
    for (int i = 0; i < fieldcount; ++i)
    {
      // get field from meta
      std::string colname = Executor::dbmsContext->GetCurDB()->GetTable(query_tab)->GetIndexColMap()[i];
      std::cout << "return col name to cli " << colname << std::endl;
      std::cout << colname << "\n";
      Protocol::FieldPacket new_field_pack(
          colname, static_cast<uint32_t>(TYPE_VARCHAR), query_tab, query_tab,
          dbname, colname, 80, CHARACTER_SET_UTF8, 0, 0);
      std::vector<uint8_t> field_pack = new_field_pack.Pack();
      std::vector<uint8_t> out_pack4;
      out_pack4.push_back(field_pack.size());
      out_pack4.push_back(0);
      out_pack4.push_back(0);
      out_pack4.push_back(seq);
      out_pack4.insert(out_pack4.end(), field_pack.begin(), field_pack.end());
      reply_.PushData(std::string(out_pack4.begin(), out_pack4.end()).c_str(),
                      out_pack4.size());
      cli->SendPacket(reply_);
      reply_.Clear();
      seq++;
    }
    // EOF col end
    Protocol::EofPacket eof(0, 2);
    std::vector<uint8_t> eof_packet = eof.Pack();
    std::vector<uint8_t> new_out_pack;
    new_out_pack.push_back(eof_packet.size());
    new_out_pack.push_back(0);
    new_out_pack.push_back(0);
    new_out_pack.push_back(seq);
    new_out_pack.insert(new_out_pack.end(), eof_packet.begin(), eof_packet.end());
    reply_.PushData(std::string(new_out_pack.begin(), new_out_pack.end()).c_str(),
                    new_out_pack.size());
    cli->SendPacket(reply_);
    reply_.Clear();
    seq++;
    // Row Data
    std::vector<std::string> row;
    for (auto &coldata : result_set)
    {
      row.clear();
      for (auto &data : coldata)
      {
        row.push_back(data.GetVal());
      }
      Protocol::RowPacket row_pack(row);
      std::vector<uint8_t> row_packet = row_pack.Pack();
      std::vector<uint8_t> out_pack;
      out_pack.push_back(row_packet.size());
      out_pack.push_back(0);
      out_pack.push_back(0);
      out_pack.push_back(seq);
      out_pack.insert(out_pack.end(), row_packet.begin(), row_packet.end());
      reply_.PushData(std::string(out_pack.begin(), out_pack.end()).c_str(),
                      out_pack.size());
      cli->SendPacket(reply_);
      reply_.Clear();
      seq++;
    }
    // EOF data end
    Protocol::EofPacket eofBack(0, 2);
    std::vector<uint8_t> eofBackPacket = eofBack.Pack();
    std::vector<uint8_t> outPack1;
    outPack1.push_back(eofBackPacket.size());
    outPack1.push_back(0);
    outPack1.push_back(0);
    outPack1.push_back(seq);
    outPack1.insert(outPack1.end(), eofBackPacket.begin(), eofBackPacket.end());
    reply_.PushData(std::string(outPack1.begin(), outPack1.end()).c_str(),
                    outPack1.size());
    cli->SendPacket(reply_);
    reply_.Clear();

    // SendOkMessageToClient(cli, seq, 0, 0, 2, 0);
    return true;
  }

} // namespace uhp_sql
