#pragma once

#include <cstdint>
#include <cstring>
#include <utility>


/*
 *  Binary Module is generic binary manipulation module
 *  for basic integer type
 */

namespace openmath {
    constexpr int8_t SIGN_BIT_POS = 0b1000'0000;
    constexpr int8_t bit_pos[] = {
        0b0000'0000,
        0b0000'0001,
        0b0000'0010,
        0b0000'0100,
        0b0000'1000,
        0b0001'0000,
        0b0010'0000,
        0b0100'0000,
        SIGN_BIT_POS
    };
}

namespace openmath {
    
    template <typename Tp>
    Tp make_binary_complement(const Tp& value);
    
    template <typename Tp>
    bool carry_out_lookahead(const Tp& lhs, const Tp& rhs);

    template <typename Tp>
    bool half_adder(const Tp& lhs, const Tp& rhs, Tp& result);

    template <typename Tp>
    bool full_adder(const Tp& lhs, const Tp& rhs, bool carry_in, Tp& result);

    template <typename Tp>
    int16_t get_digit_binary_number(const Tp& value);

    template <typename Tp>
    bool is_positive(const Tp& value);
}

namespace openmath {

    bool is_positive_ptr(const int8_t *value, const int16_t& byte_length);

    bool is_zero_ptr(int8_t *value_ptr, const int16_t& byte_length);
    bool is_one_ptr(int8_t *value_ptr, const int16_t& byte_length);
    
    bool carry_out_lookahead_ptr(int8_t *lhs, const int16_t& lhs_byte_length, int8_t *rhs, const int16_t& rhs_byte_length, bool has_sign = false);

    int16_t get_digit_binary_number_ptr(int8_t* const value_ptr, bool is_signed, const int16_t& byte_length);
    
    int8_t* make_binary_complement_ptr(const int8_t *value_ptr, int16_t byte_length);
}

namespace openmath {
    bool full_adder_ptr(const int8_t* lhs, const int8_t* rhs, int8_t** result, bool carry_in);
    int16_t adder_ptr(int8_t* const lhs, const int16_t& lhs_byte_length, int8_t* const rhs, const int16_t& rhs_byte_length, int8_t** result, bool do_fixed_byte_by_max_byte, bool return_byte_length);

    // do_shrinked 
    int16_t multiply_ptr(int8_t* const lhs, const int16_t& lhs_byte_length, int8_t* const rhs, const int16_t& rhs_byte_length, int8_t** result, bool return_byte_legnth);

    int16_t divide_ptr(int8_t* const dividend, const int16_t& dividend_byte_length, int8_t* const divisor, const int16_t& divisor_byte_length, int8_t** result);
    int16_t remainder_ptr(int8_t* const dividend, const int16_t& dividend_byte_length, int8_t* const divisor, const int16_t& divisor_byte_length, int8_t** result);
    std::pair<int16_t, int16_t> divide_remainder_ptr(int8_t* const dividend, const int16_t& dividend_byte_length, int8_t* const divisor, const int16_t& divisor_byte_length, int8_t** qutient, int8_t** remainder);
}

namespace openmath {
    int8_t *shrink_unlimitedint_memory(const int8_t *target_ptr, const int16_t& target_byte_length, const int16_t shrinked_byte_length);
    int8_t *shrink_unlimitedint_memory_and_free(int8_t *target_ptr, const int16_t& target_byte_length, const int16_t shrinked_byte_length);
}

namespace openmath {
    bool byte_carry_out_lookahead(const int8_t& lhs, const int8_t& rhs);

    std::pair<bool, bool> byte_carry_out_lookahead_with_propaganda(const int8_t& lhs, const int8_t& rhs, bool has_sign);

    bool byte_half_adder(const int8_t& lhs, const int8_t& rhs, int8_t& result);

    bool byte_full_adder(const int8_t& lhs, const int8_t& rhs, bool carry_in, int8_t& result);
}

namespace openmath {
    int16_t bit_len_to_byte_len(int16_t bit_length);
    int16_t bit_len_to_byte_len_only_meaningfull(int16_t bit_length);
}

namespace openmath {
    int8_t* stretch_data_length_for_sign_int(int8_t* value, int16_t prev_data_length, int16_t new_data_length);
}


/*
 * Only for sign Integar
 */
namespace openmath {
    int16_t string_to_integar_ptr( const char *value_ptr, const int16_t& value_byte_length, int8_t** result);
    char* integar_to_c_string_ptr(int8_t* value_ptr, const int16_t& value_byte_length);
}

#include "Binary_Impl.hpp"

