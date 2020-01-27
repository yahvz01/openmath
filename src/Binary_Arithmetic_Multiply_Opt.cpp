#include "openmath/Binary.hpp"

#include "openmath/Bitwise.hpp"


int16_t openmath::multiply_ptr(int8_t* const lhs, const int16_t& lhs_byte_length, int8_t* const rhs, const int16_t& rhs_byte_length, int8_t** result, bool return_byte_legnth)
{
    int16_t longer_byte_length(lhs_byte_length);
    int8_t* longer_data_ptr(lhs);
    int16_t smaller_byte_length(rhs_byte_length);
    int8_t* smaller_data_ptr(rhs);
    if(smaller_byte_length > longer_byte_length)
    {
        using namespace std;
        swap(longer_byte_length, smaller_byte_length);
        swap(longer_data_ptr, smaller_data_ptr);
    }
    // Crime scene
    // accumulator_length = longer_byte_length
    int16_t temp_result_byte_length(lhs_byte_length + rhs_byte_length);
    int8_t *temp_result( static_cast<int8_t *>( malloc( temp_result_byte_length ) ) );
    memset(temp_result, 0, temp_result_byte_length);
    int8_t *accumulator_ptr( temp_result + smaller_byte_length );
//    int8_t *qutient_ptr( temp_result );
    // -M
    int8_t *multiplicand_complentary( make_binary_complement_ptr(longer_data_ptr, longer_byte_length) );
    
    memcpy(temp_result, smaller_data_ptr, smaller_byte_length);

    bool q_prev(false);
    bool q_first( temp_result[0] & bit_pos[1] );

    int16_t process_count(smaller_byte_length * 8);
    // debug process_count -> 3
    for(int16_t idx(0); idx < process_count; ++idx)
    {
        if(q_prev != q_first)
        {
            int8_t *accumulator_temp_result(nullptr);
            if( q_first ) // 1'0 (A = A - M)
            {
                adder_ptr(accumulator_ptr, longer_byte_length, multiplicand_complentary, longer_byte_length, &accumulator_temp_result, true, false);
            }
            else // 0'1 
            {
                adder_ptr(accumulator_ptr, longer_byte_length, longer_data_ptr, longer_byte_length, &accumulator_temp_result, true, false);
            }
            memcpy(accumulator_ptr, accumulator_temp_result, longer_byte_length);
            free(accumulator_temp_result);
        }

        // shift
        int8_t* right_shifted_data(nullptr);
        right_bit_single_shift(temp_result, temp_result_byte_length, &right_shifted_data, false);
        free(temp_result);
        temp_result = right_shifted_data;

        accumulator_ptr = (temp_result + smaller_byte_length );

        q_prev = q_first;
        q_first = ( temp_result[0] & bit_pos[1] );
    }
    free(multiplicand_complentary);
    *result = temp_result;
    if(return_byte_legnth)
    {
        return temp_result_byte_length;
    }
    return get_digit_binary_number_ptr(*result, true, temp_result_byte_length);
}

