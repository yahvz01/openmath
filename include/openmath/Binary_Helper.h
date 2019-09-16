#pragma once

#include <stdint.h>

namespace binary_helper {
    constexpr uint8_t bit_with_sign = 0b0111'1111;
    
    constexpr inline uint8_t extract_without_bit_sign( const uint8_t& value)
    {
        return value & bit_with_sign;
    };
}
