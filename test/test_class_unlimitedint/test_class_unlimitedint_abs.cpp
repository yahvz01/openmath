#include <gtest/gtest.h>

#include <cstdint>
#include "openmath/UnLimitedInt.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

TEST(class_unlimitedint_abs, test_int8_t_zero)
{
    // 0b0111'1111
    // 0b1000'0001
    int8_t test_value(0b0000'0000);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();

    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 0);
    EXPECT_EQ(test_obj.GetByteCapacity(), 1);
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(0));
}

TEST(class_unlimitedint_abs, test_int8_t)
{
    // 0b0111'1111
    // 0b1000'0001
    int8_t test_value(0b1111'1111);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();
    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 1);
    EXPECT_EQ(test_obj.GetByteCapacity(), 1);
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(1));
}

TEST(class_unlimitedint_abs, test_uint8_t)
{
    // 0b0111'1111
    // 0b1000'0001
    uint8_t test_value(0b1111'1111);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();
    EXPECT_TRUE(test_obj_temp.IsPositive());
    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 8);
    EXPECT_EQ(test_obj.GetByteCapacity(), 2);
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(0b1111'1111));
}

TEST(class_unlimitedint_abs, test_int8_t_neg)
{
    // 0b0111'1111
    // 0b1000'0001
    int8_t test_value(0b1111'1111);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();
    
    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 1);
    EXPECT_EQ(test_obj.GetByteCapacity(), 1);
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(0b0000'0001));
}

//TEST(class_unlimitedint_abs, test_int16_t_zero)

TEST(class_unlimitedint_abs, test_uint16_t)
{
    uint16_t test_value(0b1100'0010'0011'1010);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();
    
    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 16);
    EXPECT_EQ(test_obj.GetByteCapacity(), 3);
    
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(0b0011'1010));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(0b1100'0010));    
}


TEST(class_unlimitedint_abs, test_int16_t_pos)
{
    int16_t test_value(0b0100'0010'0011'1010);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();
    
    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 15);
    EXPECT_EQ(test_obj.GetByteCapacity(), 2);
    
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(0b0011'1010));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(0b0100'0010));    
}

//0b1100'0010'0011'1010
//0b0011'1101'1100'0110

TEST(class_unlimitedint_abs, test_int16_t_neg)
{
    int16_t test_value(0b1100'0010'0011'1010);
    UnLimitedInt test_obj_temp(test_value);
    UnLimitedInt test_obj = test_obj_temp.abs();
    
    EXPECT_TRUE(test_obj.IsPositive());
    EXPECT_EQ(test_obj.GetBitLength(), 14);
    EXPECT_EQ(test_obj.GetByteCapacity(), 2);
    
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(0b1100'0110));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(0b0011'1101));
}

// 0b0000'0000'1111'1111
// 0b0000'0000'1111'1111

// 0b1111'1111'0000'0000
// 0b1111'1111'0000'0001

// 0b0000'0000