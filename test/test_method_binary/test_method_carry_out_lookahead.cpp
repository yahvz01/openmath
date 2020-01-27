#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

namespace {
    int8_t zero(0);
    
    int8_t lhs(0b0101'0000);
    int8_t rhs(0b1010'1111);
    int8_t rhs_comp(0b0101'0001);
}

using namespace openmath;

TEST(method_carry_out_lookahead, test_int8_return_true)
{   
    bool result = carry_out_lookahead(rhs, rhs_comp);
    EXPECT_TRUE(result);
}

TEST(method_carry_out_lookahead, test_int8_return_false)
{
    bool result00 = carry_out_lookahead(lhs, zero);
    bool result01 = carry_out_lookahead(zero, rhs);
    bool result02 = carry_out_lookahead(lhs, rhs);
    bool result03 = carry_out_lookahead(rhs, rhs_comp);
    EXPECT_FALSE(result00);
    EXPECT_FALSE(result01);
    EXPECT_FALSE(result02);
    EXPECT_TRUE(result03);
}

TEST(method_carry_out_lookahead, test_int8_carry_from_first_digit_return_true)
{
    int8_t lhs(0b0000'0001);
    int8_t rhs(0b1111'1111);
    bool result = carry_out_lookahead(lhs, rhs);
    EXPECT_TRUE(result);
}

TEST(method_carry_out_lookahead, test_int8_carry_from_first_digit_return_false)
{
    int8_t lhs(0b0000'0001);
    int8_t rhs(0b1111'1110);
    bool result = carry_out_lookahead(lhs, rhs);
    EXPECT_FALSE(result);
}

TEST(method_carry_out_lookahead, test_int8_carry_from_second_digit_return_true)
{
    int8_t lhs(0b0000'0011);
    int8_t rhs(0b1111'1110);
    bool result = carry_out_lookahead(lhs, rhs);
    EXPECT_TRUE(result);
}

