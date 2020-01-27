#include <gtest/gtest.h>

#include "openmath/FixedByteLengthInt.hpp"

using namespace openmath;

namespace {
    int8_t lhs(0b0110'1001);
    int8_t lhs_one_left_shift(0b1101'0010);
    int8_t lhs_one_right_shift(0b0011'0100);
    
    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t lhs_multi_two_left_shift(0b1010'0110'0101'1000);
    int16_t lhs_multi_two_right_shift(0b0001'1010'0110'0101);

    int8_t* lhs_multi_two_left_shift_ptr( reinterpret_cast<int8_t*>(&lhs_multi_two_left_shift));
    int8_t* rhs_multi_two_right_shift_ptr( reinterpret_cast<int8_t *>(&lhs_multi_two_right_shift));

    int8_t rhs(0b1001'0110);
    int8_t rhs_one_left_shift(0b0010'1100);
    int8_t rhs_one_right_shift(0b1100'1011);
    
    int16_t rhs_multi(0b1001'0110'0110'1001);
    int16_t rhs_multi_two_left_shift(0b0101'1001'1010'0100);
    int16_t rhs_multi_two_right_shift(0b1110'0101'1001'1010);

}

TEST(test_class_fixedbytelengthint_bit_shift_opt, test_pos_left_shift_single_byte)
{
    FixedByteLengthInt lhs_obj(lhs, 1);
    lhs_obj = lhs_obj << 1;
    EXPECT_FALSE(lhs_obj.IsPositive());
    EXPECT_EQ(*lhs_obj.GetValuePtr(), lhs_one_left_shift);
}

TEST(test_class_fixedbytelengthint_bit_shift_opt, test_pos_left_shift_multi_bytes)
{
    FixedByteLengthInt lhs_multi_obj(lhs_multi, 2);
    lhs_multi_obj = lhs_multi_obj << 2;
    EXPECT_FALSE(lhs_multi_obj.IsPositive());
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[0], lhs_multi_two_left_shift_ptr[0]);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[1], lhs_multi_two_left_shift_ptr[1]);
}

TEST(test_class_fixedbytelengthint_bit_shift_opt, test_pos_right_shift_single_byte)
{
    FixedByteLengthInt lhs_obj(lhs, 1);
    lhs_obj = lhs_obj >> 1;
    EXPECT_TRUE(lhs_obj.IsPositive());
    EXPECT_EQ(*lhs_obj.GetValuePtr(), lhs_one_right_shift);
}

TEST(test_class_fixedbytelengthint_bit_shift_opt, test_pos_right_shift_multi_bytes)
{
    FixedByteLengthInt lhs_multi_obj(lhs_multi, 2);
    lhs_multi_obj = lhs_multi_obj >> 2;
    EXPECT_TRUE(lhs_multi_obj.IsPositive());
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[0], rhs_multi_two_right_shift_ptr[0]);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[1], rhs_multi_two_right_shift_ptr[1]);
}