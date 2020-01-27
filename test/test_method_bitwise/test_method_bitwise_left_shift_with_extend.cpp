#include <gtest/gtest.h>

#include "openmath/Bitwise.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

TEST(test_method_bitwise_left_shift_with_extend, test_int8_t)
{
    int8_t value(0b1101'1101);

    int8_t* result(nullptr);
    int16_t result_bit_length(left_bit_shift_with_extend(&value, 1, 1, &result, false));


    int8_t comp(0b1011'1010);
    EXPECT_EQ(result_bit_length, 7);
    EXPECT_EQ(result[0], comp);
}

TEST(test_method_bitwise_left_shift_with_extend, test_int8_t_over_extend)
{
    int8_t value(0b1101'1101);

    int8_t* result(nullptr);
    int16_t result_bit_length(left_bit_shift_with_extend(&value, 1, 9, &result, false));

    int8_t comp(0b1011'1010);
    EXPECT_EQ(result_bit_length, 15);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], comp);
}

TEST(test_method_bitwise_left_shift_with_extend, test_int16_t_over_extend)
{
    int16_t value(0b1001'0110'0110'1001);
    int8_t* value_ptr(reinterpret_cast<int8_t*>(&value));

    int8_t* result(nullptr);
    int16_t result_bit_length(left_bit_shift_with_extend(value_ptr, 2, 9, &result, false));

    int8_t comp00(0b1101'0010);
    int8_t comp01(0b0010'1100);
    int8_t comp02(0b1111'1111);
    
    EXPECT_EQ(result_bit_length, 24);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], comp00);
    EXPECT_EQ(result[2], comp01);
    EXPECT_EQ(result[3], comp02);
}