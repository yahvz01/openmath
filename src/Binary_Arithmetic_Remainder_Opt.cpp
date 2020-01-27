#include "openmath/Binary.hpp"

#include <stdexcept>
#include <cstdlib>
#include "openmath/Bitwise.hpp"

int16_t openmath::remainder_ptr(int8_t* const dividend, const int16_t& dividend_byte_length, int8_t* const divisor, const int16_t& divisor_byte_length, int8_t** result)
{
    int16_t longer_byte_length(dividend_byte_length);
    if(dividend_byte_length < divisor_byte_length)
    {
        throw std::invalid_argument("dividend_byte_length is bigger than divisor_byte_length");
    }
    if(is_zero_ptr(divisor, divisor_byte_length) || divisor_byte_length == 0)
    {
        throw std::invalid_argument("divisor should not be zero.");
    }
    //is_need_to_change_complementary
    bool is_positive_of_dividend( is_positive_ptr(dividend, dividend_byte_length) );
    bool is_positive_of_divisor( is_positive_ptr(divisor, divisor_byte_length) );
    
    int16_t temp_result_length( dividend_byte_length * 2 );
    int8_t *temp_result( static_cast<int8_t *>( malloc( temp_result_length )) );
    memset(temp_result, 0, temp_result_length);

    if(is_positive_of_dividend)
    {
        memcpy(temp_result, dividend, dividend_byte_length);
    }
    else
    {
        int8_t* const dividend_complmentary(make_binary_complement_ptr(dividend, dividend_byte_length));
        memcpy(temp_result, dividend_complmentary, dividend_byte_length);
        free(dividend_complmentary);
    }
    int8_t *add_element_for_process( stretch_data_length_for_sign_int(divisor, divisor_byte_length, dividend_byte_length) );
    if(is_positive_of_divisor)
    {
        int8_t* temp(make_binary_complement_ptr(add_element_for_process, dividend_byte_length));
        free(add_element_for_process);
        add_element_for_process = temp;
    }

    int16_t process_count( dividend_byte_length * 8 );
    for(int16_t idx(0); idx < process_count; ++idx)
    {
        int8_t *temp(nullptr);
        left_bit_single_shift(temp_result, temp_result_length, &temp, false);
        free(temp_result);
        temp_result = temp;
        
        
        int8_t* remainder_ptr(temp_result + dividend_byte_length);
        bool is_positive_remainer( is_positive_ptr(remainder_ptr, dividend_byte_length) );
        
        int8_t* processed_remainer(nullptr);
        adder_ptr(remainder_ptr, dividend_byte_length, add_element_for_process, dividend_byte_length, &processed_remainer, true, false);
        bool is_positive_processed_remainer( is_positive_ptr(processed_remainer, dividend_byte_length) );
        
        if(is_positive_remainer == is_positive_processed_remainer)
        {
            memcpy((temp_result + dividend_byte_length), processed_remainer, dividend_byte_length);
            int8_t add_one( temp_result[0] | bit_pos[1] );
            memcpy(temp_result, &add_one, 1);
        }
        free(processed_remainer);
    }
    free(add_element_for_process);


    // remainder return process
    //int8_t* remainder_ptr(temp_result + dividend_byte_length);
    int8_t* remainder_ptr(temp_result + dividend_byte_length);
    int16_t remainder_bit_length( get_digit_binary_number_ptr(remainder_ptr, true, dividend_byte_length) );
    if(!is_positive_of_dividend)
    {
        int8_t* temp(make_binary_complement_ptr(remainder_ptr, dividend_byte_length));
        std::swap(remainder_ptr, temp);
    }
    else
    {
        int8_t* temp(static_cast<int8_t*>(malloc(dividend_byte_length)));
        memcpy(temp, remainder_ptr, dividend_byte_length);
        std::swap(remainder_ptr, temp);
    }
    
    *result = remainder_ptr;
    free(temp_result);
    
    return remainder_bit_length;
}
