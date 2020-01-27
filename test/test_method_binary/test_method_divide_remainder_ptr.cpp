#include <gtest/gtest.h>

#include "openmath/Binary.hpp"
#include <cstdint>

#include <iostream>
#include <bitset>


using namespace openmath;

// int8_t
TEST(method_divide_ptr, test_int8_t_pos_and_pos)
{
    int8_t lhs(0b0000'0101); // 5
    int8_t rhs(0b0000'0011); // 3

    int8_t* result_qutient(nullptr);
    int8_t* result_remainder(nullptr);
    auto result_bit_lengths(divide_remainder_ptr(&lhs, 1, &rhs, 1, &result_qutient, &result_remainder));
    
    EXPECT_EQ(result_qutient[0], static_cast<int8_t>(1) );
    EXPECT_EQ(result_bit_lengths.first, 1);

    EXPECT_EQ(result_remainder[0], static_cast<int8_t>(0b0000'0010) );
    EXPECT_EQ(result_bit_lengths.second, 2);
    free(result_qutient);
    free(result_remainder);
}

TEST(method_divide_ptr, test_int8_t_pos_and_neg)
{
    int8_t lhs(0b0000'0101); // 5
    int8_t rhs(0b1111'1101); // -3

    int8_t* result_qutient(nullptr);
    int8_t* result_remainder(nullptr);
    auto result_bit_lengths(divide_remainder_ptr(&lhs, 1, &rhs, 1, &result_qutient, &result_remainder));
    
    EXPECT_EQ(result_qutient[0], static_cast<int8_t>(0b1111'1111) );
    EXPECT_EQ(result_bit_lengths.first, 1);

    EXPECT_EQ(result_remainder[0], static_cast<int8_t>(0b0000'0010) );
    EXPECT_EQ(result_bit_lengths.second, 2);
    free(result_qutient);
    free(result_remainder);
}

TEST(method_divide_ptr, test_int8_t_neg_and_pos)
{
    int8_t lhs(0b1111'1011); // -5
    int8_t rhs(0b0000'0011); // 3

    int8_t* result_qutient(nullptr);
    int8_t* result_remainder(nullptr);
    auto result_bit_lengths(divide_remainder_ptr(&lhs, 1, &rhs, 1, &result_qutient, &result_remainder));
    
    EXPECT_EQ(result_qutient[0], static_cast<int8_t>(0b1111'1111) );
    EXPECT_EQ(result_bit_lengths.first, 1);

    EXPECT_EQ(result_remainder[0], static_cast<int8_t>(0b1111'1110) );
    EXPECT_EQ(result_bit_lengths.second, 2);
    free(result_qutient);
    free(result_remainder);
}


TEST(method_divide_remainder_ptr, test_int8_t_neg_and_neg)
{
    int8_t lhs(0b1111'1011); // -5
    int8_t rhs(0b0000'0011); // 3

    int8_t* result_qutient(nullptr);
    int8_t* result_remainder(nullptr);
    auto result_bit_lengths(divide_remainder_ptr(&lhs, 1, &rhs, 1, &result_qutient, &result_remainder));
    
    EXPECT_EQ(result_qutient[0], static_cast<int8_t>(0b1111'1111) );
    EXPECT_EQ(result_bit_lengths.first, 1);

    EXPECT_EQ(result_remainder[0], static_cast<int8_t>(0b1111'1110) );
    EXPECT_EQ(result_bit_lengths.second, 2);
    free(result_qutient);
    free(result_remainder);
}