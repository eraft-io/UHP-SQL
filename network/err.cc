/**
 * @file Err.cpp
 *
 * Err 包实现
 */

#include "err.h"

#include "common.h"
#include "protocol_buffer.h"

namespace Protocol {

struct ErrPacket::Impl {
  uint8_t header;

  uint16_t errorCode;

  std::string sqlState;

  std::string errorMessage;
};

ErrPacket::ErrPacket() : impl_(new Impl()) {}

ErrPacket::~ErrPacket() noexcept {}

// e.g 0, 10, 0, 2, 0, 0, 0
std::vector<uint8_t> ErrPacket::Pack(uint16_t errorCode, std::string sqlState,
                                     std::string errorMessage) {
  impl_->header = ERR_PACKET;
  impl_->errorCode = errorCode;
  impl_->sqlState = sqlState;
  impl_->errorMessage = errorMessage;
  std::vector<uint8_t> packetOutput;
  WriteU8(packetOutput, ERR_PACKET);
  WriteU16(packetOutput, impl_->errorCode);
  WriteU8(packetOutput, '#');
  if (impl_->sqlState == "") {
    impl_->sqlState == "HY000";
  }
  WriteString(packetOutput, impl_->sqlState);
  WriteString(packetOutput, impl_->errorMessage);
  return packetOutput;
}

}  // namespace Protocol
