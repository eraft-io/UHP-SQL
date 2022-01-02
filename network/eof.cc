/**
 *  @file Eof.cpp
 *
 *  Mysql Eof 包编解码实现
 *
 *  Copyright © 2020 by LiuJ
 */

#include "eof.h"

#include "common.h"
#include "protocol_buffer.h"

namespace Protocol {

struct EofPacket::Impl {
  /**
   * 包头部
   */
  uint8_t header;

  /**
   * 警告标志
   */
  uint16_t warnings;

  /**
   * 状态标志
   */
  uint16_t statusFlags;
};

EofPacket::EofPacket() : impl_(new Impl()) {}

EofPacket::~EofPacket() noexcept {}

EofPacket::EofPacket(uint16_t warnFlag, uint16_t statusFlag)
    : impl_(new Impl()) {
  impl_->header = EOF_PACKET;
  impl_->warnings = warnFlag;
  impl_->statusFlags = statusFlag;
}

std::vector<uint8_t> EofPacket::Pack() {
  std::vector<uint8_t> packetOutput;
  // EOF
  packetOutput.push_back(impl_->header);
  // warning
  packetOutput.push_back(static_cast<uint8_t>(impl_->warnings));
  packetOutput.push_back(static_cast<uint8_t>(impl_->warnings >> 8));
  // status
  packetOutput.push_back(static_cast<uint8_t>(impl_->statusFlags));
  packetOutput.push_back(static_cast<uint8_t>(impl_->statusFlags >> 8));
  return packetOutput;
}

bool EofPacket::UnPack(std::vector<uint8_t>& packet) {
  std::vector<uint8_t>::iterator seek = packet.begin();
  // header
  // impl_->header = *seek;
  // seek ++;
  impl_->header = Protocol::ReadU8(packet, seek);
  // warning
  impl_->warnings =
      static_cast<uint16_t>(*seek) | static_cast<uint16_t>(*(seek + 1) << 8);
  seek += 2;
  // status
  impl_->statusFlags =
      static_cast<uint16_t>(*seek) | static_cast<uint16_t>(*(seek + 1) << 8);
  return true;
}

/**
 * 包头部
 */
uint8_t EofPacket::GetHeader() { return impl_->header; }

/**
 * 警告标志
 */
uint16_t EofPacket::GetWarning() { return impl_->warnings; }

/**
 * 状态标志
 */
uint16_t EofPacket::GetStatusFlags() { return impl_->statusFlags; }

}  // namespace Protocol