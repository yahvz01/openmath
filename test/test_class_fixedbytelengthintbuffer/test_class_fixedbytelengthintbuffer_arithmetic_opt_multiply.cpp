#include <gtest/gtest.h>

#include "openmath/FixedByteLengthIntBuffer.hpp"

using namespace openmath;

TEST(test_class_fixedbytelengthintbuffer_arithmetic_opt_multiply, test_int8_t)
{
    FixedByteLengthIntBuffer buffer(0b0000'0101, 1);
    int8_t rhs(0b0000'1001);
    buffer.multiply(&rhs, 1);

    int8_t comp(0b0010'1101);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}

TEST(test_class_fixedbytelengthintbuffer_arithmetic_opt_multiply, test_int8_t_pos_and_neg)
{
    FixedByteLengthIntBuffer buffer(0b0000'0101, 1);
    int8_t rhs(0b1111'0111);
    buffer.multiply(&rhs, 1);

    int8_t comp(0b1101'0011);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}

TEST(test_class_fixedbytelengthintbuffer_arithmetic_opt_multiply, test_int8_t_pos_and_neg_Test)
{
    FixedByteLengthIntBuffer buffer(0b0111'1111'1111'1111, 2);
    int8_t rhs(0);
    buffer.multiply(&rhs, 1);
    int8_t comp(0);
    EXPECT_EQ(buffer.GetBitLength(), 0);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}




