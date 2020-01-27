#include <gtest/gtest.h>

#include "openmath/UnLimitedIntBuffer.hpp"

using namespace openmath;

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);
    int8_t full_byte(0b1111'1111);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int8_t* lhs_multi_ptr( reinterpret_cast<int8_t*>(&lhs_multi) );
    int16_t rhs_multi(0b1001'0110'0110'1001);
    int8_t* rhs_multi_ptr( reinterpret_cast<int8_t*>(&rhs_multi) );

    int16_t full_byte_multi(0b1111'1111'1111'1111);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int8_t_not)
{
    UnLimitedIntBuffer lhs_obj(lhs);
    lhs_obj.bitwise_not();

    EXPECT_EQ(lhs_obj.IsPositive(), false);
    EXPECT_EQ(lhs_obj.GetBitLength(), 7);
    EXPECT_EQ(lhs_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_obj.GetValuePtr()[0], rhs);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int8_t_and)
{
    UnLimitedIntBuffer lhs_obj(lhs);
    lhs_obj.bitwise_and(&rhs, 1);

    EXPECT_EQ(lhs_obj.IsPositive(), true);
    EXPECT_EQ(lhs_obj.GetBitLength(), 0);
    EXPECT_EQ(lhs_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_obj.GetValuePtr()[0], 0);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int8_t_or)
{
    UnLimitedIntBuffer lhs_obj(lhs);
    lhs_obj.bitwise_or(&rhs, 1);

    EXPECT_EQ(lhs_obj.IsPositive(), false);
    EXPECT_EQ(lhs_obj.GetBitLength(), 1);
    EXPECT_EQ(lhs_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_obj.GetValuePtr()[0], full_byte);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int8_t_xor)
{
    UnLimitedIntBuffer lhs_obj(lhs);
    lhs_obj.bitwise_xor(&rhs, 1);

    EXPECT_EQ(lhs_obj.IsPositive(), false);
    EXPECT_EQ(lhs_obj.GetBitLength(), 1);
    EXPECT_EQ(lhs_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_obj.GetValuePtr()[0], full_byte);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int16_t_not)
{
    UnLimitedIntBuffer lhs_multi_obj(lhs_multi);
    lhs_multi_obj.bitwise_not();

    EXPECT_EQ(lhs_multi_obj.IsPositive(), false);
    EXPECT_EQ(lhs_multi_obj.GetBitLength(), 15);
    EXPECT_EQ(lhs_multi_obj.GetByteCapacity(), 2);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[0], rhs_multi_ptr[0]);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[1], rhs_multi_ptr[1]);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int16_t_and)
{
    UnLimitedIntBuffer lhs_multi_obj(lhs_multi);
    lhs_multi_obj.bitwise_and(rhs_multi_ptr, 2);

    EXPECT_EQ(lhs_multi_obj.IsPositive(), true);
    EXPECT_EQ(lhs_multi_obj.GetBitLength(), 0);
    EXPECT_EQ(lhs_multi_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[0], 0);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int16_t_or)
{
    UnLimitedIntBuffer lhs_multi_obj(lhs_multi);
    lhs_multi_obj.bitwise_or(rhs_multi_ptr, 2);

    EXPECT_EQ(lhs_multi_obj.IsPositive(), false);
    EXPECT_EQ(lhs_multi_obj.GetBitLength(), 1);
    EXPECT_EQ(lhs_multi_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[0], full_byte);
}

TEST(test_class_unlimitedintbuffer_bit_opt, test_int16_t_xor)
{
    UnLimitedIntBuffer lhs_multi_obj(lhs_multi);
    lhs_multi_obj.bitwise_xor(rhs_multi_ptr, 2);

    EXPECT_EQ(lhs_multi_obj.IsPositive(), false);
    EXPECT_EQ(lhs_multi_obj.GetBitLength(), 1);
    EXPECT_EQ(lhs_multi_obj.GetByteCapacity(), 1);
    EXPECT_EQ(lhs_multi_obj.GetValuePtr()[0], full_byte);
}