#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

#include <iostream>

using namespace openmath;


// Positive Number Test

TEST(method_get_digit_binary_number, test_int8_t)
{
    int8_t result = get_digit_binary_number(0b0010'0000);
    EXPECT_EQ(result, 6);
}
TEST(method_get_digit_binary_number, test_int8_t_zero)
{
    int16_t result = get_digit_binary_number(0b0000'0000);
    EXPECT_EQ(result, 0);
}

TEST(method_get_digit_binary_number, test_int8_t_one)
{
    int16_t result = get_digit_binary_number(0b0000'0001);
    EXPECT_EQ(result, 1);
}


TEST(method_get_digit_binary_number, test_int16_t)
{
    int16_t value(0b0000'0000'0110'0000);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 7);
}

TEST(method_get_digit_binary_number, test_int16_t_zero)
{
    int16_t result = get_digit_binary_number(0b0000'0000'0000'0000);
    EXPECT_EQ(result, 0);
}

TEST(method_get_digit_binary_number, test_int16_t_one)
{
    int16_t result = get_digit_binary_number(0b0000'0000'0000'0001);
    EXPECT_EQ(result, 1);
}


TEST(method_get_digit_binary_number, test_int32_t)
{
    int32_t value(0b0000'0000'0110'0000'0000'0000'0110'0000);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 23);
}

TEST(method_get_digit_binary_number, test_int32_t_zero)
{
    int32_t value(0b0000'0000'0000'0000'0000'0000'0000'0000);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 0);
}
TEST(method_get_digit_binary_number, test_int32_t_one)
{
    int32_t value(0b0000'0000'0000'0000'0000'0000'0000'0001);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 1);
}

TEST(method_get_digit_binary_number, test_int8_t_negative_one)
{
    int8_t value(-1);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 1);
}

TEST(method_get_digit_binary_number, test_int16_t_negative_one)
{
    int8_t value(-1);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 1);
}
TEST(method_get_digit_binary_number, test_int16_t_negative_num00)
{
    // 0011'0101'0011'0000
    // 1100'1010'1101'1111
    int16_t value(-13616);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 14);
}


TEST(method_get_digit_binary_number, test_int16_t_negative_num01)
{
    // 0111'0101'0011'0000
    // 1000'1010'1101'1111
    int16_t value(-30000);
    int16_t result = get_digit_binary_number(value);
    EXPECT_EQ(result, 15);
}

