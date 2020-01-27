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

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_divide, test_zero)
{
    
    UnLimitedIntBuffer result(lhs);
    //EXPECT_THROW(result.divide(0, 0), std::invalid_argument);
    //EXPECT_THROW(result.divide(0, 1), std::invalid_argument);
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_divide, test_int8_t_pos_multiply_two)
{
    UnLimitedIntBuffer result_pos(lhs);
    int8_t rhs(2);
    result_pos.divide(&rhs, 1);

    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 6);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b0011'0100));
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_divide, test_int8_t__neg_multiply_two)
{
    UnLimitedIntBuffer result_pos(rhs);
    int8_t rhs(2);
    result_pos.divide(&rhs, 1);

    EXPECT_EQ(result_pos.IsPositive(), false);
    EXPECT_EQ(result_pos.GetBitLength(), 6);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b1100'1011));
}

TEST(test_class_UnLimitedIntBuffer_arithmetic_opt_divide, test_int16_t_pos)
{
    int8_t comp_low(0b1011'1011);
    int8_t comp_top(0b0000'1011);
    
    UnLimitedIntBuffer result_pos(lhs_multi);
    int8_t rhs(9);
    result_pos.divide(&rhs, 1);

    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 12);
    EXPECT_EQ(result_pos.GetByteCapacity(), 2);
    EXPECT_EQ(result_pos.GetValuePtr()[0], comp_low);
    EXPECT_EQ(result_pos.GetValuePtr()[1], comp_top);
}