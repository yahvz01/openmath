#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

using namespace openmath;

TEST(method_half_adder, test_int8_t_carry_out_false)
{
    int8_t rhs(0b1010'1010);
    int8_t lhs(0b0101'0101);
    int8_t expected(0b1111'1111);
    
    int8_t result;
    bool carry_out = half_adder(lhs, rhs, result);
    EXPECT_FALSE(carry_out);
    EXPECT_EQ(result, expected);
}

TEST(method_half_adder, test_int8_t_carry_out_true)
{
    int8_t rhs(0b1010'1011);
    int8_t lhs(0b0101'0101);
    int8_t expected(0b0000'0000);
    
    int8_t result;
    bool carry_out = half_adder(lhs, rhs, result);
    EXPECT_TRUE(carry_out);
    EXPECT_EQ(result, expected);
}

TEST(method_half_adder, test_int8_t_carry_out_true_plus_one)
{
    int8_t rhs(0b1110'1101);
    int8_t lhs(0b0000'0001);
    int8_t expected(0b1110'1110);
    
    int8_t result;
    bool carry_out = half_adder(lhs, rhs, result);
    EXPECT_FALSE(carry_out);
    EXPECT_EQ(result, expected);
}

TEST(method_half_adder, test_int16_t_carry_out_false)
{
    int16_t rhs(0b1111'1111'1110'1101);
    int16_t lhs(0b0000'0000'0000'0001);
    int16_t expected(0b1111'1111'1110'1110);
    int16_t result;
    bool carry_out = half_adder(lhs, rhs, result);
    EXPECT_FALSE(carry_out);
    EXPECT_EQ(result, expected);
}

TEST(method_half_adder, test_int16_t_carry_out_true_plus_one)
{
    int16_t rhs(0b1111'1111'1111'1111);
    int16_t lhs(0b0000'0000'0000'0001);
    int16_t expected(0b0000'0000'0000'0000);
    int16_t result;
    bool carry_out = half_adder(lhs, rhs, result);
    EXPECT_TRUE(carry_out);
    EXPECT_EQ(result, expected);
}

