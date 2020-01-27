#include <gtest/gtest.h>

#include "openmath/UnLimitedIntBuffer.hpp"

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

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_remainder, test_zero)
{
    //EXPECT_THROW(UnLimitedIntBuffer result_pos(lhs_obj % 0), std::invalid_argument);
    UnLimitedIntBuffer result(lhs);

    //EXPECT_THROW(result.remainder(0, 0), std::invalid_argument);
    //EXPECT_THROW(result.remainder(0, 1), std::invalid_argument);
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_remainder, test_int8_t_pos_multiply_two)
{
    UnLimitedIntBuffer result_pos(lhs);
    int8_t rhs(2);
    result_pos.remainder(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 1);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], 1);
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_remainder, test_int8_t_pos_multiply_neg_two)
{
    UnLimitedIntBuffer result_pos(lhs);
    int8_t rhs(-2);
    result_pos.remainder(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 1);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], 1);
}


TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_remainder, test_int8_t__neg_multiply_two)
{
    int8_t value(0b1111'1101);
    UnLimitedIntBuffer result_pos(value);
    int8_t rhs(2);
    result_pos.remainder(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), false);
    EXPECT_EQ(result_pos.GetBitLength(), 1);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b1111'1111));
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_remainder, test_int16_t_pos)
{
    // 0b0110'1001'1001'0110
    int8_t comp_low(0b1011'1011);
    int8_t comp_top(0b0000'1011);
    
    int8_t comp(0b0000'0011);
    UnLimitedIntBuffer result_pos(lhs_multi);
    int8_t rhs(9);
    result_pos.remainder(&rhs, 1);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 2);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1);
    EXPECT_EQ(result_pos.GetValuePtr()[0], comp);
}