#include <gtest/gtest.h>

#include "openmath/Binary.hpp"
#include <cstdint>
#include <type_traits>

using namespace openmath;

TEST(method_get_digit_binary_number, test_ptr_version_int8_t)
{
    int8_t value(0b0111'0110);
    int16_t digit_result = get_digit_binary_number_ptr(&value, std::is_signed<int8_t>::value, sizeof(value));
    EXPECT_EQ(digit_result, 7);
}

TEST(method_get_digit_binary_number, test_ptr_version_int8_t_negative)
{
    int8_t value(0b1111'1111);
    int16_t digit_result = get_digit_binary_number_ptr(&value, std::is_signed<int8_t>::value, sizeof(value));
    EXPECT_EQ(digit_result, 1);
}

TEST(method_get_digit_binary_number, test_ptr_version_int16_t)
{
    int16_t value(0b0011'0000'0111'0110);
    int8_t *converted_ptr = reinterpret_cast<int8_t *>(&value);
    int16_t digit_result = get_digit_binary_number_ptr(converted_ptr, std::is_signed<int16_t>::value, sizeof(value));
    EXPECT_EQ(digit_result, 14);
}

TEST(method_get_digit_binary_number, test_ptr_version_int16_t_negative)
{
    // 0b0000'1010'0000'0000
    // 0b1111'0111'1111'1111
    int16_t value(0b1111'0111'1111'1111);
    int8_t *converted_ptr = reinterpret_cast<int8_t *>(&value);
    int16_t digit_result = get_digit_binary_number_ptr(converted_ptr, std::is_signed<int16_t>::value, sizeof(value));
    EXPECT_EQ(digit_result, 12);
}

TEST(method_get_digit_binary_number, test_error_version)
{
    int16_t value(0b1101'0011'0010'1100);
    int8_t* value_ptr( reinterpret_cast<int8_t*>(&value));
    int16_t digit_result( get_digit_binary_number_ptr(value_ptr, true, 2));
    EXPECT_EQ(digit_result, 14);
}