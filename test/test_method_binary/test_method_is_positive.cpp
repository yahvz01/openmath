#include <gtest/gtest.h>

#include <cstdint>
#include "openmath/Binary.hpp"

using namespace openmath;

TEST(method_is_positive, test_int8_t)
{
    int8_t test_value_neg(-1);
    int8_t test_value_zero(0);
    int8_t test_value_pos(1);

    EXPECT_FALSE( is_positive(test_value_neg) );
    EXPECT_TRUE( is_positive(test_value_zero) );
    EXPECT_TRUE( is_positive(test_value_pos) );
}

TEST(method_is_positive, test_uint8_t)
{
    uint8_t test_value_neg(-1);
    int8_t test_value_zero(0);
    int8_t test_value_pos(1);

    EXPECT_TRUE( is_positive(test_value_neg) );
    EXPECT_TRUE( is_positive(test_value_zero) );
    EXPECT_TRUE( is_positive(test_value_pos) );
}


TEST(method_is_positive, test_int16_t)
{
    int16_t test_value_neg(-1);
    int16_t test_value_zero(0);
    int16_t test_value_pos(1);

    EXPECT_FALSE( is_positive(test_value_neg) );
    EXPECT_TRUE( is_positive(test_value_zero) );
    EXPECT_TRUE( is_positive(test_value_pos) );
}

TEST(method_is_positive, test_uint16_t)
{
    uint16_t test_value_neg(-1);
    uint16_t test_value_zero(0);
    uint16_t test_value_pos(1);

    EXPECT_TRUE( is_positive(test_value_neg) );
    EXPECT_TRUE( is_positive(test_value_zero) );
    EXPECT_TRUE( is_positive(test_value_pos) );
}

