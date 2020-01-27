#include <gtest/gtest.h>

#include "openmath/UnLimitedIntBuffer.hpp"

#include <iostream>
#include <bitset>

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

using namespace openmath;

TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_left_shift_int8_t)
{
    UnLimitedIntBuffer buffer(lhs);
    buffer.bit_left_shift(1);

    int8_t comp(0b1101'0010);
    
    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 6);
    EXPECT_EQ(buffer.GetByteCapacity(), 1);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}

TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_left_shift_int8_t_neg)
{
    UnLimitedIntBuffer buffer(rhs);
    buffer.bit_left_shift(2);

    int8_t comp(0b0101'1000);
    std::cout << buffer.GetValuePtr()[3] << std::endl;
    
    EXPECT_EQ(buffer.IsPositive(), true);
    EXPECT_EQ(buffer.GetBitLength(), 7);
    EXPECT_EQ(buffer.GetByteCapacity(), 1);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}


TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_right_shift_int8_t)
{
    UnLimitedIntBuffer buffer(lhs);
    buffer.bit_right_shift(1);
    int8_t comp(0b0011'0100);
    
    EXPECT_EQ(buffer.IsPositive(), true);
    EXPECT_EQ(buffer.GetBitLength(), 6);
    EXPECT_EQ(buffer.GetByteCapacity(), 1);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}


TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_right_shift_int8_t_neg)
{
    UnLimitedIntBuffer buffer(rhs);
    buffer.bit_right_shift(2);
    int8_t comp(0b1110'0101);
    
    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 5);
    EXPECT_EQ(buffer.GetByteCapacity(), 1);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp);
}


TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_left_shift_int16_t)
{
    UnLimitedIntBuffer buffer(lhs_multi);
    std::cout << "Values_Length:Out : " << buffer.GetBitLength() << std::endl;
    buffer.bit_left_shift(1);
    //           0b0110'0010'0011'0000
    //           0b1101'0011'0010'1100
    int16_t comp(0b1101'0011'0010'1100);
    int8_t* comp_ptr(reinterpret_cast<int8_t*>(&comp));

    
    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 14);
    EXPECT_EQ(buffer.GetByteCapacity(), 2);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
}

TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_left_shift_int16_t_neg)
{
    UnLimitedIntBuffer buffer(lhs_multi);
    buffer.bit_left_shift(2);

    int16_t comp(0b1010'0110'0101'1000);
    int8_t* comp_ptr(reinterpret_cast<int8_t*>(&comp));

    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 15);
    EXPECT_EQ(buffer.GetByteCapacity(), 2);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);

}
TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_right_shift_int16_t)
{
    UnLimitedIntBuffer buffer(rhs_multi);
    buffer.bit_right_shift(1);

    int16_t comp(0b1100'1011'0011'0100);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );

    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 14);
    EXPECT_EQ(buffer.GetByteCapacity(), 2);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
}
TEST(test_class_unlimitedintbuffer_bit_shift_opt, test_right_shift_int16_t_neg)
{
    UnLimitedIntBuffer buffer(rhs_multi);
    buffer.bit_right_shift(2);

    int16_t comp(0b1110'0101'1001'1010);
    int8_t* comp_ptr( reinterpret_cast<int8_t*>(&comp) );

    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 13);
    EXPECT_EQ(buffer.GetByteCapacity(), 2);
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
}