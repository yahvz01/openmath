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

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(&lhs, 1, &rhs, 1, &result));

    EXPECT_EQ(result[0], static_cast<int8_t>(1) );
    EXPECT_EQ(result_bit_length, 1);
    free(result);
}


TEST(method_divide_ptr, test_int8_t_pos_and_pos_sec)
{
    int8_t lhs(0b0000'1101);
    int8_t rhs(0b0000'0101);

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(&lhs, 1, &rhs, 1, &result));

    EXPECT_EQ(result[0], static_cast<int8_t>(2) );
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}


TEST(method_divide_ptr, test_int8_t_pos_and_neg)
{
    int8_t lhs(0b0000'1101); // 13
    int8_t rhs(0b1111'1011); // -5

    int8_t comp(0b1111'1110); // -2
    int8_t* result(nullptr);
    int16_t result_bit_length( divide_ptr(&lhs, 1,&rhs, 1, &result) );
    EXPECT_EQ(result[0], comp);
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}

TEST(method_divide_ptr, test_int8_t_pos_and_neg_dividen)
{
    int8_t lhs(0b0000'1111); // 15
    int8_t rhs(0b1111'1011); // -5

    int8_t comp(0b1111'1101);
    int8_t* result(nullptr);
    int16_t result_bit_length( divide_ptr(&lhs, 1,&rhs, 1, &result) );
    EXPECT_EQ(result[0], comp);
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}

// problem - neg - pos
TEST(method_divide_ptr, test_int8_t_neg_and_pos_dividen)
{
    int8_t lhs(0b1111'0001); // -15
    int8_t rhs(0b0000'0101); // 5

    int8_t comp(0b1111'1101); // -3
    int8_t* result(nullptr);
    int16_t result_bit_length( divide_ptr(&lhs, 1,&rhs, 1, &result) );
    EXPECT_EQ(result[0], comp);
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}


TEST(method_divide_ptr, test_int8_t_neg_and_neg_dividen)
{
    int8_t lhs(0b1111'0001); // -15
    int8_t rhs(0b0000'0101); // 5

    int8_t comp(0b1111'1101); // -3
    int8_t* result(nullptr);
    int16_t result_bit_length( divide_ptr(&lhs, 1,&rhs, 1, &result) );
    EXPECT_EQ(result[0], comp);
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}


TEST(method_divide_ptr, test_int16_t_pos_and_pos)
{
    int16_t lhs(0b0011'0011'0011'0011);
    int8_t *lhs_ptr( reinterpret_cast<int8_t*>(&lhs));
    int16_t rhs(0b0000'0000'0000'0011);
    int8_t *rhs_ptr( reinterpret_cast<int8_t*>(&rhs));

    int16_t comp(0b0001'0001'0001'0001);
    int8_t *comp_ptr( reinterpret_cast<int8_t*>(&comp));

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 2, rhs_ptr, 2, &result));
    EXPECT_EQ(result[0], comp_ptr[0] );
    EXPECT_EQ(result[1], comp_ptr[1] );
    EXPECT_EQ(result_bit_length, 13);
    free(result);
}

TEST(method_divide_ptr, test_int8_t_pos_and_neg_sec)
{
    int8_t lhs(0b0000'0101);
    int8_t rhs(0b1111'1101);
    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(&lhs, 1, &rhs, 1, &result));
    EXPECT_EQ(result[0], static_cast<int8_t>(0b1111'1111) );
    EXPECT_EQ(result_bit_length, 1);
    free(result);
}

TEST(method_divide_ptr, test_int8_t_pos_and_neg_sec_sec)
{
    int8_t lhs(0b0000'1101);
    int8_t rhs(0b1111'1011);

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(&lhs, 1, &rhs, 1, &result));
    std::cout << std::bitset<8>( result[0] ) << std::endl;
    EXPECT_EQ(result[0], static_cast<int8_t>(0b1111'1110) );
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}

TEST(method_divide_ptr, test_int16_t_pos_and_neg)
{
    int16_t lhs(0b0011'0011'0011'0011);
    int8_t *lhs_ptr( reinterpret_cast<int8_t*>(&lhs));
    int16_t rhs(0b1111'1111'1111'1101);
    int8_t *rhs_ptr( reinterpret_cast<int8_t*>(&rhs));

    int16_t comp(0b1110'1110'1110'1111);
    int8_t *comp_ptr( reinterpret_cast<int8_t*>(&comp));

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 2, rhs_ptr, 2, &result));
    
    EXPECT_EQ(result[0], comp_ptr[0] );
    EXPECT_EQ(result[1], comp_ptr[1] );
    EXPECT_EQ(result_bit_length, 13);
    free(result);
}


TEST(method_divide_ptr, test_int16_t_neg_and_pos)
{
    //13107
    int16_t lhs(0b1100'1100'1100'1101);
    int8_t *lhs_ptr( reinterpret_cast<int8_t*>(&lhs));
    int16_t rhs(0b0000'0000'0000'0011);
    int8_t *rhs_ptr( reinterpret_cast<int8_t*>(&rhs));

    int16_t comp(0b1110'1110'1110'1111);
    int8_t *comp_ptr( reinterpret_cast<int8_t*>(&comp));

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 2, rhs_ptr, 2, &result));
    
    EXPECT_EQ(result[0], comp_ptr[0] );
    EXPECT_EQ(result[1], comp_ptr[1] );
    EXPECT_EQ(result_bit_length, 13);
    free(result);
}

// Crime scene
TEST(method_divide_ptr, test_int8_t_neg_and_pos)
{
    //13107
    int8_t lhs(0b1111'0011);
    int8_t rhs(0b0000'0101);

    int8_t comp(0b1111'1110);

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(&lhs, 1, &rhs, 1, &result));
    EXPECT_EQ(result[0], comp );
    EXPECT_EQ(result_bit_length, 2);
    free(result);
}


TEST(method_divide_ptr, test_int8_t_neg_and_neg)
{
    
    int16_t lhs(0b1100'1101);
    int8_t *lhs_ptr( reinterpret_cast<int8_t*>(&lhs));
    int16_t rhs(0b1111'1101);
    int8_t *rhs_ptr( reinterpret_cast<int8_t*>(&rhs));

    int16_t comp(0b0001'0001);
    int8_t *comp_ptr( reinterpret_cast<int8_t*>(&comp));

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 1, rhs_ptr, 1, &result));
    
    EXPECT_EQ(result[0], comp_ptr[0] );
    EXPECT_EQ(result_bit_length, 5);
    free(result);
}


TEST(method_divide_ptr, test_int16_t_neg_and_neg)
{
    
    int16_t lhs(0b1100'1100'1100'1101);
    int8_t *lhs_ptr( reinterpret_cast<int8_t*>(&lhs));
    int16_t rhs(0b1111'1111'1111'1101);
    int8_t *rhs_ptr( reinterpret_cast<int8_t*>(&rhs));

    int16_t comp(0b0001'0001'0001'0001);
    int8_t *comp_ptr( reinterpret_cast<int8_t*>(&comp));

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 2, rhs_ptr, 2, &result));
  
    EXPECT_EQ(result[0], comp_ptr[0] );
    EXPECT_EQ(result[1], comp_ptr[1] );
    EXPECT_EQ(result_bit_length, 13);
    free(result);
}


TEST(method_divide_ptr, test_int16_t_non_dividen)
{
    int16_t lhs(0b0011'0011'0011'0100);
    int8_t* lhs_ptr( reinterpret_cast<int8_t*>(&lhs) );
    int16_t rhs(0b0000'0000'0000'0011);
    int8_t* rhs_ptr( reinterpret_cast<int8_t*>(&rhs) );
    int16_t comp(0b0001'0001'0001'0001);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 2, rhs_ptr, 1, &result));
    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    EXPECT_EQ(result_bit_length, 13);
    free(result);
}


TEST(method_divide_ptr, test_int32_t_not_dividen)
{
    int32_t lhs(0b0011'0011'0011'0011'0011'0011'0011'0100);
    int8_t* lhs_ptr( reinterpret_cast<int8_t*>(&lhs) );
    int8_t rhs(0b0000'0011);
    int32_t comp(0b0001'0001'0001'0001'0001'0001'0001'0001);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 4, &rhs, 1, &result));

    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    EXPECT_EQ(result[2], comp_ptr[2]);
    EXPECT_EQ(result[3], comp_ptr[3]);
    EXPECT_EQ(result_bit_length, 29);
    free(result);
}

TEST(method_divide_ptr, test_int32_t_dividen)
{
    int32_t lhs(0b0011'0011'0011'0011'0011'0011'0011'0011);
    int8_t* lhs_ptr( reinterpret_cast<int8_t*>(&lhs) );
    int8_t rhs(0b0000'0011);
    int32_t comp(0b0001'0001'0001'0001'0001'0001'0001'0001);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );

    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(lhs_ptr, 4, &rhs, 1, &result));

    EXPECT_EQ(result[0], comp_ptr[0]);
    EXPECT_EQ(result[1], comp_ptr[1]);
    EXPECT_EQ(result[2], comp_ptr[2]);
    EXPECT_EQ(result[3], comp_ptr[3]);
    EXPECT_EQ(result_bit_length, 29);
    free(result);
}

/*
   중복된 테스트를 동시에수행했을 경우에 메모리 침범이 일어
 */

TEST(method_divide_ptr, test_int8_t_pos_and_pos_error_test)
{
    int8_t lhs(0b0000'0011);
    int8_t rhs(0b0000'1010);

    int8_t* result_qutient(nullptr);
    auto result_bit_length(divide_ptr(&lhs, 1, &rhs, 1, &result_qutient));
    
    EXPECT_EQ(result_qutient[0], static_cast<int8_t>(0));
    EXPECT_EQ(result_bit_length, 0);

    free(result_qutient);
}