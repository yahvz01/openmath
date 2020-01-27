#include <gtest/gtest.h>

#include "openmath/UnLimitedIntBuffer.hpp"


using namespace openmath;

namespace {
    int8_t single_one(0b0000'0001);
    int8_t single_pos(0b0110'1001);
    int8_t single_neg(0b1001'0110);

    UnLimitedIntBuffer single_one_obj(single_one);
    UnLimitedIntBuffer single_pos_obj(single_pos);
    UnLimitedIntBuffer single_neg_obj(single_neg);

    int16_t multi_pos(0b0110'1001'1001'0110);
    int16_t multi_neg(0b1001'0110'0110'1001);

    UnLimitedIntBuffer multi_pos_obj(multi_pos);
    UnLimitedIntBuffer multi_neg_obj(multi_neg);
}


TEST(class_UnLimitedIntBuffer_arithmetic_opt, test_subtract_opt_by_single_byte)
{
    int8_t comp(single_pos - single_one);
    UnLimitedIntBuffer comp_obj(comp);
    UnLimitedIntBuffer result(single_pos_obj);
    result.subtract(&single_one, 1);
    
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 7);
    EXPECT_EQ(result.GetBitLength(), comp_obj.GetBitLength());

    EXPECT_EQ(result.GetByteCapacity(), 1);
    EXPECT_EQ(result.GetByteCapacity(), comp_obj.GetByteCapacity());
    
    EXPECT_EQ(result.GetValuePtr()[0], comp);
}

TEST(class_UnLimitedIntBuffer_arithmetic_opt, test_subtract_opt_by_multi_bytes)
{
    int16_t comp(multi_pos - single_one);
    UnLimitedIntBuffer comp_obj(comp);
    UnLimitedIntBuffer result(multi_pos_obj);// - single_one_obj);
    result.subtract(&single_one, 1);
    
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetBitLength(), comp_obj.GetBitLength());
    EXPECT_EQ(result.GetByteCapacity(), 2);
    EXPECT_EQ(result.GetByteCapacity(), comp_obj.GetByteCapacity());
    EXPECT_EQ(result.GetValuePtr()[0], static_cast<int8_t>(0b1001'0101));
    EXPECT_EQ(result.GetValuePtr()[1], single_pos);
}

TEST(class_UnLimitedIntBuffer_arithmetic_opt, test_subtract_obj_by_diff_bytes)
{
    int16_t comp(0b1001'0110'0110'1000);
    UnLimitedIntBuffer comp_obj(comp);
    int8_t *comp_ptr = reinterpret_cast<int8_t *>(&comp);

    int16_t result_int(multi_neg - single_one);
    UnLimitedIntBuffer result(result_int);
    
    
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), 2);
    EXPECT_EQ(result.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(result.GetValuePtr()[1], comp_ptr[1]);
}