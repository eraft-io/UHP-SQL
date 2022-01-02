/**
 *  @file Err.hpp
 *  
 *  Mysql Err 包
 * 
 *  Copyright © 2020 by LiuJ
 */

#pragma once

#include <unistd.h>
#include <vector>
#include <iostream>
#include <memory>

namespace Protocol {

    class ErrPacket {
    
    public:
        ~ErrPacket() noexcept;
        ErrPacket(const ErrPacket&) = delete;
        ErrPacket(ErrPacket&&) noexcept = delete;
        ErrPacket& operator=(const ErrPacket&) = delete;
        ErrPacket& operator=(ErrPacket&&) noexcept = delete;
        ErrPacket();

        std::vector< uint8_t > Pack(uint16_t errorCode, std::string sqlState, std::string errorMessage);

    private:

        struct Impl;

        std::unique_ptr< Impl > impl_;

    };

} // namespace Protocol
