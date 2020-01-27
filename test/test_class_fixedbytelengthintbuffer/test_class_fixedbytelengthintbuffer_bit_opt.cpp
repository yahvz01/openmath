#include <gtest/gtest.h>

#include "openmath/FixedByteLengthIntBuffer.hpp"

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int8_t lhs_left_shift_one(0b1101'0010);
    int8_t lhs_left_shift_two(0b1010'0100);
    int8_t rhs_left_shift_one(0b0010'1100);

    int8_t lhs_right_shift_one(0b0011'0100);
    int8_t rhs_right_shift_one(0b1100'1011);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int8_t *lhs_multi_ptr(reinterpret_cast<int8_t *>(&lhs_multi));
    int16_t rhs_multi(0b1001'0110'0110'1001);
    int8_t *rhs_multi_ptr(reinterpret_cast<int8_t *>(&rhs_multi));
    
    int16_t lhs_multi_left_shift_one(0b1101'0011'0010'1100);
    int16_t lhs_multi_left_shift_sev(0b1100'1011'0000'0000);
    int16_t lhs_multi_left_shift_eig(0b1001'0110'0000'0000);
    int16_t lhs_multi_left_shift_nin(0b0010'1100'0000'0000);

    int16_t rhs_multi_left_shift_one(0b0010'1100'1101'0010);
    int16_t rhs_multi_left_shift_sev(0b0011'0100'1000'0000);
    int16_t rhs_multi_left_shift_eig(0b0110'1001'0000'0000);
    int16_t rhs_multi_left_shift_nin(0b1101'0010'0000'0000);

    int8_t bit_full(0b1111'1111);
}

using namespace openmath;

TEST(test_class_fixedbytelengthintbuffer_bit_opt, test_not_opt_single_byte)
{
    FixedByteLengthIntBuffer base(lhs, 1);
    
    base.bitwise_not();
    EXPECT_EQ(base.GetValuePtr()[0], rhs);
}

TEST(test_class_fixedbytelengthintbuffer_bit_opt, test_not_opt_multi_bytes)
{
    FixedByteLengthIntBuffer base(lhs, 2);
    base.bitwise_not();
    EXPECT_EQ(base.GetValuePtr()[0], rhs);
    EXPECT_EQ(base.GetValuePtr()[1], bit_full);
}

TEST(test_class_fixedbytelengthintbuffer_bit_opt, test_and_opt_multi_byte)
{
    FixedByteLengthIntBuffer base(lhs_multi, 2);
    int8_t *comp_ptr(reinterpret_cast<int8_t *>(&rhs_multi));
    base.bitwise_and(comp_ptr, 2);
    EXPECT_EQ(base.GetValuePtr()[0], 0);
    EXPECT_EQ(base.GetValuePtr()[1], 0);
}

TEST(test_class_fixedbytelengthintbuffer_bit_opt, test_or_opt)
{
    FixedByteLengthIntBuffer base(lhs_multi, 2);
    int8_t *comp_ptr(reinterpret_cast<int8_t *>(&rhs_multi));
    base.bitwise_or(comp_ptr, 2);
    EXPECT_EQ(base.GetValuePtr()[0], bit_full);
    EXPECT_EQ(base.GetValuePtr()[1], bit_full);
}

TEST(test_class_fixedbytelengthintbuffer_bit_opt, test_xor_opt)
{
    FixedByteLengthIntBuffer base(lhs_multi, 2);
    int8_t *comp_ptr(reinterpret_cast<int8_t *>(&lhs_multi));
    base.bitwise_xor(comp_ptr, 2);
    EXPECT_EQ(base.GetValuePtr()[0], 0);
    EXPECT_EQ(base.GetValuePtr()[1], 0);
}