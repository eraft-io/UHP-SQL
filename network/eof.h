/**
 *  @file Eof.hpp
 *
 *  Mysql Eof 包
 *
 *  Copyright © 2020 by LiuJ
 */

#pragma once

#include <unistd.h>

#include <iostream>
#include <memory>
#include <vector>

namespace Protocol {

class EofPacket {
 public:
  ~EofPacket() noexcept;
  EofPacket(const EofPacket&) = delete;
  EofPacket(EofPacket&&) noexcept = delete;
  EofPacket& operator=(const EofPacket&) = delete;
  EofPacket& operator=(EofPacket&&) noexcept = delete;
  EofPacket();

  EofPacket(uint16_t warnFlag, uint16_t statusFlag);
  /**
   * 编码 Eof 包
   */
  std::vector<uint8_t> Pack();

  /**
   * 解码 Eof 包
   */
  bool UnPack(std::vector<uint8_t>& packet);

  /**
   * 包头部
   */
  uint8_t GetHeader();

  /**
   * 警告标志
   */
  uint16_t GetWarning();

  /**
   * 状态标志
   */
  uint16_t GetStatusFlags();

 private:
  struct Impl;

  std::unique_ptr<Impl> impl_;
};

}  // namespace Protocol
