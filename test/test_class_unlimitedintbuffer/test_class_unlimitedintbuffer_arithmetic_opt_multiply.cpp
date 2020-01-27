#include <gtest/gtest.h>

#include "openmath/UnLimitedIntBuffer.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

namespace openmath {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t rhs_multi(0b1001'0110'0110'1001);

    UnLimitedIntBuffer lhs_obj(lhs);
    UnLimitedIntBuffer rhs_obj(rhs);

    UnLimitedIntBuffer lhs_multi_obj(lhs_multi);
    UnLimitedIntBuffer rhs_multi_obj(rhs_multi);
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_multiply, test_zero)
{
    UnLimitedIntBuffer result_pos(lhs_obj);
    result_pos.multiply(0, 0);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 0);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], 0);
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_multiply, test_int8_t_pos_multiply_two)
{
    UnLimitedIntBuffer result_pos(lhs_obj);
    int8_t rhs(2);
    result_pos.multiply(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 8);
    EXPECT_EQ(result_pos.GetByteCapacity(), 2);
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b1101'0010));
    EXPECT_EQ(result_pos.GetValuePtr()[1], 0);
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_multiply, test_int8_t_pos_multiply_neg_two)
{
    UnLimitedIntBuffer result_pos(lhs_obj);
    int8_t rhs(-2);
    result_pos.multiply(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), false);
    EXPECT_EQ(result_pos.GetBitLength(), 8);
    EXPECT_EQ(result_pos.GetByteCapacity(), 2); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b0010'1110));
    EXPECT_EQ(result_pos.GetValuePtr()[1], static_cast<int8_t>(0b1111'1111));
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_multiply, test_int8_t__neg_multiply_two)
{
    UnLimitedIntBuffer result_neg(rhs_obj);
    int8_t rhs(2);
    result_neg.multiply(&rhs, 1);
    EXPECT_EQ(result_neg.IsPositive(), false);
    EXPECT_EQ(result_neg.GetBitLength(), 8);
    EXPECT_EQ(result_neg.GetByteCapacity(), 2); 
    EXPECT_EQ(result_neg.GetValuePtr()[0], static_cast<int8_t>(0b0010'1100));
    EXPECT_EQ(result_neg.GetValuePtr()[1], static_cast<int8_t>(0b1111'1111));
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_multiply, test_int8_t__neg_multiply_neg_two)
{
    UnLimitedIntBuffer result_neg(rhs_obj);
    int8_t rhs(-2);
    result_neg.multiply(&rhs, 1);
    EXPECT_EQ(result_neg.IsPositive(), true);
    EXPECT_EQ(result_neg.GetBitLength(), 8);
    EXPECT_EQ(result_neg.GetByteCapacity(), 2); 
    EXPECT_EQ(result_neg.GetValuePtr()[0], static_cast<int8_t>(0b1101'0100));
    EXPECT_EQ(result_neg.GetValuePtr()[1], 0);
}
// 1111'1001'0110
// 1111'0010'1100
// 0000'1101'0100

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_multiply, test_int16_t_pos)
{
    int8_t comp_top(0b0000'0011);
    int8_t comp_mid(0b1011'0110);
    int8_t comp_low(0b0100'0110);
    UnLimitedIntBuffer result_pos(lhs_multi_obj);
    int8_t rhs(9);
    result_pos.multiply(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 18);
    EXPECT_EQ(result_pos.GetByteCapacity(), 3);
    EXPECT_EQ(result_pos.GetValuePtr()[0], comp_low);
    EXPECT_EQ(result_pos.GetValuePtr()[1], comp_mid);
    EXPECT_EQ(result_pos.GetValuePtr()[2], comp_top);
}