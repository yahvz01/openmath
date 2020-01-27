#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"

using namespace openmath;

namespace openmath {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t rhs_multi(0b1001'0110'0110'1001);

    UnLimitedInt lhs_obj(lhs);
    UnLimitedInt rhs_obj(rhs);

    UnLimitedInt lhs_multi_obj(lhs_multi);
    UnLimitedInt rhs_multi_obj(rhs_multi);
}

TEST(test_class_unlimitedint_arithmetic_opt_divide, test_zero)
{
    EXPECT_THROW(UnLimitedInt result_pos(lhs_obj / 0), std::invalid_argument);
}

TEST(test_class_unlimitedint_arithmetic_opt_divide, test_int8_t_pos_multiply_two)
{
    UnLimitedInt result_pos(lhs_obj / 2);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 6);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b0011'0100));
}

TEST(test_class_unlimitedint_arithmetic_opt_divide, test_int8_t__neg_multiply_two)
{
    UnLimitedInt result_pos(rhs_obj / 2);
    EXPECT_EQ(result_pos.IsPositive(), false);
    EXPECT_EQ(result_pos.GetBitLength(), 6);
    EXPECT_EQ(result_pos.GetByteCapacity(), 1); 
    EXPECT_EQ(result_pos.GetValuePtr()[0], static_cast<int8_t>(0b1100'1011));
}

TEST(test_class_unlimitedint_arithmetic_opt_divide, test_int16_t_pos)
{
    int8_t comp_low(0b1011'1011);
    int8_t comp_top(0b0000'1011);
    
    UnLimitedInt result_pos(lhs_multi_obj / 9);
    EXPECT_EQ(result_pos.IsPositive(), true);
    EXPECT_EQ(result_pos.GetBitLength(), 12);
    EXPECT_EQ(result_pos.GetByteCapacity(), 2);
    EXPECT_EQ(result_pos.GetValuePtr()[0], comp_low);
    EXPECT_EQ(result_pos.GetValuePtr()[1], comp_top);
}