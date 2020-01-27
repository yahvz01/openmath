#include <gtest/gtest.h>
#include <cstdint>

#include "openmath/Bitwise.hpp"

#include <iostream>
#include <bitset>

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int8_t lhs_left_shift_one(0b1101'0010);
    int8_t lhs_left_shift_two(0b1010'0100);
    int8_t rhs_left_shift_one(0b0010'1100);

    int8_t lhs_right_shift_one(0b0011'0100);
    int8_t rhs_right_shift_one(0b1100'1011);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int8_t *lhs_multi_ptr(reinterpret_cast<int8_t *>(&lhs_multi));
    int16_t rhs_multi(0b1001'0110'0110'1001);
    int8_t *rhs_multi_ptr(reinterpret_cast<int8_t *>(&rhs_multi));
    
    int16_t lhs_multi_left_shift_one(0b1101'0011'0010'1100);
    int16_t lhs_multi_left_shift_sev(0b1100'1011'0000'0000);
    int16_t lhs_multi_left_shift_eig(0b1001'0110'0000'0000);
    int16_t lhs_multi_left_shift_nin(0b0010'1100'0000'0000);

    int16_t rhs_multi_left_shift_one(0b0010'1100'1101'0010);
    int16_t rhs_multi_left_shift_sev(0b0011'0100'1000'0000);
    int16_t rhs_multi_left_shift_eig(0b0110'1001'0000'0000);
    int16_t rhs_multi_left_shift_nin(0b1101'0010'0000'0000);
    
}

using namespace openmath;

TEST(test_method_bitwise_left_shift, test_single_byte_one_shift)
{
    int8_t *result = nullptr;
    left_bit_shift(&lhs, 1, 1, &result, false);
    EXPECT_EQ(*result, lhs_left_shift_one);
}

TEST(test_method_bitwise_left_shift, test_single_byte_two_shift)
{
    int8_t *result = nullptr;
    left_bit_shift(&lhs, 1, 2, &result, false);
    EXPECT_EQ(*result, lhs_left_shift_two);
}
//0110'1001'1001'0110
//1101'0011'0010'1100
//0010'1100'1101'0010

TEST(test_method_bitwise_left_shift, test_multi_bytes_pos)
{
    int8_t* result = nullptr;
    left_bit_shift(lhs_multi_ptr, 2, 1, &result, false);
    int8_t *comp_ptr(reinterpret_cast<int8_t *>(&lhs_multi_left_shift_one));
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);

    comp_ptr = reinterpret_cast<int8_t *>(&lhs_multi_left_shift_sev);
    left_bit_shift(lhs_multi_ptr, 2, 7, &result, false);
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);

    comp_ptr = reinterpret_cast<int8_t *>(&lhs_multi_left_shift_eig);
    left_bit_shift(lhs_multi_ptr, 2, 8, &result, false);
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);

    comp_ptr = reinterpret_cast<int8_t *>(&lhs_multi_left_shift_nin);
    left_bit_shift(lhs_multi_ptr, 2, 9, &result, false);
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);
}

TEST(test_method_bitwise_left_shift, test_multi_bytes_neg)
{
    int8_t* result = nullptr;
    left_bit_shift(rhs_multi_ptr, 2, 1, &result, false);
    int8_t *comp_ptr(reinterpret_cast<int8_t *>(&rhs_multi_left_shift_one));
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);

    comp_ptr = reinterpret_cast<int8_t *>(&rhs_multi_left_shift_sev);
    left_bit_shift(rhs_multi_ptr, 2, 7, &result, false);
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);

    comp_ptr = reinterpret_cast<int8_t *>(&rhs_multi_left_shift_eig);
    left_bit_shift(rhs_multi_ptr, 2, 8, &result, false);
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);

    comp_ptr = reinterpret_cast<int8_t *>(&rhs_multi_left_shift_nin);
    left_bit_shift(rhs_multi_ptr, 2, 9, &result, false);
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    free(result);
}

// Single Shift
TEST(test_method_bitwise_left_single_shift, test_int8_t)
{
    int8_t* result(nullptr);
    int16_t result_length(left_bit_single_shift(&lhs, 1, &result, false));
    EXPECT_EQ(*result, lhs_left_shift_one);
}

TEST(test_method_bitwise_left_single_shift, test_int16_t)
{
    int8_t* result(nullptr);
    int16_t result_length(left_bit_single_shift(lhs_multi_ptr, 2, &result, false));
    int8_t* comp_ptr = reinterpret_cast<int8_t *>(&lhs_multi_left_shift_one);
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
}

TEST(test_method_bitwise_left_single_shift, test_int8_t_by_neg)
{
    int8_t* result(nullptr);
    int16_t result_length(left_bit_single_shift(&rhs, 1, &result, false));
    EXPECT_EQ(*result, rhs_left_shift_one);
}

TEST(test_method_bitwise_left_single_shift, test_int16_t_by_neg)
{
    int8_t* result(nullptr);
    int16_t result_length(left_bit_single_shift(rhs_multi_ptr, 2, &result, false));
    int8_t* comp_ptr = reinterpret_cast<int8_t *>(&rhs_multi_left_shift_one);
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
}

TEST(test_method_bitwise_left_single_shift, test_int16_t_add)
{
    int16_t lhs_multi(0b0110'1001'1001'0110);
    int8_t* lhs_multi_ptr( reinterpret_cast<int8_t*>(&lhs_multi) );
    int16_t comp(0b1101'0011'0010'1100);
    int8_t* comp_ptr(reinterpret_cast<int8_t*>(&comp));
    
    int8_t* result(nullptr);
    int16_t result_length(left_bit_shift(lhs_multi_ptr, 2, 1, &result, true));
    std::cout << "result : 0b" << std::bitset<8>(result[1]) << std::bitset<8>(result[0]) << std::endl;
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
}