#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t rhs_multi(0b1001'0110'0110'1001);
}

using namespace openmath;

TEST(method_is_positive_ptr, test_single_byte_pos)
{
    EXPECT_TRUE( is_positive_ptr(&lhs, 1) );
}


TEST(method_is_positive_ptr, test_single_byte_neg)
{
    EXPECT_FALSE( is_positive_ptr(&rhs, 1) );
}

TEST(method_is_positive_ptr, test_multi_byte_pos)
{
    EXPECT_TRUE( is_positive_ptr(reinterpret_cast<int8_t *>(&lhs_multi), 2) );
}

TEST(method_is_positive_ptr, test_multi_byte_neg)
{
    EXPECT_FALSE( is_positive_ptr(reinterpret_cast<int8_t *>(&rhs_multi), 2) );
}