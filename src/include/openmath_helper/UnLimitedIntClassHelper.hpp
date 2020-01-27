#pragma once

#include <cstdint>
#include <cstdlib>
#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"
#include "openmath/UnLimitedInt.hpp"

using namespace openmath;

namespace openmath_helper {
    template <typename Tp>
    int16_t get_bit_length_and_set_value(const Tp& value, int8_t** result_ptr);    

    UnLimitedInt bitwise_opt_unlimitedint(const UnLimitedInt& lhs, const UnLimitedInt& rhs, bit_opt func);
}

template <typename Tp>
int16_t openmath_helper::get_bit_length_and_set_value(const Tp& value, int8_t** result_ptr)
{
    static_assert(std::is_integral<Tp>::value);
    int16_t binary_digits = get_digit_binary_number(value);
    
    int16_t byte_divisor(binary_digits / 8);
    bool less_then_one_byte(binary_digits % 8);
    
    int16_t byte_length( bit_len_to_byte_len(binary_digits) );
    
    *result_ptr = static_cast<int8_t *>( malloc(byte_length) );

    if(std::is_unsigned<Tp>::value)
    {   
        memset(*result_ptr, 0, byte_length);
        memcpy(*result_ptr, &value, byte_length);
    }
    else
    {
        int8_t fill_byte(0b0000'0000);
        if( !(is_positive(value)) )
            fill_byte = 0b1111'1111; // -1
        // MSByte 만 수행해도 된다. 
        memset(*result_ptr, fill_byte, byte_length);
        memcpy(*result_ptr, &value, byte_length);
    }
    return binary_digits;
}