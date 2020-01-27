#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

#include <iostream>
#include <bitset>


using namespace openmath;

TEST(test_method_multiply_ptr, test_int8_t)
{
    // 5 * 3
    int8_t lhs(0b0000'0101);
    int8_t rhs(0b0000'0011);
    int8_t comp(0b0000'1111);
    
    int8_t* result(nullptr);
    int16_t result_bit_length(multiply_ptr(&lhs, 1, &rhs, 1, &result, false));

    EXPECT_EQ(*result, comp);
    EXPECT_EQ(result_bit_length, 4);
    free(result);
}

TEST(test_method_multiply_ptr, test_int8_t_by_neg)
{
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);
    int16_t comp(0b1101'0100'1000'0110);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>(&comp));
    
    int8_t* result(nullptr);
    int16_t result_bit_length(multiply_ptr(&lhs, 1, &rhs, 1, &result, false));
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    EXPECT_EQ(result_bit_length, 14);
    free(result);
}


TEST(test_method_multiply_ptr, test_int16_t_neg)
{
    // 27030
    int16_t lhs(0b0110'1001'1001'0110);
    int8_t* lhs_ptr( reinterpret_cast<int8_t *>(&lhs));
    // −27031
    int16_t rhs(0b1001'0110'0110'1001);
    int8_t* rhs_ptr( reinterpret_cast<int8_t *>(&rhs));

    int8_t* result(nullptr);
    int16_t result_bit_length(multiply_ptr(lhs_ptr, 2, rhs_ptr, 2, &result, false));
    

    //           0b1101'0100'0111'0011'0011'0010'1000'0110
    //           0b1101'0100'0111'0010'0001'1010'1111'1011
    int32_t comp(0b1101'0100'0111'0011'0011'0010'1000'0110);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>(&comp) );
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    EXPECT_EQ(result[2], comp_ptr[2]);
    EXPECT_EQ(result[3], comp_ptr[3]);
    EXPECT_EQ(result_bit_length, 30);
    free(result);
}

TEST(test_method_multiply_ptr, test_int16_t_neg_double)
{
    // 27030
    int16_t lhs(0b0110'1001'1001'0110);
    int8_t* lhs_ptr( reinterpret_cast<int8_t *>(&lhs));
    // −27031
    int16_t rhs(0b1001'0110'0110'1001);
    int8_t* rhs_ptr( reinterpret_cast<int8_t *>(&rhs));

    int8_t* result(nullptr);
    int16_t result_bit_length(multiply_ptr(lhs_ptr, 2, rhs_ptr, 2, &result, false));
    

    int32_t comp(0b1101'0100'0111'0011'0011'0010'1000'0110);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>(&comp) );
    
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    EXPECT_EQ(result[2], comp_ptr[2]);
    EXPECT_EQ(result[3], comp_ptr[3]);
    EXPECT_EQ(result_bit_length, 30);
    free(result);
}

TEST(test_method_multiply_ptr, test_int8_t_multiply_by_neg)
{
    int8_t value(0b0110'1001);
    int8_t neg_one(-1); // 0b1111'1111;
    int8_t comp(0b1001'0111);

    int8_t *result(nullptr);
    int16_t result_bit_length(multiply_ptr(&value, 1, &neg_one, 1, &result, false));
    
    EXPECT_EQ(result_bit_length, 7);
    EXPECT_EQ(result[0], comp);
    free(result);
}

TEST(test_method_multiply_ptr, test_int8_t_neg_multiply_by_neg)
{
    int8_t value(0b1001'0111);
    int8_t neg_one(-1); // 0b1111'1111;
    int8_t comp(0b0110'1001);

    int8_t *result(nullptr);
    int16_t result_bit_length(multiply_ptr(&value, 1, &neg_one, 1, &result, false));
    
    EXPECT_EQ(result_bit_length, 7);
    EXPECT_EQ(result[0], comp);
    free(result);
}
