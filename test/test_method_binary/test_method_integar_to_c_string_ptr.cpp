#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

#include <cstdlib>
#include <iostream>
#include <bitset>

using namespace openmath;

TEST(test_test_method_integar_to_c_string_ptr, test_int8_t)
{
    int8_t value(3);
    char *value_str(integar_to_c_string_ptr(&value, 1));
    EXPECT_EQ(value_str[0], '3');
    free(value_str);
}
TEST(test_test_method_integar_to_c_string_ptr, test_int8_t_sec)
{
    int8_t value(23);
    char *value_str(integar_to_c_string_ptr(&value, 1));
    EXPECT_EQ(value_str[0], '2');
    EXPECT_EQ(value_str[1], '3');
    free(value_str);
}

TEST(test_test_method_integar_to_c_string_ptr, test_int16_t)
{
    int16_t value(333);
    char *value_str(integar_to_c_string_ptr(reinterpret_cast<int8_t*>(&value), 2));
    EXPECT_EQ(value_str[0], '3');
    EXPECT_EQ(value_str[1], '3');
    EXPECT_EQ(value_str[2], '3');
    free(value_str);
}

TEST(test_test_method_integar_to_c_string_ptr, test_int16_t_3_digits)
{
    int16_t value(300);
    char *value_str(integar_to_c_string_ptr(reinterpret_cast<int8_t*>(&value), 2));
    EXPECT_EQ(value_str[0], '3');
    EXPECT_EQ(value_str[1], '0');
    EXPECT_EQ(value_str[2], '0');
    free(value_str);
}
TEST(test_test_method_integar_to_c_string_ptr, test_int8_t_neg)
{
    int8_t value(-3);
    char *value_str(integar_to_c_string_ptr(&value, 1));
    EXPECT_EQ(value_str[0], '-');
    EXPECT_EQ(value_str[1], '3');
    free(value_str);
}

TEST(test_test_method_integar_to_c_string_ptr, test_int16_t_neg)
{
    int16_t value(-333);
    char *value_str(integar_to_c_string_ptr(reinterpret_cast<int8_t*>(&value), 2));
    EXPECT_EQ(value_str[0], '-');
    EXPECT_EQ(value_str[1], '3');
    EXPECT_EQ(value_str[2], '3');
    EXPECT_EQ(value_str[3], '3');
    free(value_str);
}

// qutient
// remainder
// error