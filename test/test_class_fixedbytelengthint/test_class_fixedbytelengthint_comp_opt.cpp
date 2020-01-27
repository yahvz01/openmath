#include <gtest/gtest.h>

#include "openmath/FixedByteLengthInt.hpp"

using namespace openmath;

#include <iostream>
#include <bitset>

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);
    int8_t empty_binary_value(0b0000'0000);
    int8_t full_binary_value(0b1111'1111);
    int16_t full_multi_binary_value(0b1111'1111'1111'1111);

    FixedByteLengthInt lhs_obj(lhs, 1);
    FixedByteLengthInt rhs_obj(rhs, 1);
    FixedByteLengthInt empty_obj(empty_binary_value);
    FixedByteLengthInt full_obj(full_binary_value);

    int16_t lhs_multi(0b0110'1001'0110'1001);
    int16_t lhs_multi_00(0b0111'1001'0110'1000);
    int16_t rhs_multi(0b1001'0110'1001'0110);
    
    FixedByteLengthInt lhs_obj_multi(lhs_multi, 2);
    FixedByteLengthInt lhs_obj_multi_00(lhs_multi_00, 2);
    FixedByteLengthInt rhs_obj_multi(rhs_multi, 2);
    FixedByteLengthInt full_obj_multi(full_multi_binary_value, 2);
}

// Comparsion between FixedByteLengthInts
TEST(test_class_fixedbytelengthint_comp_opt, test_equal_with_single_bytes)
{
    EXPECT_TRUE(lhs_obj.IsPositive());
    EXPECT_FALSE(rhs_obj.IsPositive());
    EXPECT_FALSE(lhs_obj == rhs_obj);
    EXPECT_TRUE( lhs_obj == lhs_obj );
    EXPECT_TRUE(lhs_obj == lhs_obj);
}

TEST(test_class_fixedbytelengthint_comp_opt, test_equal_with_multi_bytes)
{
    EXPECT_FALSE(lhs_obj_multi == rhs_obj_multi);
    EXPECT_TRUE(lhs_obj_multi == lhs_obj_multi);
}

TEST(test_class_fixedbytelengthint_comp_opt, test_smaller_with_same_length)
{
    FixedByteLengthInt comp_obj(lhs + 1);
    EXPECT_FALSE(lhs_obj < rhs_obj);
    EXPECT_TRUE(lhs_obj < comp_obj);
}


TEST(test_class_fixedbytelengthint_comp_opt, test_smaller_with_difference_length)
{
    // 0b1001'0110; => 0b0110'1010;
    // 0b1001'0110'1001'0110 => 0b0110'1001'0110'1010
    
    EXPECT_TRUE(lhs_obj < lhs_obj_multi);
    // lhs_multi(0b0110'1001'0110'1001);
    // lhs_multi_00(0b0111'1001'0110'1000);
    EXPECT_TRUE(lhs_obj_multi < lhs_obj_multi_00);
    EXPECT_TRUE(lhs_obj < lhs_obj_multi);
    EXPECT_TRUE(rhs_obj_multi < lhs_obj);
    EXPECT_TRUE(rhs_obj_multi < rhs_obj);
}

//TEST(test_class_fixedbytelengthint_comp_opt, test_larger_with_same_length)
//TEST(test_class_fixedbytelengthint_comp_opt, test_larger_with_difference_length)

// TEST(test_class_fixedbytelengthint_comp_opt, test_smaller_and_same_with_same_length)
// TEST(test_class_fixedbytelengthint_comp_opt, test_smaller_and_same_with_difference_length)
// 
// TEST(test_class_fixedbytelengthint_comp_opt, test_larger_and_same_with_same_length)
// TEST(test_class_fixedbytelengthint_comp_opt, test_larger_and_same_with_difference_length)

// Comparsion between FixedByteLengthInt and Basic Inter type
TEST(test_class_fixedbytelengthint_comp_opt, test_equal_with_single_bytes_and_basic_type)
{
    EXPECT_FALSE( lhs_obj == rhs );
    EXPECT_TRUE( lhs_obj == lhs_obj );
    EXPECT_TRUE(lhs_obj == lhs_obj);
    EXPECT_TRUE( lhs_obj > 3 );
}