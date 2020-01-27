#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

#include <iostream>
#include <bitset>


using namespace openmath;


namespace {
    int8_t single_one(0b0000'0010);
    int8_t single_pos(0b0110'1001);
    int8_t single_pos_shift_left(0b1101'0010);
    int8_t single_neg(0b1001'0110);

    int16_t multi_pos(0b0110'1001'1001'0110);
    int16_t multi_neg(0b1001'0110'0110'1001);
    int8_t *multi_pos_ptr = reinterpret_cast<int8_t *>(&multi_pos);
    int8_t *multi_neg_ptr = reinterpret_cast<int8_t *>(&multi_neg);

    int32_t multi_pos_shift_left(0b0000'0000'1101'0011'0010'1100);
    int32_t multi_neg_shift_left(0b1111'1111'0010'1100'1101'0010);

    int8_t *multi_pos_shift_left_ptr = reinterpret_cast<int8_t *>(&multi_pos_shift_left);
    int8_t *multi_neg_shift_left_ptr = reinterpret_cast<int8_t *>(&multi_neg_shift_left);

}

// do_shrink
TEST(method_adder_ptr, test_single_byte_pos_and_pos)
{
    //0110'1001
    //0110'1001
    //1101'0010
    int8_t *result;
    
    int16_t bit_length = adder_ptr(&single_pos, 1, &single_pos, 1, &result, false, false);
    
    EXPECT_EQ(bit_length, 8);
    EXPECT_EQ(result[0], single_pos_shift_left);
    EXPECT_EQ(result[1], 0);
    free(result);
}

TEST(method_adder_ptr, test_single_byte_pos_and_neg)
{
    int8_t *result;
    int bit_length = adder_ptr(&single_pos, 1, &single_neg, 1, &result, false, false);
    
    EXPECT_EQ(bit_length, 1);
    EXPECT_EQ(result[0], static_cast<int8_t>(0b1111'1111));
    free(result);
}

//TEST(method_adder_ptr, test_single_byte_neg_and_pos);
TEST(method_adder_ptr, test_single_byte_neg_and_neg)
{
    int8_t *result;
    int bit_length = adder_ptr(&single_neg, 1, &single_neg, 1, &result, false, false);

    EXPECT_EQ(bit_length, 8);
    EXPECT_EQ(result[0], static_cast<int8_t>(0b0010'1100));
    EXPECT_EQ(result[1], static_cast<int8_t>(0b1111'1111));
    free(result);
}

TEST(method_adder_ptr, test_multi_byte_pos_and_pos)
{
    int8_t *result;
    int bit_length = adder_ptr(multi_pos_ptr, 2, multi_pos_ptr, 2, &result, false, false);
    
    EXPECT_EQ(bit_length, 16);
    EXPECT_EQ(result[0], multi_pos_shift_left_ptr[0]);
    EXPECT_EQ(result[1], multi_pos_shift_left_ptr[1]);
    EXPECT_EQ(result[2], multi_pos_shift_left_ptr[2]);
    
    free(result);
}

//TEST(method_adder_ptr, test_multi_byte_pos_and_neg);
//TEST(method_adder_ptr, test_multi_byte_neg_and_pos);
TEST(method_adder_ptr, test_multi_byte_neg_and_neg)
{
    int8_t *result;
    int bit_length = adder_ptr(multi_neg_ptr, 2, multi_neg_ptr, 2, &result, false, false);

    EXPECT_EQ(bit_length, 16);
    EXPECT_EQ(result[0], static_cast<int8_t>(multi_neg_shift_left_ptr[0]));
    EXPECT_EQ(result[1], static_cast<int8_t>(multi_neg_shift_left_ptr[1]));
    EXPECT_EQ(result[2], static_cast<int8_t>(multi_neg_shift_left_ptr[2]));
    free(result);
}

//TEST(method_half_adder_ptr, test_diff_byte_pos_and_pos);
//TEST(method_half_adder_ptr, test_diff_byte_pos_and_neg);
//TEST(method_half_adder_ptr, test_diff_byte_neg_and_pos);
//TEST(method_half_adder_ptr, test_diff_byte_neg_and_neg);

// not do_shrink

TEST(method_adder_ptr, test_single_byte_pos_and_pos_not_shrink)
{
    //0110'1001
    //0110'1001
    //1101'0010
    int8_t *result;
    
    int16_t bit_length = adder_ptr(&single_pos, 1, &single_pos, 1, &result, false, false);
    
    EXPECT_EQ(bit_length, 8);
    EXPECT_EQ(result[0], single_pos_shift_left);
    EXPECT_EQ(result[1], 0);
    free(result);
}

TEST(method_adder_ptr, test_single_byte_pos_and_neg_not_shrink)
{
    int8_t *result;
    int bit_length = adder_ptr(&single_pos, 1, &single_neg, 1, &result, false, false);
    
    EXPECT_EQ(bit_length, 1);
    EXPECT_EQ(result[0], static_cast<int8_t>(0b1111'1111));
    free(result);
}

// do_fixed_byte_by_max_byte

TEST(method_adder_ptr, test_multi_byte_pos_and_pos_not_shrink)
{
    int8_t *result;
    int bit_length = adder_ptr(multi_pos_ptr, 2, multi_pos_ptr, 2, &result, true, false);
    
    EXPECT_EQ(bit_length, 14);
    EXPECT_EQ(result[0], multi_pos_shift_left_ptr[0]);
    EXPECT_EQ(result[1], multi_pos_shift_left_ptr[1]);
    //EXPECT_EQ(result[2], multi_pos_shift_left_ptr[2]);
    
    free(result);
}

//TEST(method_adder_ptr, test_multi_byte_pos_and_neg);
//TEST(method_adder_ptr, test_multi_byte_neg_and_pos);
TEST(method_adder_ptr, test_multi_byte_neg_and_neg_not_shrink)
{
    int8_t *result;
    int bit_length = adder_ptr(multi_neg_ptr, 2, multi_neg_ptr, 2, &result, true, false);

    EXPECT_EQ(bit_length, 14);
    EXPECT_EQ(result[0], static_cast<int8_t>(multi_neg_shift_left_ptr[0]));
    EXPECT_EQ(result[1], static_cast<int8_t>(multi_neg_shift_left_ptr[1]));
    //EXPECT_EQ(result[2], static_cast<int8_t>(multi_neg_shift_left_ptr[2]));
    free(result);
}