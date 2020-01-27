#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

namespace {
    int8_t lhs_less(0b0010'0010);
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    // 0b0010'1001'1001'0110
    // 0b0010'1001'1001'0110
    // 0b0110'1001'1001'0110

    int16_t one_multi(1);
    int16_t pos_full_multi(0b0111'1111'1111'1111);

    int16_t neg_one(0b1111'1111'1111'1111);
    int16_t neg_full_multi(0b1000'0000'0000'0001);

    int16_t lhs_multi_less(0b0010'1001'1001'0110);
    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t rhs_multi(0b1001'0110'0110'1001);
}

using namespace openmath;

// negative not impl

TEST(method_carry_out_lookahead_ptr, test_single_bytes_consider_sign_bit)
{
    // pos & pos
    EXPECT_FALSE( carry_out_lookahead_ptr(&lhs_less, 1, &lhs_less, 1, true) );
    EXPECT_TRUE( carry_out_lookahead_ptr(&lhs_less, 1, &lhs, 1, true) );
    EXPECT_TRUE( carry_out_lookahead_ptr(&lhs, 1, &lhs, 1, true) );
    EXPECT_FALSE( carry_out_lookahead_ptr(&lhs, 1, &rhs, 1, true) );
    
    EXPECT_FALSE( carry_out_lookahead_ptr(&rhs, 1, &lhs, 1, true) );
    EXPECT_TRUE( carry_out_lookahead_ptr(&rhs, 1, &rhs, 1, true) );

    // neg & neg
    // pos & neg
    // neg & pos
}

TEST(method_carry_out_lookahead_ptr, test_multi_bytes_consider_sign_bit)
{
    int8_t *one_multi_ptr = reinterpret_cast<int8_t *>(&one_multi);
    int8_t *pos_full_multi_multi_ptr = reinterpret_cast<int8_t *>(&pos_full_multi);
    int8_t *lhs_multi_less_ptr = reinterpret_cast<int8_t *>(&lhs_multi_less);

    int8_t *neg_one_ptr = reinterpret_cast<int8_t *>(&neg_one);
    int8_t *neg_full_multi_ptr = reinterpret_cast<int8_t *>(&neg_full_multi);
    // pos & pos
    EXPECT_TRUE(
        carry_out_lookahead_ptr(one_multi_ptr, 2, pos_full_multi_multi_ptr, 2, true)
    );
    
    EXPECT_FALSE(
        carry_out_lookahead_ptr(lhs_multi_less_ptr, 2, lhs_multi_less_ptr, 2)
        );
    EXPECT_TRUE( carry_out_lookahead_ptr(&lhs, 1, &lhs_less, 1, true) );
    EXPECT_TRUE( carry_out_lookahead_ptr(&lhs, 1, &lhs, 1, true) );

    // pos & neg
    EXPECT_FALSE( carry_out_lookahead_ptr(&lhs, 1, &rhs, 1, true) );;
    EXPECT_FALSE( carry_out_lookahead_ptr(&rhs, 1, &lhs, 1, true) );;

    // neg & neg
    EXPECT_FALSE( carry_out_lookahead_ptr(neg_one_ptr, 2, neg_one_ptr, 2, true) );;
    EXPECT_TRUE( carry_out_lookahead_ptr(neg_one_ptr, 2, neg_full_multi_ptr, 2, true) );


    // neg & neg
    // pos & neg
    // neg & pos
}

// 0b1111'1111'1111'1111
// 0b1000'0000'0000'0001