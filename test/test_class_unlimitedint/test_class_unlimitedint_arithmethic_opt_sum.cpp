#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"


using namespace openmath;

namespace {
    int8_t single_one(0b0000'0001);
    int8_t single_pos(0b0110'1001);
    int8_t single_neg(0b1001'0110);

    UnLimitedInt single_one_obj(single_one);
    UnLimitedInt single_pos_obj(single_pos);
    UnLimitedInt single_neg_obj(single_neg);

    int16_t multi_pos(0b0110'1001'1001'0110);
    int16_t multi_neg(0b1001'0110'0110'1001);

    UnLimitedInt multi_pos_obj(multi_pos);
    UnLimitedInt multi_neg_obj(multi_neg);
}


TEST(class_unlimitedint_arithmetic_opt, test_sum_opt_by_single_byte)
{
    int8_t comp(single_one + single_pos);
    UnLimitedInt comp_obj(comp);
    UnLimitedInt result(single_pos_obj + single_one_obj);
    
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 7);
    EXPECT_EQ(result.GetBitLength(), comp_obj.GetBitLength());

    EXPECT_EQ(result.GetByteCapacity(), 1);
    EXPECT_EQ(result.GetByteCapacity(), comp_obj.GetByteCapacity());
    
    EXPECT_EQ(result.GetValuePtr()[0], comp);
}

TEST(class_unlimitedint_arithmetic_opt, test_sum_opt_by_multi_bytes)
{
    int16_t comp(single_one + multi_pos);
    UnLimitedInt comp_obj(comp);
    UnLimitedInt result(multi_pos_obj + single_one_obj);
    
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetBitLength(), comp_obj.GetBitLength());
    EXPECT_EQ(result.GetByteCapacity(), 2);
    EXPECT_EQ(result.GetByteCapacity(), comp_obj.GetByteCapacity());
    EXPECT_EQ(result.GetValuePtr()[0], static_cast<int8_t>(0b1001'0111));
    EXPECT_EQ(result.GetValuePtr()[1], single_pos);
}

TEST(class_unlimitedint_arithmetic_opt, test_sum_opt_by_single_byte_and_neg_Test)
{
    int8_t comp(0b1001'0111);
    UnLimitedInt comp_obj(comp);
    UnLimitedInt result(single_neg + single_one);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 7);
    EXPECT_EQ(result.GetByteCapacity(), 1);
    EXPECT_EQ(result.GetByteCapacity(), comp_obj.GetByteCapacity());
    EXPECT_EQ(result.GetValuePtr()[0], comp);
}