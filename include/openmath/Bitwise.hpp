#pragma once

#include <cstdint>

namespace openmath {
    /*
     *  @param last parameter is result in heap memory
     *  @return bit_length
     */
    

    int8_t bitwise_and_single_byte(const int8_t& lhs, const int8_t& rhs);
    int8_t bitwise_or_single_byte(const int8_t& lhs, const int8_t& rhs);
    int8_t bitwise_xor_single_byte(const int8_t& lhs, const int8_t& rhs);
    using bit_opt = int8_t (*)(const int8_t&, const int8_t&);

    int16_t bitwise_not_opt_ptr(int8_t * const value_ptr, int16_t byte_length, int8_t **result);
    int16_t bitwise_opt_ptr(int8_t* lhs, int16_t lhs_byte_length, int8_t* rhs, int16_t rhs_byte_length,const bit_opt& bit_opt, int8_t **result, bool do_shrink);

    
    int16_t left_bit_shift_with_extend(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result, bool do_shrink);
    int16_t left_bit_shift_with_extend_return_allocated_byte_length(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result);
    

    int16_t left_bit_shift(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result, bool do_shrink);
    int16_t right_bit_shift(int8_t *value_ptr, int16_t byte_length, int16_t shift_jump, int8_t **result, bool do_shrink);

    int16_t left_bit_single_shift(int8_t *value_ptr, int16_t byte_length, int8_t **result, bool do_shrink);
    int16_t right_bit_single_shift(int8_t *value_ptr, int16_t byte_length, int8_t **result, bool do_shrink);
}