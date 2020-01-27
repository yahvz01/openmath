#include <gtest/gtest.h>

#include "openmath/FixedByteLengthIntBuffer.hpp"
#include "openmath/Binary.hpp"

using namespace openmath;

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t rhs_multi(0b1001'0110'0110'1001);

    int16_t lhs_bit_length( get_digit_binary_number(lhs) );
    int16_t rhs_bit_length( get_digit_binary_number(rhs) );

    int16_t lhs_multi_bit_length( get_digit_binary_number(lhs_multi) );
    int16_t rhs_multi_bit_length( get_digit_binary_number(rhs_multi) );
}

TEST(class_fixedbytelengthintbuffer_ctor, test_int8_t_pos)
{
    FixedByteLengthIntBuffer result(lhs, 1);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs);
    EXPECT_EQ(result.GetBitLength(), lhs_bit_length);
}

TEST(class_fixedbytelengthintbuffer_ctor, test_int8_t_pos_and_set_multi_bytes)
{
    FixedByteLengthIntBuffer result(lhs, 2);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs);
    EXPECT_EQ(result.GetValuePtr()[1], 0b0000'0000);
    EXPECT_EQ(result.GetBitLength(), lhs_bit_length);
}

TEST(class_fixedbytelengthintbuffer_ctor, test_int8_t_neg)
{
    FixedByteLengthIntBuffer result(rhs, 1);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], rhs);
    EXPECT_EQ(result.GetBitLength(), rhs_bit_length);
}

TEST(class_fixedbytelengthintbuffer_ctor, test_int8_t_neg_set_multi_bytes)
{
    FixedByteLengthIntBuffer result(rhs, 2);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], rhs);
    EXPECT_EQ(result.GetValuePtr()[1], static_cast<int8_t>(0b1111'1111));
    EXPECT_EQ(result.GetBitLength(), rhs_bit_length);
}

TEST(test_class_fixedlengthint_buffer_ctor, test_int16_t_pos)
{
    FixedByteLengthIntBuffer result(lhs_multi, 2);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], rhs);
    EXPECT_EQ(result.GetValuePtr()[1], lhs);
    EXPECT_EQ(result.GetBitLength(), lhs_multi_bit_length);
}

TEST(test_class_fixedlengthint_buffer_ctor, test_int16_t_pos_set_single_byte)
{
    FixedByteLengthIntBuffer result(lhs_multi, 1);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], rhs);
    EXPECT_EQ(result.GetBitLength(), rhs_bit_length);
}

TEST(test_class_fixedlengthint_buffer_ctor, test_int16_t_neg)
{
    FixedByteLengthIntBuffer result(rhs_multi, 2);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs);
    EXPECT_EQ(result.GetValuePtr()[1], rhs);
    EXPECT_EQ(result.GetBitLength(), rhs_multi_bit_length);
}

TEST(test_class_fixedlengthint_buffer_ctor, test_int16_t_neg_set_single_byte)
{
    FixedByteLengthIntBuffer result(rhs_multi, 1);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs);
    EXPECT_EQ(result.GetBitLength(), rhs_bit_length);
}