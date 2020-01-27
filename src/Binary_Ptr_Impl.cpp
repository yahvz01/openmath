#include "openmath/Binary.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>

using namespace openmath;

int16_t openmath::get_digit_binary_number_ptr(int8_t* const value_ptr, bool is_signed, const int16_t& byte_length)
{
    int16_t data_type_length = byte_length;
    bool is_negative( !is_positive_ptr(value_ptr, byte_length) );
    
    // Crime scene start

    int8_t* copyed_data_ptr(nullptr);
    if(is_negative)
    {
        copyed_data_ptr = make_binary_complement_ptr(value_ptr, byte_length);
    }
    else
        copyed_data_ptr = value_ptr;

    int byte_idx( data_type_length - 1 );
    int bit_idx;
    bool first_bit_idx_jump(is_signed);
    // Crime scene
    for(; byte_idx >= 0; --byte_idx)
    {
        for(bit_idx = (first_bit_idx_jump ? 7 : 8); bit_idx > 0; --bit_idx)
        {
            bool break_condition = (copyed_data_ptr[byte_idx] & bit_pos[bit_idx]);
            if(break_condition)
                goto loop_break;
        }
        first_bit_idx_jump = false;
    }
    ++byte_idx;
loop_break :
    if(is_negative)
    {
        free(copyed_data_ptr);
        copyed_data_ptr = nullptr;
    }
    return ((byte_idx * 8) + bit_idx);
}

int8_t* openmath::make_binary_complement_ptr(const int8_t *value_ptr, int16_t byte_length)
{
    int8_t *new_value(static_cast<int8_t *>(malloc(byte_length)));
    memset(new_value, 0, byte_length);
    
    for(int16_t idx(0); idx < byte_length; ++idx)
    {
        new_value[idx] = ~(value_ptr[idx]);
    }
    bool carry_out = true;
    for(int16_t idx(0); (idx < byte_length && carry_out == true); ++idx)
    {
        int8_t temp(0);
        carry_out = byte_half_adder(new_value[idx], 1, temp);
        new_value[idx] = temp;
    }
    return new_value;
}

bool openmath::is_positive_ptr(const int8_t *value, const int16_t& byte_length)
{
    return !(value[byte_length - 1] & SIGN_BIT_POS);
}

bool openmath::is_zero_ptr(int8_t *value_ptr, const int16_t& byte_length)
{
    for(int16_t idx(0); idx < byte_length; ++idx)
    {
        if(value_ptr[idx] != 0b0000'0000)
        {
            return false;
        }
    }
    return true;
}
bool openmath::is_one_ptr(int8_t *value_ptr, const int16_t& byte_length)
{
    int16_t idx(0);
    if(value_ptr[idx] != 0b0000'0001)
    {
        return false;
    }
    for(++idx; idx < byte_length; ++idx)
    {
        if(value_ptr[idx] != 0b0000'0000)
        {
            return false;
        }
    }
    return true;
}

// Crime scene
// consider sign bit // Only Sign

bool openmath::carry_out_lookahead_ptr(int8_t *lhs, const int16_t& lhs_byte_length, int8_t *rhs, const int16_t& rhs_byte_length, bool has_sign)
{
    if(lhs_byte_length != rhs_byte_length)
        return false;
    bool lhs_pos( is_positive_ptr(lhs, lhs_byte_length) );
    bool rhs_pos( is_positive_ptr(rhs, rhs_byte_length) );
    
    if(lhs_pos != rhs_pos)
        return false;
    
    std::pair<bool, bool> carry_out_and_propaganda(false, true);
    
    int16_t idx(lhs_byte_length - 1);

    int8_t *lhs_ptr(lhs);
    int8_t *rhs_ptr(rhs);

    if(!lhs_pos)
    {
        lhs_ptr = make_binary_complement_ptr(lhs, lhs_byte_length);
        rhs_ptr = make_binary_complement_ptr(rhs, rhs_byte_length);
    }
    if(has_sign)
    {
        carry_out_and_propaganda = byte_carry_out_lookahead_with_propaganda(lhs_ptr[idx], rhs_ptr[idx], true);
        --idx;
    }

    for(;
        idx >= 0 && (!carry_out_and_propaganda.first && carry_out_and_propaganda.second);
        --idx)
    {
        carry_out_and_propaganda = byte_carry_out_lookahead_with_propaganda(lhs_ptr[idx], rhs_ptr[idx], false);
    }
    if(!lhs_pos)
    {
        free(lhs_ptr);
        free(rhs_ptr);
    }
    
    return carry_out_and_propaganda.first;
}

int8_t* openmath::shrink_unlimitedint_memory(const int8_t *target_ptr, const int16_t& target_byte_length, const int16_t shrinked_byte_length)
{
    if(target_byte_length < shrinked_byte_length)
        throw std::invalid_argument("target_length should be larger than shrink_length");
    int8_t* new_value_ptr = static_cast<int8_t *>(malloc(shrinked_byte_length));
    memset(new_value_ptr, 0, shrinked_byte_length);
    int16_t target_byte_gap_length( target_byte_length - shrinked_byte_length );
    memcpy(new_value_ptr, target_ptr, shrinked_byte_length);
    return new_value_ptr;
}

int8_t* openmath::shrink_unlimitedint_memory_and_free(int8_t *target_ptr, const int16_t& target_byte_length, const int16_t shrinked_byte_length)
{
    if(target_byte_length < shrinked_byte_length)
        throw std::invalid_argument("target_length should be larger than shrink_length");
    int8_t* new_value_ptr = static_cast<int8_t *>(malloc(shrinked_byte_length));
    memset(new_value_ptr, 0, shrinked_byte_length);
    int16_t target_byte_gap_length( target_byte_length - shrinked_byte_length );
    memcpy(new_value_ptr, target_ptr, shrinked_byte_length);
    free(target_ptr);
    return new_value_ptr;
}


int8_t* openmath::stretch_data_length_for_sign_int(int8_t* value, int16_t prev_data_length, int16_t new_data_length)
{
    if(prev_data_length > new_data_length)
        throw std::invalid_argument("new_data_length is longer than prev_data_length");
    
    int8_t* result( static_cast<int8_t *>( malloc(new_data_length) ) );
    int8_t byte_fill( is_positive_ptr(value, prev_data_length)? 0b0000'0000 : 0b1111'1111 );
    int16_t gap_data_length( new_data_length - prev_data_length );

    memset(result, byte_fill, new_data_length);
    memcpy( result, value, prev_data_length );
    return result;
}