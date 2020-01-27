#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

/*
 * TEST Case
 * - First Positive Number & Negative Number
 * - Throw error ( std::invalid_argument )
 * - Single_Byte & Multi_Bytes // None => All target data should be multi_bytes
 */

TEST(test_method_string_to_integar_ptr, test_throw_error_none_data)
{
    // null value
    const char *test_value = "";
    int8_t* result(nullptr);
    EXPECT_THROW(string_to_integar_ptr(test_value, 0, &result), std::invalid_argument);
}

TEST(test_method_string_to_integar_ptr, test_throw_error_invalid_data)
{
    // null value
    const char *test_value = " ";
    int8_t* result(nullptr);
    EXPECT_THROW(string_to_integar_ptr(test_value, 1, &result), std::invalid_argument);
}

TEST(test_method_string_to_integar_ptr, test_pos_throw_error_only_gave_negative)
{
    const char* test_value = "-";
    int8_t* result(nullptr);
    EXPECT_THROW(string_to_integar_ptr(test_value, 1, &result), std::invalid_argument);  
}

TEST(test_method_string_to_integar_ptr, test_int8_t_pos_non_dividen_byte_length)
{
    const char *test_value = "12345678";
    int8_t* result(nullptr);
    int16_t result_bit_length( string_to_integar_ptr(test_value, 8, &result) );
}

TEST(test_method_string_to_integar_ptr, test_int8_t_neg_non_dividen_byte_length)
{
    const char *test_value = "-12345678";
    int8_t* result(nullptr);
    int16_t result_bit_length( string_to_integar_ptr(test_value, 9, &result) );
}

TEST(test_method_string_to_integar_ptr, test_int8_t_pos_dividen_byte_length)
{
    const char *test_value = "123456789";
    int8_t* result(nullptr);
    int16_t result_bit_length( string_to_integar_ptr(test_value, 9, &result) );
}

TEST(test_method_string_to_integar_ptr, test_int8_t_neg_dividen_byte_length)
{
    const char *test_value = "-123456789";
    int8_t* result(nullptr);
    int16_t result_bit_length( string_to_integar_ptr(test_value, 10, &result) );
}

// 해석은 정방향
// arr_digit_of_three[]는 역방향