#pragma once

#include <cstring>
#include <cstdlib>
#include <type_traits>

#include "openmath/Binary.hpp"

namespace openmath_helper {
    template <typename Tp>
    int16_t data_copy_get_length_in_fixed_bit(const Tp& value, uint16_t fixed_byte, int8_t **result);
}

template <typename Tp>
int16_t openmath_helper::data_copy_get_length_in_fixed_bit(const Tp& value, uint16_t fixed_byte, int8_t **result)
{
    using namespace openmath;
    
    static_assert(std::is_integral<Tp>::value);
    
    *result = static_cast<int8_t *>( malloc(fixed_byte) );
    
    int8_t fill_bit( (is_positive(value)? 0b0000'0000 : 0b1111'1111) );
    memset(*result, fill_bit, fixed_byte);
    int16_t input_value_byte_length(sizeof(value));
    int16_t copyed_data_length( ((input_value_byte_length < fixed_byte) ? input_value_byte_length : fixed_byte) );
    memcpy(*result, &value, copyed_data_length);
    return get_digit_binary_number_ptr(*result, true, copyed_data_length);
}