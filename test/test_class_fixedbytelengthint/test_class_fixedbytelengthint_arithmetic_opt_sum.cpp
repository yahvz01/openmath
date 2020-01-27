#include <gtest/gtest.h>

#include "openmath/FixedByteLengthInt.hpp"

using namespace openmath;

TEST(test_class_fixbytelengthint_arithmetic_opt_sum, test_int8_t)
{
    FixedByteLengthInt buffer(0b0000'0101, 2);

    int8_t rhs(0b0000'1010);
    buffer = buffer + rhs;

    int8_t comp(0b0000'1111);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
    EXPECT_EQ(buffer.GetBitLength(), 4);
}

TEST(test_class_fixbytelengthint_arithmetic_opt_sum, test_int8_t_over_value)
{
    FixedByteLengthInt buffer(0b1111'0111, 1);

    int8_t rhs(0b0000'1001);
    buffer = buffer + rhs;

    int8_t comp(0b0000'0000);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
    EXPECT_EQ(buffer.GetBitLength(), 0);
}

TEST(test_class_fixbytelengthint_arithmetic_opt_sum, test_int8_t_over_value_over_length)
{
    FixedByteLengthInt buffer(0b1111'0111, 1);

    int16_t rhs(0b1111'1111'0000'1001);
    int8_t* rhs_ptr( reinterpret_cast<int8_t*>(&rhs) );
    buffer = buffer + rhs;

    int8_t comp(0b0000'0000);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
    EXPECT_EQ(buffer.GetBitLength(), 0);
}
