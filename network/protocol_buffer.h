/**
 *  @file Greeting.hpp
 *
 *  Mysql 认证协议 Buffer 操作抽象
 *
 *  Copyright © 2020 by LiuJ
 */

#pragma once

#include <unistd.h>

#include <iostream>
#include <memory>
#include <vector>

namespace Protocol {

uint8_t ReadU8(std::vector<uint8_t>& packet,
               std::vector<uint8_t>::iterator& it);
uint16_t ReadU16(std::vector<uint8_t>& packet,
                 std::vector<uint8_t>::iterator& it);
uint16_t ReadU24(std::vector<uint8_t>& packet,
                 std::vector<uint8_t>::iterator& it);
uint32_t ReadU32(std::vector<uint8_t>& packet,
                 std::vector<uint8_t>::iterator& it);
uint64_t ReadU64(std::vector<uint8_t>& packet,
                 std::vector<uint8_t>::iterator& it);
uint64_t ReadLenEncode(std::vector<uint8_t>& packet,
                       std::vector<uint8_t>::iterator& it);
std::string ReadString(std::vector<uint8_t>& packet,
                       std::vector<uint8_t>::iterator& it, size_t readBytes);
std::string ReadLenEncodeString(std::vector<uint8_t>& packet,
                                std::vector<uint8_t>::iterator& it);

void WriteU8(std::vector<uint8_t>& packet, uint8_t v);
void WriteU16(std::vector<uint8_t>& packet, uint16_t v);
void WriteU24(std::vector<uint8_t>& packet, uint32_t v);
void WriteU32(std::vector<uint8_t>& packet, uint32_t v);
void WriteU64(std::vector<uint8_t>& packet, uint64_t v);
void WriteLenEncode(std::vector<uint8_t>& packet, uint64_t v);
void WriteLenEncodeNUL(std::vector<uint8_t>& packet);
void WriteString(std::vector<uint8_t>& packet, std::string v);
void WriteLenEncodeString(std::vector<uint8_t>& packet, std::string v);

}  // namespace Protocol
