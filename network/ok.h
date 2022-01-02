/**
 *  @file Ok.hpp
 *
 *  Mysql Ok 包
 *
 *  Copyright © 2020 by LiuJ
 */

#pragma once

#include <unistd.h>

#include <iostream>
#include <memory>
#include <vector>

namespace Protocol {

class OkPacket {
 public:
  ~OkPacket() noexcept;
  OkPacket(const OkPacket&) = delete;
  OkPacket(OkPacket&&) noexcept = delete;
  OkPacket& operator=(const OkPacket&) = delete;
  OkPacket& operator=(OkPacket&&) noexcept = delete;
  OkPacket();

  std::vector<uint8_t> Pack(uint64_t affectedRows, uint64_t lastInsertID,
                            uint16_t statusFlags, uint16_t warnings);

 private:
  struct Impl;

  std::unique_ptr<Impl> impl_;
};

}  // namespace Protocol
