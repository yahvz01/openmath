#include <gtest/gtest.h>

#include "openmath/UnLimitedIntBuffer.hpp"

using namespace openmath;

TEST(test_class_unlimitedint_buffer_ctor, test_int8_t)
{
    int8_t value(0b0110'1001);
    UnLimitedIntBuffer buffer(value);
    
    EXPECT_EQ(buffer.GetValuePtr()[0], value);
    EXPECT_EQ(buffer.IsPositive(), true);
    EXPECT_EQ(buffer.GetBitLength(), 7);
    EXPECT_EQ(buffer.GetByteCapacity(), 1);
}

TEST(test_class_unlimitedint_buffer_ctor, test_int8_t_neg)
{
    int8_t value(0b1001'0110);
    UnLimitedIntBuffer buffer(value);
    
    EXPECT_EQ(buffer.GetValuePtr()[0], value);
    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 7);
    EXPECT_EQ(buffer.GetByteCapacity(), 1);
}

TEST(test_class_unlimitedint_buffer_ctor, test_int16_t)
{
    int16_t value(0b0110'1001'1001'0110);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>( &value ) );
    UnLimitedIntBuffer buffer(value);
    
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
    EXPECT_EQ(buffer.IsPositive(), true);
    EXPECT_EQ(buffer.GetBitLength(), 15);
    EXPECT_EQ(buffer.GetByteCapacity(), 2);
}

TEST(test_class_unlimitedint_buffer_ctor, test_int16_t_neg)
{
    int16_t value(0b1001'0110'0110'1001);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>( &value ) );
    UnLimitedIntBuffer buffer(value);
    
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 15);
    EXPECT_EQ(buffer.GetByteCapacity(), 2);
}

TEST(test_class_unlimitedint_buffer_ctor, test_int32_t)
{
    int32_t value(0b0110'1001'1001'0110'1001'0110'0110'1001);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>( &value ) );
    UnLimitedIntBuffer buffer(value);
    
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
    EXPECT_EQ(buffer.GetValuePtr()[2], comp_ptr[2]);
    EXPECT_EQ(buffer.GetValuePtr()[3], comp_ptr[3]);
    EXPECT_EQ(buffer.IsPositive(), true);
    EXPECT_EQ(buffer.GetBitLength(), 31);
    EXPECT_EQ(buffer.GetByteCapacity(), 4);
}

TEST(test_class_unlimitedint_buffer_ctor, test_int32_t_neg)
{
    int32_t value(0b1001'0110'0110'1001'0110'1001'1001'0110);
    int8_t* comp_ptr( reinterpret_cast<int8_t *>( &value ) );
    UnLimitedIntBuffer buffer(value);
    
    EXPECT_EQ(buffer.GetValuePtr()[0], comp_ptr[0]);
    EXPECT_EQ(buffer.GetValuePtr()[1], comp_ptr[1]);
    EXPECT_EQ(buffer.IsPositive(), false);
    EXPECT_EQ(buffer.GetBitLength(), 31);
    EXPECT_EQ(buffer.GetByteCapacity(), 4);
}

