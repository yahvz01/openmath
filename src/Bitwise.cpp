#include "openmath/Bitwise.hpp"

#include <cstdint>
#include <cstdlib>
#include "openmath/Binary.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

int8_t openmath::bitwise_and_single_byte(const int8_t& lhs,const int8_t& rhs)
{   return (lhs & rhs);   }
int8_t openmath::bitwise_or_single_byte(const int8_t& lhs,const int8_t& rhs)
{   return (lhs | rhs);   }
int8_t openmath::bitwise_xor_single_byte(const int8_t& lhs,const int8_t& rhs)
{   return (lhs ^ rhs);   }

int16_t openmath::bitwise_not_opt_ptr(int8_t * const value_ptr, int16_t byte_length, int8_t **result)
{
    if(*result != NULL && *result != nullptr)
        free(*result);
    *result = static_cast<int8_t *>( malloc(byte_length) );
    for(int16_t idx(0); idx < byte_length; ++idx)
    {
        (*result)[idx] = ~(value_ptr[idx]);
    }
    // byte_length;
    return get_digit_binary_number_ptr(*result, true, byte_length);
}


int16_t openmath::bitwise_opt_ptr(int8_t* lhs, int16_t lhs_byte_length, int8_t* rhs, int16_t rhs_byte_length,const bit_opt& bit_opt, int8_t **result, bool do_shrink)
{   
    if(result != NULL && result != nullptr)
    {
        free(*result);
        *result = nullptr;
    }
    int16_t byte_length_longer = lhs_byte_length;
    int16_t byte_length_smaller = rhs_byte_length;
    int8_t* value_ptr_longer = lhs;
    int8_t* value_ptr_smaller = rhs;
    bool is_positive_smaller = is_positive_ptr(rhs, byte_length_smaller);
    
    if(lhs_byte_length < rhs_byte_length)
    {
        using namespace std;
        swap(byte_length_longer, byte_length_smaller);
        is_positive_smaller = is_positive_ptr(lhs, byte_length_smaller);
        swap(value_ptr_longer, value_ptr_smaller);
    }
    
    int8_t *new_value_ptr = static_cast<int8_t *>(malloc( byte_length_longer ));
    
    int idx(0);
    for(;idx < byte_length_smaller; ++idx)
    {
        new_value_ptr[idx] = bit_opt(value_ptr_longer[idx], value_ptr_smaller[idx]);
    }
    
    int8_t fill_smaller(is_positive_smaller ? 0 : 0b1111'1111);
    
    for(;idx < byte_length_longer; ++idx)
    {
        new_value_ptr[idx] = bit_opt(value_ptr_longer[idx], fill_smaller);
    }
    int16_t meaningfull_bit_length(get_digit_binary_number_ptr(new_value_ptr, true, byte_length_longer));

    if(do_shrink)
    {
        // Crime scene
        int16_t meaningfull_byte_length( bit_len_to_byte_len(meaningfull_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(new_value_ptr, byte_length_longer, meaningfull_byte_length);
    }
    else
    {
        *result = new_value_ptr;
    }
    return meaningfull_bit_length;
}



int16_t openmath::left_bit_shift_with_extend(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result, bool do_shrink)
{
    int16_t byte_jump(shift_jump / 8);
    int16_t bit_jump(shift_jump % 8);

    int16_t allocated_byte_length(byte_length + byte_jump + (bit_jump != 0? 1 : 0));
    int8_t* temp_result_ptr( static_cast<int8_t *>( malloc(allocated_byte_length) ) );
    bool is_positive(is_positive_ptr(value_ptr, byte_length));
    memset(temp_result_ptr, 0, allocated_byte_length);

    int8_t carry_bit(0);
    int8_t shift_bit(0);

    for(int16_t idx(0); idx < allocated_byte_length; ++idx)
    {
        int16_t result_idx = byte_jump + idx;
        temp_result_ptr[result_idx] = carry_bit;
        
        carry_bit = (static_cast<uint8_t>(value_ptr[idx]) >> ( 8 - bit_jump ));
        shift_bit = (value_ptr[idx] << bit_jump);
        temp_result_ptr[result_idx] = ( shift_bit | temp_result_ptr[result_idx]);
    }
    if(byte_jump != 0 && !(is_positive))
    {
        int8_t fill_bit( 0b1111'1111 << bit_jump );
        temp_result_ptr[allocated_byte_length - 1] = (temp_result_ptr[allocated_byte_length - 1] | fill_bit);
    }
    
    int16_t result_bit_length(get_digit_binary_number_ptr(temp_result_ptr, true, allocated_byte_length));

    if(do_shrink)
    {
        int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(temp_result_ptr, allocated_byte_length, result_byte_length);
        free(temp_result_ptr);
    }
    else
    {
        *result = temp_result_ptr;
    }
    return result_bit_length; 
}

// static_cast has cost of runtime
/*
    // prev_value value_ptr not free
    @parameter : only consider signed value && do_shrink for optimization
    @return bit_length (new_value)
 */

int16_t openmath::left_bit_shift(int8_t *value_ptr, int16_t value_byte_length, int16_t shift_jump, int8_t **result, bool do_shrink)
{
    int16_t byte_jump(shift_jump / 8);
    int16_t bit_jump(shift_jump % 8);

    if(byte_jump > value_byte_length)
    {
        *result = nullptr;
        return 0;
    }

    int8_t* temp_result_ptr( static_cast<int8_t *>( malloc(value_byte_length) ) );
    memset(temp_result_ptr, 0, value_byte_length);

    int8_t carry_bit(0);
    int8_t shift_bit(0);

    int16_t valid_byte_length( value_byte_length - byte_jump );
    for(int16_t idx(0); idx < valid_byte_length; ++idx)
    {
        int16_t result_idx(byte_jump + idx);
        temp_result_ptr[result_idx] = carry_bit;
        
        carry_bit = (static_cast<uint8_t>(value_ptr[idx]) >> ( 8 - bit_jump));
        shift_bit = (value_ptr[idx] << bit_jump);
        temp_result_ptr[result_idx] = ( shift_bit | temp_result_ptr[result_idx]);
    }
    int16_t result_bit_length(get_digit_binary_number_ptr(temp_result_ptr, true, value_byte_length));
    
    if(do_shrink)
    {
        int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(temp_result_ptr, value_byte_length, result_byte_length);
    }
    else
    {
        *result = temp_result_ptr;
    }
    
    return result_bit_length;
}

int16_t openmath::right_bit_shift(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result, bool do_shrink)
{
    int16_t byte_down_jump(shift_jump / 8);
    int16_t bit_down_jump(shift_jump % 8);
    bool is_positive_value( is_positive_ptr(value_ptr, byte_length) );

    if(byte_down_jump >= byte_length)
    {
        *result = nullptr;
        return 0;
    }

    int16_t valid_byte_length( byte_length - byte_down_jump );
    
    int8_t *temp_result_ptr( static_cast<int8_t *>(malloc(valid_byte_length)) );
    
    //memset(temp_result_ptr, fill_byte, valid_byte_length);
    memset(temp_result_ptr, 0, valid_byte_length);

    int8_t carry_down_bit(0);
    int8_t shift_down_bit(0);


    for(int32_t idx(valid_byte_length - 1); idx >= 0; --idx)
    {
        int16_t curr_idx(byte_down_jump + idx);
        temp_result_ptr[idx] = carry_down_bit;
        
        carry_down_bit = ( value_ptr[curr_idx] << (8 - bit_down_jump) );
        shift_down_bit = ( static_cast<uint8_t>(value_ptr[curr_idx]) >> bit_down_jump);

        temp_result_ptr[idx] = (shift_down_bit | temp_result_ptr[idx]);
    }
    if(!is_positive_value)
    {
        int8_t fill_byte( 0b1111'1111 );
        memset(&temp_result_ptr[valid_byte_length], fill_byte, byte_down_jump);

        int16_t head_byte_idx(valid_byte_length - 1);
        int8_t head_byte( temp_result_ptr[head_byte_idx] | (0b1111'1111 << (8 - bit_down_jump)) );
        temp_result_ptr[head_byte_idx] = head_byte;
    }
    int16_t result_bit_length(get_digit_binary_number_ptr(temp_result_ptr, true, valid_byte_length));
    if(do_shrink)
    {
        int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(temp_result_ptr, valid_byte_length, result_byte_length);
        free(temp_result_ptr);
    }
    else
    {
        *result = temp_result_ptr;
    }
    return result_bit_length;
}

int16_t openmath::left_bit_single_shift(int8_t *value_ptr, int16_t byte_length, int8_t **result, bool do_shrink)
{
    int8_t* temp_result_ptr( static_cast<int8_t *>( malloc(byte_length) ) );
    memset(temp_result_ptr, 0, byte_length);

    int8_t carry_bit(0);
    int8_t shift_bit(0);

    for(int16_t idx(0); idx < byte_length; ++idx)
    {
        int16_t result_idx = idx;
        temp_result_ptr[result_idx] = carry_bit;
        
        carry_bit = (static_cast<uint8_t>(value_ptr[idx]) >> 7);
        shift_bit = (value_ptr[idx] << 1);
        temp_result_ptr[result_idx] = ( shift_bit | temp_result_ptr[result_idx]);
    }
    
    int16_t result_bit_length(get_digit_binary_number_ptr(temp_result_ptr, true, byte_length));

    if(do_shrink)
    {
        int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(temp_result_ptr, byte_length, result_byte_length);
        free(temp_result_ptr);
    }
    else
    {
        *result = temp_result_ptr;
    }
    return result_bit_length;
}

int16_t openmath::right_bit_single_shift(int8_t *value_ptr, int16_t byte_length, int8_t **result, bool do_shrink)
{
    bool is_positive_value( is_positive_ptr(value_ptr, byte_length) );
    int8_t *temp_result_ptr( static_cast<int8_t *>(malloc(byte_length)) );
    memset(temp_result_ptr, 0, byte_length);

    int8_t carry_down_bit(0);
    int8_t shift_down_bit(0);


    for(int32_t idx(byte_length - 1); idx >= 0; --idx)
    {
        int16_t curr_idx(idx);
        temp_result_ptr[idx] = carry_down_bit;
        
        carry_down_bit = ( value_ptr[curr_idx] << 7 );
        shift_down_bit = ( static_cast<uint8_t>(value_ptr[curr_idx]) >> 1);

        temp_result_ptr[idx] = (shift_down_bit | temp_result_ptr[idx]);
    }

    if(!is_positive_value)
    {
        int16_t head_byte_idx(byte_length - 1);
        int8_t head_byte( temp_result_ptr[head_byte_idx] | 0b1000'0000 );
        temp_result_ptr[head_byte_idx] = head_byte;
    }
    int16_t result_bit_length(get_digit_binary_number_ptr(temp_result_ptr, true, byte_length));
    if(do_shrink)
    {
        int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(temp_result_ptr, byte_length, result_byte_length);
        free(temp_result_ptr);
    }
    else
    {
        *result = temp_result_ptr;
    }
    return result_bit_length;
}


int16_t openmath::left_bit_shift_with_extend_return_allocated_byte_length(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result)
{
    int16_t byte_jump(shift_jump / 8);
    int16_t bit_jump(shift_jump % 8);

    int16_t allocated_byte_length(byte_length + byte_jump + (bit_jump != 0? 1 : 0));
    int8_t* temp_result_ptr( static_cast<int8_t *>( malloc(allocated_byte_length) ) );
    bool is_positive(is_positive_ptr(value_ptr, byte_length));
    memset(temp_result_ptr, 0, allocated_byte_length);

    int8_t carry_bit(0);
    int8_t shift_bit(0);

    for(int16_t idx(0); idx < allocated_byte_length; ++idx)
    {
        int16_t result_idx = byte_jump + idx;
        temp_result_ptr[result_idx] = carry_bit;
        
        carry_bit = (static_cast<uint8_t>(value_ptr[idx]) >> ( 8 - bit_jump ));
        shift_bit = (value_ptr[idx] << bit_jump);
        temp_result_ptr[result_idx] = ( shift_bit | temp_result_ptr[result_idx]);
    }

    if(byte_jump != 0 && !(is_positive))
    {
        int8_t fill_bit( 0b1111'1111 << bit_jump );
        temp_result_ptr[allocated_byte_length - 1] = (temp_result_ptr[allocated_byte_length - 1] | fill_bit);
    }
    
    *result = temp_result_ptr;
    return allocated_byte_length; 
}