#include <gtest/gtest.h>

#include "openmath/FixedByteLengthInt.hpp"

using namespace openmath;

TEST(test_class_fixedbytelengthint_arithmetic_opt_divide, test_int8_t)
{
    FixedByteLengthInt buffer(0b0000'1101, 1);
    int8_t rhs(0b0000'0101);
    buffer = buffer / rhs;
    
    int8_t comp(0b0000'0010);
    EXPECT_EQ(buffer.GetBitLength(), 2);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}

TEST(test_class_fixedbytelengthint_arithmetic_opt_divide, test_int8_t_divide_by_zero)
{
    FixedByteLengthInt buffer(0b0000'1101, 1);
    int8_t rhs(0b0000'0000);
    EXPECT_THROW(buffer = buffer / rhs;, std::invalid_argument);
}

TEST(test_class_fixedbytelengthint_arithmetic_opt_divide, test_int32_t_dividen)
{
    FixedByteLengthInt buffer(0b0011'0011'0011'0011'0011'0011'0011'0011, 4);
    int8_t rhs(0b0000'0011);
    buffer = buffer / rhs;
    
    int32_t comp(0b0001'0001'0001'0001'0001'0001'0001'0001);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );
    EXPECT_EQ(buffer.GetBitLength(), 29);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
    EXPECT_EQ(buffer.GetValuePtr()[2], comp_ptr[2]);
    EXPECT_EQ(buffer.GetValuePtr()[3], comp_ptr[3]);
}

TEST(test_class_fixedbytelengthint_arithmetic_opt_divide, test_int32_t_non_dividen)
{
    FixedByteLengthInt buffer(0b0011'0011'0011'0011'0011'0011'0011'0100, 4);
    int8_t rhs(0b0000'0011);
    buffer = buffer / rhs;
    
    int32_t comp(0b0001'0001'0001'0001'0001'0001'0001'0001);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );
    EXPECT_EQ(buffer.GetBitLength(), 29);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
    EXPECT_EQ(buffer.GetValuePtr()[2], comp_ptr[2]);
    EXPECT_EQ(buffer.GetValuePtr()[3], comp_ptr[3]);
}