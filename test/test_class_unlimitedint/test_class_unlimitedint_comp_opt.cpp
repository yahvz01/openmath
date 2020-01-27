#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"

using namespace openmath;

#include <iostream>
#include <bitset>

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);
    int8_t empty_binary_value(0b0000'0000);
    int8_t full_binary_value(0b1111'1111);
    int16_t full_multi_binary_value(0b1111'1111'1111'1111);

    UnLimitedInt lhs_obj(lhs);
    UnLimitedInt rhs_obj(rhs);
    UnLimitedInt empty_obj(empty_binary_value);
    UnLimitedInt full_obj(full_binary_value);

    int16_t lhs_multi(0b0110'1001'0110'1001);
    int16_t lhs_multi_00(0b0111'1001'0110'1000);
    int16_t rhs_multi(0b1001'0110'1001'0110);
    
    UnLimitedInt lhs_obj_multi(lhs_multi);
    UnLimitedInt lhs_obj_multi_00(lhs_multi_00);
    UnLimitedInt rhs_obj_multi(rhs_multi);
    UnLimitedInt full_obj_multi(full_multi_binary_value);
}
// Comparsion between UnLimitedInts
TEST(test_class_unlimitedint_comp_opt, test_equal_with_single_bytes)
{
    EXPECT_TRUE(lhs_obj.IsPositive());
    EXPECT_FALSE(rhs_obj.IsPositive());
    EXPECT_FALSE(lhs_obj == rhs_obj);
    EXPECT_TRUE( lhs_obj == lhs_obj );
    EXPECT_TRUE(lhs_obj == lhs_obj);
}

TEST(test_class_unlimitedint_comp_opt, test_equal_with_multi_bytes)
{
    EXPECT_FALSE(lhs_obj_multi == rhs_obj_multi);
    EXPECT_TRUE(lhs_obj_multi == lhs_obj_multi);
}

TEST(test_class_unlimitedint_comp_opt, test_smaller_with_same_length)
{
    UnLimitedInt comp_obj(lhs + 1);
    EXPECT_FALSE(lhs_obj < rhs_obj);
    EXPECT_TRUE(lhs_obj < comp_obj);
}


TEST(test_class_unlimitedint_comp_opt, test_smaller_with_difference_length)
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

//TEST(test_class_unlimitedint_comp_opt, test_larger_with_same_length)
//TEST(test_class_unlimitedint_comp_opt, test_larger_with_difference_length)

// TEST(test_class_unlimitedint_comp_opt, test_smaller_and_same_with_same_length)
// TEST(test_class_unlimitedint_comp_opt, test_smaller_and_same_with_difference_length)
// 
// TEST(test_class_unlimitedint_comp_opt, test_larger_and_same_with_same_length)
// TEST(test_class_unlimitedint_comp_opt, test_larger_and_same_with_difference_length)

// Comparsion between UnLimitedInt and Basic Inter type
TEST(test_class_unlimitedint_comp_opt, test_equal_with_single_bytes_and_basic_type)
{
    EXPECT_FALSE( lhs_obj == rhs );
    EXPECT_TRUE( lhs_obj == lhs_obj );
    EXPECT_TRUE(lhs_obj == lhs_obj);
    EXPECT_TRUE( lhs_obj > 3 );
}