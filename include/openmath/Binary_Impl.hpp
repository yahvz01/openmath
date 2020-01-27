#pragma once

#include "Binary.hpp"
#include <type_traits>

#include <cstdlib>
#include <cstring>
#include <cstdint>

template <typename Tp>
Tp openmath::make_binary_complement(const Tp& value)
{
    static_assert(std::is_integral<Tp>::value);
    return ((~value) + 1);
}

template <typename Tp>
bool openmath::carry_out_lookahead(const Tp& lhs, const Tp& rhs)
{
    static_assert(std::is_integral<Tp>::value);
    auto data_length = sizeof(Tp);

    auto *lhs_ptr = reinterpret_cast<const int8_t *>(&lhs);
    auto *rhs_ptr = reinterpret_cast<const int8_t *>(&rhs);
    
    // carry_out_and_prop => first generated / second propagation
    std::pair<bool, bool> carry_out_and_propaganda(false, true);
    for(int idx(data_length - 1);
        idx >= 0 && (!carry_out_and_propaganda.first && carry_out_and_propaganda.second);
        --idx)
    {
        carry_out_and_propaganda = byte_carry_out_lookahead_with_propaganda(lhs_ptr[idx], rhs_ptr[idx], false);
    }
    return carry_out_and_propaganda.first;
}


template <typename Tp>
bool openmath::half_adder(const Tp& lhs, const Tp& rhs, Tp& result)
{
    static_assert(std::is_integral<Tp>::value);
    auto data_length_in_bytes = sizeof(Tp);
    
    auto *lhs_ptr = reinterpret_cast<const int8_t *>(&lhs);
    auto *rhs_ptr = reinterpret_cast<const int8_t *>(&rhs);
    auto *result_ptr = reinterpret_cast<int8_t *>(&result);
    
    bool carry_in(false);
    for(int idx(0); idx < data_length_in_bytes; ++idx)
    {
        if(carry_in)
        {
            int8_t temp_result;
            carry_in = byte_half_adder(lhs_ptr[idx], 0b0000'0001, temp_result);
            carry_in = carry_in || byte_half_adder(temp_result, rhs_ptr[idx], result_ptr[idx]);
        }
        else
            carry_in = byte_half_adder(lhs_ptr[idx], rhs_ptr[idx], result_ptr[idx]);
    }
    return carry_in;
}

template <typename Tp>
bool openmath::full_adder(const Tp& lhs, const Tp& rhs, bool carry_in, Tp& result)
{
    static_assert(std::is_integral<Tp>::value);
    Tp temp_result;
    bool carry_out = half_adder(lhs, rhs, temp_result);
    if(carry_in)
    {
        Tp complement_add(1);
        bool result_bool = half_adder(temp_result, complement_add, result);
        carry_out = carry_out || result_bool;
    }
    else
        result = temp_result;
    return carry_out;
}

template <typename Tp>
int16_t openmath::get_digit_binary_number(const Tp& value)
{
    static_assert(std::is_integral<Tp>::value);
    int16_t data_type_length = sizeof(Tp);
    bool is_signed(std::is_signed<Tp>::value);
    const int8_t *value_ptr(reinterpret_cast<const int8_t *>(&value));
    bool is_negative( is_signed ? (value_ptr[ data_type_length - 1] & bit_pos[8]) : false );
    
    Tp copyed_data(value);
    if(is_negative)
    {
        copyed_data = make_binary_complement(value);
        value_ptr = reinterpret_cast<const int8_t *>(&copyed_data);
    }
    
    int byte_idx( data_type_length - 1 );
    int bit_idx;
    bool first_bit_idx_jump(is_signed);
    for(; byte_idx >= 0; --byte_idx)
    {
        for(bit_idx = (first_bit_idx_jump ? 7 : 8); bit_idx > 0; --bit_idx)
        {
            bool break_condition = (value_ptr[byte_idx] & bit_pos[bit_idx]);
            if(break_condition)
                goto loop_break;
        }
        first_bit_idx_jump = false;
    }
    ++byte_idx;
loop_break :
    return ((byte_idx * 8) + bit_idx);
}



template <typename Tp>
bool openmath::is_positive(const Tp& value)
{
    static_assert(std::is_integral<Tp>::value);
    if(std::is_unsigned<Tp>::value)
        return true;
    int16_t byte_length = sizeof(Tp);
    auto value_ptr = reinterpret_cast<const int8_t *>(&value);
    return !(value_ptr[byte_length - 1] & SIGN_BIT_POS);
}
