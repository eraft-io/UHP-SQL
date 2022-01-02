/**
 *  @file Field.hpp
 *
 *  Mysql Field 包
 *
 *  Copyright © 2020 by LiuJ
 */

#pragma once

#include <unistd.h>

#include <iostream>
#include <memory>
#include <vector>

namespace Protocol {

class FieldPacket {
 public:
  ~FieldPacket() noexcept;
  FieldPacket(const FieldPacket&) = delete;
  FieldPacket(FieldPacket&&) noexcept = delete;
  FieldPacket& operator=(const FieldPacket&) = delete;
  FieldPacket& operator=(FieldPacket&&) noexcept = delete;
  FieldPacket();

  /**
   *  编码 Field 包
   */
  std::vector<uint8_t> Pack();

  FieldPacket(std::string name, uint32_t type, std::string table,
              std::string orgTable, std::string dataBase, std::string orgName,
              uint32_t columnLength, uint32_t charset, uint32_t decimals,
              uint32_t flags);
  /**
   *  解码 Field 包
   */
  bool UnPack(std::vector<uint8_t>& packet);

  std::string ToString();

 private:
  struct Impl;

  std::unique_ptr<Impl> impl_;
};

class RowPacket {
 public:
  ~RowPacket() noexcept;
  RowPacket(const RowPacket&) = delete;
  RowPacket(RowPacket&&) noexcept = delete;
  RowPacket& operator=(const RowPacket&) = delete;
  RowPacket& operator=(RowPacket&&) noexcept = delete;
  RowPacket();

  std::string ToString();
  RowPacket(std::vector<std::string>& row);
  /**
   * 编码 Row
   */
  std::vector<uint8_t> Pack();

  /**
   *  解码 Row
   */
  bool UnPack(std::vector<uint8_t>& packet, size_t colCount);

 private:
  struct Impl;

  std::unique_ptr<Impl> impl_;
};

}  // namespace Protocol
