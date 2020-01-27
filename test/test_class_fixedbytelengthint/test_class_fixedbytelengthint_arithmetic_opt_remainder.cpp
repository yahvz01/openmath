#include <gtest/gtest.h>

#include "openmath/FixedByteLengthInt.hpp"

using namespace openmath;

TEST(test_class_rixedbytelengthint_arithmetic_opt_remainder, test_int8_t)
{
    FixedByteLengthInt buffer(0b0000'1101, 1);
    int8_t rhs(0b0000'0101);
    buffer = buffer % rhs;
    
    int8_t comp(0b0000'0011);
    EXPECT_EQ(buffer.GetBitLength(), 2);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}

TEST(test_class_rixedbytelengthint_arithmetic_opt_remainder, test_int8_t_remainder_by_zero)
{
    FixedByteLengthInt buffer(0b0000'1101, 1);
    int8_t rhs(0b0000'0000);
    EXPECT_THROW(buffer = buffer % rhs;, std::invalid_argument);
}

TEST(test_class_rixedbytelengthint_arithmetic_opt_remainder, test_int32_t_remainder_dividen)
{
    FixedByteLengthInt buffer(0b0011'0011'0011'0011'0011'0011'0011'0011, 4);
    int8_t rhs(0b0000'0011);
    buffer = buffer % rhs;
    EXPECT_EQ(buffer.GetBitLength(), 0);
    EXPECT_EQ(buffer.GetValuePtr()[0], 0);
}

TEST(test_class_rixedbytelengthint_arithmetic_opt_remainder, test_int32_t_remainder_non_dividen)
{
    FixedByteLengthInt buffer(0b0011'0011'0011'0011'0011'0011'0011'0100, 4);
    int8_t rhs(0b0000'0011);
    buffer = buffer % rhs;
    EXPECT_EQ(buffer.GetBitLength(), 1);
    EXPECT_EQ(buffer.GetValuePtr()[0], 1);
}