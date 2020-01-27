#include "openmath/Binary.hpp"

#include <cstdlib>
#include <stdexcept>
#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"

using namespace openmath;

namespace {
    int16_t multiply_by_1000_ptr_return_byte(int8_t *value, const int16_t& value_byte_length, int8_t** result)
    {
        int16_t value_1000(0b0000'0011'1110'1000);
        int16_t result_byte_length(multiply_ptr(value, value_byte_length, reinterpret_cast<int8_t*>(&value_1000), 2, result, true));
        return result_byte_length;
    }

    int16_t multiply_by_10_ptr_return_byte(int8_t *value, const int16_t& value_byte_length, int8_t** result)
    {
        int8_t value_10(0b0000'1010);
        int16_t result_byte_length(multiply_ptr(value, value_byte_length, &value_10, 1, result, true));
        return result_byte_length;
    }
    
    int16_t divide_by_10_ptr(int8_t *value_ptr, const int16_t& value_byte_length, int8_t** result_qutient)
    {
        int8_t divisor_ptr(0b0000'1010);
        int16_t divisor_byte_length(1);
        int16_t result_bit_length(divide_ptr(value_ptr, value_byte_length, &divisor_ptr, divisor_byte_length, result_qutient));
        return result_bit_length;
    }
    
    int16_t get_nearest_overflowed_multiply_of_10(int16_t byte_length, int8_t **result)
    {
        int16_t bit_length(byte_length * 8);
        int16_t approx_digits(bit_length / 3);

        int8_t one(1);
        
        int8_t *temp_result(&one);
        int16_t temp_result_byte_length(1);
        
        for(int16_t idx(0); idx < approx_digits; ++idx)
        {
            int8_t *temp_in_loop(nullptr);
            temp_result_byte_length = 
                            multiply_by_10_ptr_return_byte(temp_result, temp_result_byte_length, &temp_in_loop);
            if(idx != 0)
                free(temp_result);
            temp_result = temp_in_loop;
        }
        int16_t result_bit_length(get_digit_binary_number_ptr(temp_result, true, temp_result_byte_length));
        int16_t result_byte_length( bit_len_to_byte_len(result_bit_length) );
        *result = shrink_unlimitedint_memory_and_free(temp_result, temp_result_byte_length, result_byte_length);
        return result_byte_length;
    }
}


char* openmath::integar_to_c_string_ptr(int8_t* value_ptr, const int16_t& value_byte_length)
{
    bool is_positive( is_positive_ptr(value_ptr, value_byte_length) );
    
    int8_t* valid_value_ptr( (is_positive ? value_ptr : make_binary_complement_ptr(value_ptr, value_byte_length) ) );
    int16_t valid_value_byte_length(value_byte_length);
    
    int8_t* divisor_decimal_ptr(nullptr);
    int16_t divisor_decimal_byte_length(
        get_nearest_overflowed_multiply_of_10(valid_value_byte_length, &divisor_decimal_ptr)
    );
    // sign bit should be proceed post-process
    int8_t* temp_result(static_cast<int8_t*>( malloc(divisor_decimal_byte_length) ) );
    memset(temp_result, 0, divisor_decimal_byte_length);
    
    int8_t* input_ptr(temp_result);
    int16_t idx_meaingfull_decmial(0);
    bool first(true);
    bool break_cond(false);
    while(true)
    {
        break_cond = is_one_ptr(divisor_decimal_ptr, divisor_decimal_byte_length);
        if(valid_value_byte_length >= divisor_decimal_byte_length)
        {
            int8_t* qutient(nullptr);
            int8_t* remainder(nullptr);
            std::pair<int16_t, int16_t> bit_lengths(
                divide_remainder_ptr(valid_value_ptr, valid_value_byte_length, divisor_decimal_ptr, divisor_decimal_byte_length, &qutient, &remainder));
            
            if(idx_meaingfull_decmial == 0 && (*qutient == 0))
            { }
            else
            {
                *input_ptr = ((*qutient) + 48);
                ++input_ptr;
                ++idx_meaingfull_decmial;
            }
            free(qutient);
            
            if( !(first && is_positive_ptr) )
            {
                free(valid_value_ptr);
            }
            
            first = false;
            valid_value_ptr = remainder;
            valid_value_byte_length = bit_len_to_byte_len(bit_lengths.second);
        }
        // loop-end process
        int8_t* temp_swap(nullptr);
        int16_t temp_swap_bit_length(divide_by_10_ptr(divisor_decimal_ptr, divisor_decimal_byte_length, &temp_swap));
        free(divisor_decimal_ptr);
        divisor_decimal_ptr = temp_swap;
        divisor_decimal_byte_length = bit_len_to_byte_len(temp_swap_bit_length);

        if(break_cond)
            break;
    }
    if( !(first && is_positive_ptr) )
    {
        free(valid_value_ptr);
    }
    free(divisor_decimal_ptr);
    
    // shrink_data and input bit_sign
    int16_t allocate_mem_size(idx_meaingfull_decmial + (is_positive ? 0 : 1));
    char* result_ptr( static_cast<char*>(malloc(allocate_mem_size)) );
    
    if(is_positive)
    {
        memcpy( result_ptr, temp_result, idx_meaingfull_decmial);   
    }
    else
    {
        result_ptr[0] = '-';
        memcpy( (result_ptr + 1), temp_result, idx_meaingfull_decmial);
    }
    free(temp_result);
    
    return result_ptr;
}


int16_t openmath::string_to_integar_ptr( const char *value_ptr, const int16_t& value_byte_length, int8_t** result)
{
    bool is_positive(true);
    if(value_ptr[0] == '-')
    {
        is_positive = false;
    }
    const char* only_decmial_ptr( is_positive ? value_ptr : (value_ptr + 1));
    
    int16_t meaningfull_decimal_digits( value_byte_length - (is_positive? 0 : 1));
    if(meaningfull_decimal_digits == 0)
        throw std::invalid_argument("input value should include decimal number");
    int16_t less_than_divide_three( meaningfull_decimal_digits % 3 );
    int16_t byte_dividen_three( meaningfull_decimal_digits / 3);
    int16_t allocated_array_length( byte_dividen_three + (less_than_divide_three? 1 : 0) );
    int16_t* arr_digit_of_three = static_cast<int16_t*>(malloc( allocated_array_length ));

    bool valid_decimal(true);

    if(less_than_divide_three)
    {
        int16_t result(0);
        int8_t multiplier(10);
        for(int16_t idx(0); idx < less_than_divide_three; ++idx)
        {
            int8_t temp_value(only_decmial_ptr[idx] );
            if( temp_value < 48 || temp_value > 57 )
                valid_decimal = false;
            result += ((temp_value - 48) * multiplier);
            multiplier /= 10;
        }
        if(!valid_decimal)
            throw std::invalid_argument("input value is not decimal");
        arr_digit_of_three[byte_dividen_three] = result;
    }

    for(int16_t idx(0); idx < byte_dividen_three; ++idx )
    {
        int16_t result(0);
        int16_t target_idx(idx * 3 + less_than_divide_three);
        int8_t temp_value00(only_decmial_ptr[target_idx + 0] );
        if( temp_value00 < 48 || temp_value00 > 57 )
            valid_decimal = false;
        result += (temp_value00 - 48) * 100;

        int8_t temp_value01(only_decmial_ptr[target_idx + 1] );
        if( temp_value01 < 48 || temp_value01 > 57 )
            valid_decimal = false;
        result += (temp_value01 - 48) * 10;

        int8_t temp_value02(only_decmial_ptr[target_idx + 2] );
        if( temp_value02 < 48 || temp_value02 > 57 )
            valid_decimal = false;
        result += (temp_value02 - 48);

        if(!valid_decimal)
            throw std::invalid_argument("input value is not decimal");
        
        arr_digit_of_three[byte_dividen_three - idx - 1] = result;
    }
    
    int8_t zero(0);
    int8_t* accumulated_result( &zero );
    int16_t accumulated_result_byte_length(1);

    for(int idx(0); idx < allocated_array_length; ++idx)
    {
        int8_t* temp_result( reinterpret_cast<int8_t*>(&arr_digit_of_three[idx]));
        int16_t temp_result_byte_length(2); // sizeof(int16_t) == 2
        
        for(int16_t inner_idx(0); inner_idx < idx; ++inner_idx)
        {
            int8_t *temp_swap(nullptr);
            temp_result_byte_length = multiply_by_1000_ptr_return_byte(temp_result, temp_result_byte_length, &temp_swap);
            
            if(inner_idx != 0)
                free(temp_result);
            temp_result = temp_swap;
        }
        int8_t *temp_swap(nullptr);
        accumulated_result_byte_length
            = adder_ptr(accumulated_result, accumulated_result_byte_length, temp_result, temp_result_byte_length, &temp_swap, false, true);
        
        if(idx != 0)
            free(accumulated_result);
        accumulated_result = temp_swap;
    }

    int16_t digits = get_digit_binary_number_ptr(accumulated_result, false, allocated_array_length);
    int16_t result_byte_length(bit_len_to_byte_len(digits));
    int8_t* temp_result = shrink_unlimitedint_memory_and_free(accumulated_result, accumulated_result_byte_length, result_byte_length);

    if(!is_positive)
    {
        int8_t* temp_swap(make_binary_complement_ptr(temp_result, result_byte_length));
        free(temp_result);
        temp_result = temp_swap;
    }
    *result = temp_result;
    return digits;
}