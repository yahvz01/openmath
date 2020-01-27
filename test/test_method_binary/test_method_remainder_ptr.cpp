#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

using namespace openmath;

TEST(test_method_remainder_ptr, test_int8_t_by_pos_and_pos)
{
    int8_t lhs(0b0000'0101);
    int8_t rhs(0b0000'0011);

    int8_t* result(nullptr);
    int16_t result_bit_length(remainder_ptr(&lhs, 1, &rhs, 1, &result));
    
    EXPECT_EQ(result[0], static_cast<int8_t>(0b0000'0010));
    EXPECT_EQ(result_bit_length, 2);
}

TEST(method_divide_ptr, test_int32_t_not_dividen)
{
    int32_t lhs(0b0011'0011'0011'0011'0011'0011'0011'0100);
    int8_t* lhs_ptr( reinterpret_cast<int8_t*>(&lhs) );
    int8_t rhs(0b0000'0011);
    int8_t comp(0b0000'0001);

    int8_t* result(nullptr);
    int16_t result_bit_length(remainder_ptr(lhs_ptr, 4, &rhs, 1, &result));

    EXPECT_EQ(result[0], comp);
    EXPECT_EQ(result_bit_length, 1);
    free(result);
}

TEST(method_divide_ptr, test_int32_t_dividen)
{
    int32_t lhs(0b0011'0011'0011'0011'0011'0011'0011'0011);
    int8_t* lhs_ptr( reinterpret_cast<int8_t*>(&lhs) );
    int8_t rhs(0b0000'0011);
    int8_t comp(0b0000'0000);

    int8_t* result(nullptr);
    int16_t result_bit_length(remainder_ptr(lhs_ptr, 4, &rhs, 1, &result));

    EXPECT_EQ(result[0], comp);
    EXPECT_EQ(result_bit_length, 0);
    free(result);
}
