/**
 *  @file Greeting.hpp
 *
 *  Mysql 认证协议包 C -> S
 *
 *  Copyright © 2020 by LiuJ
 */

#pragma once

#include <unistd.h>

#include <iostream>
#include <memory>
#include <vector>

namespace Protocol {

class AuthPacket {
 public:
  ~AuthPacket() noexcept;
  AuthPacket(const AuthPacket&) = delete;
  AuthPacket(AuthPacket&&) noexcept = delete;
  AuthPacket& operator=(const AuthPacket&) = delete;
  AuthPacket& operator=(AuthPacket&&) noexcept = delete;
  AuthPacket();
  /**
   * 编码 auth 包
   * TODO 暂时没有编码的需求
   */
  std::vector<uint8_t> Pack(uint32_t capabilityFlags, uint8_t charset,
                            std::string username, std::string password,
                            std::vector<uint8_t> salt, std::string database);
  /**
   * 解码 auth 包
   */
  bool UnPack(std::vector<uint8_t>& packet);

  std::string GetPluginName();

  std::string GetDatabaseName();

  std::string GetUserName();

 private:
  struct Impl;

  std::unique_ptr<Impl> impl_;
};

}  // namespace Protocol