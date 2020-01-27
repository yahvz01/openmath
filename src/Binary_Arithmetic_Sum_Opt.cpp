#include "openmath/Binary.hpp"


#include <cstdlib>
#include <stdexcept>
#include "openmath/Bitwise.hpp"


using namespace openmath;

/*
 *  "divide_ptr / remainder_ptr / divide_remainder_ptr" could be integrated,
 *  But these functions need to fast performance for calc
 *  so 
 */

int16_t openmath::adder_ptr(int8_t* const lhs, const int16_t& lhs_byte_length,int8_t* const rhs, const int16_t& rhs_byte_length, int8_t** result, bool do_fixed_byte_by_max_byte, bool return_byte_length)
{       
    int8_t* longer_data_ptr(lhs);
    int16_t longer_byte_length(lhs_byte_length);
    int8_t* smaller_data_ptr(rhs);
    int16_t smaller_byte_length(rhs_byte_length);
    
    if(longer_byte_length < smaller_byte_length)
    {
        using namespace std;
        swap(longer_data_ptr, smaller_data_ptr);
        swap(longer_byte_length, smaller_byte_length);
    }

    bool expected_carry(false);
    if(!do_fixed_byte_by_max_byte)
        expected_carry = carry_out_lookahead_ptr(longer_data_ptr, longer_byte_length, smaller_data_ptr, smaller_byte_length, true);

    int16_t allocate_byte_length(longer_byte_length + ( expected_carry ? 1 : 0));
    int8_t *temp_result_ptr = static_cast<int8_t*>( malloc(allocate_byte_length) );
    
    memset(temp_result_ptr, 0b0000'0000, allocate_byte_length);

    // Crime scene
    // Not optimized operation
    bool carry_in(false);
    int16_t idx(0);
    for(; idx < smaller_byte_length; ++idx)
    {
        carry_in = full_adder(longer_data_ptr[idx], smaller_data_ptr[idx], carry_in, temp_result_ptr[idx]);
    }
    
    // check smaller data is positive or not
    int8_t fill_bit( !(smaller_data_ptr[smaller_byte_length - 1] & SIGN_BIT_POS)? 0 : 0b1111'1111 );
    for(; idx < longer_byte_length; ++idx)
    {
        carry_in = full_adder(longer_data_ptr[idx], fill_bit, carry_in, temp_result_ptr[idx]);
    }
    
    if(expected_carry)
    {
        bool is_pos(is_positive(longer_data_ptr[longer_byte_length - 1]));
        if(is_pos)
        {
            temp_result_ptr[allocate_byte_length - 1] = 0b0000'0000;
        }
        else
        {
            temp_result_ptr[allocate_byte_length - 1] = 0b1111'1111;
        }
    }
    
    //optimization
    int16_t result_bit_length(get_digit_binary_number_ptr(temp_result_ptr, true, allocate_byte_length));
    int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
    
    if(!do_fixed_byte_by_max_byte)
    {
        *result = shrink_unlimitedint_memory_and_free(temp_result_ptr, allocate_byte_length, result_byte_length);
    }
    else
    {
        *result = temp_result_ptr;
    }
    
    if(return_byte_length)
    {
        return result_byte_length;
    }
    
    return result_bit_length;
}
