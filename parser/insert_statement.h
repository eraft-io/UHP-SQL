#ifndef SQLPARSER_INSERT_STATEMENT_H
#define SQLPARSER_INSERT_STATEMENT_H

#include "select_statement.h"
#include "sql_statement.h"

namespace hsql {
enum InsertType { kInsertValues, kInsertSelect };

// Represents SQL Insert statements.
// Example: "INSERT INTO students VALUES ('Max', 1112233, 'Musterhausen', 2.3)"
struct InsertStatement : SQLStatement {
  InsertStatement(InsertType type);
  ~InsertStatement() override;

  InsertType type;
  char* schema;
  char* tableName;
  std::vector<char*>* columns;
  std::vector<Expr*>* values;
  SelectStatement* select;
};

}  // namespace hsql

#endif
