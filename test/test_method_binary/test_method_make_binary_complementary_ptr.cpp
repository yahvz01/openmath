#include <gtest/gtest.h>

#include "openmath/Binary.hpp"
#include <cstdint>
#include <cstdlib>

#include <iostream>
#include <bitset>


using namespace openmath;

TEST(method_make_binary_complementary_ptr_version, test_uint8_t)
{
    int8_t value(0b0000'0001);
    int8_t *value_ptr = &value;
    int8_t* result = make_binary_complement_ptr(value_ptr, 1);
    EXPECT_EQ(static_cast<uint8_t>(*result), 0b1111'1111);
    free(result);
    result = nullptr;
}

TEST(method_make_binary_complementary_ptr_version, test_int8_t)
{
    int8_t value(0b1111'1111);
    int8_t *value_ptr = &value;
    int8_t* result = make_binary_complement_ptr(value_ptr, 1);
    EXPECT_EQ(*result, static_cast<int8_t>(0b0000'0001));
    free(result);
    result = nullptr;
}

TEST(method_make_binary_complementary_ptr_version, test_uint16_t)
{
    
    // error
    uint16_t value(0b0000'0010'0000'0100);
    //int16_t comp_value(0b1111'1101'1111'1100);

    int8_t *value_ptr = reinterpret_cast<int8_t *>(&value);

    
    auto value_ptr_ptr00 = &value_ptr[0];
    auto value_ptr_ptr01 = &value_ptr[1];

    int8_t* result = make_binary_complement_ptr(value_ptr, 2);
    EXPECT_EQ(static_cast<uint8_t>(result[0]), 0b1111'1100);
    EXPECT_EQ(static_cast<uint8_t>(result[1]), 0b1111'1101);
    free(result);
    result = nullptr;
}

TEST(method_make_binary_complementary_ptr_version, test_int16_t)
{
    int16_t value(0b0000'0010'0000'0100);
    //int16_t comp_value(0b1111'1101'1111'1100);

    int8_t *value_ptr = reinterpret_cast<int8_t *>(&value);

    auto value_ptr_ptr00 = &value_ptr[0];
    auto value_ptr_ptr01 = &value_ptr[1];

    int8_t* result = make_binary_complement_ptr(value_ptr, 2);
    EXPECT_EQ(static_cast<uint8_t>(result[0]), 0b1111'1100);
    EXPECT_EQ(static_cast<uint8_t>(result[1]), 0b1111'1101);
    free(result);
    result = nullptr;
}

//0000000110100000
//1111111001100000
//1111111001100000