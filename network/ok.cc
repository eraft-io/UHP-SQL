/**
 * @file Ok.cpp
 *
 * Ok 包实现
 */

#include "ok.h"

#include "common.h"
#include "protocol_buffer.h"

namespace Protocol {

struct OkPacket::Impl {
  uint8_t header;

  uint64_t affectedRows;

  uint64_t lastInsertID;

  uint16_t statusFlags;

  uint16_t warnings;
};

OkPacket::OkPacket() : impl_(new Impl()) {}

OkPacket::~OkPacket() noexcept {}

// e.g 0, 10, 0, 2, 0, 0, 0
std::vector<uint8_t> OkPacket::Pack(uint64_t affectedRows,
                                    uint64_t lastInsertID, uint16_t statusFlags,
                                    uint16_t warnings) {
  impl_->header = OK_PACKET;
  impl_->affectedRows = affectedRows;
  impl_->lastInsertID = lastInsertID;
  impl_->statusFlags = statusFlags;
  impl_->warnings = warnings;
  std::vector<uint8_t> packetOutput;
  WriteU8(packetOutput, OK_PACKET);
  WriteLenEncode(packetOutput, impl_->affectedRows);
  WriteLenEncode(packetOutput, impl_->lastInsertID);
  WriteU16(packetOutput, impl_->statusFlags);
  WriteU16(packetOutput, impl_->warnings);
  return packetOutput;
}

}  // namespace Protocol
