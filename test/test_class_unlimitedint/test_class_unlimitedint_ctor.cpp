#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

namespace {
    int8_t comp_value_pattern_00(0b0101'1010);
    int8_t comp_value_pattern_01(0b1111'0000);
    int8_t comp_value_pattern_02(0b0000'1111);
    int8_t comp_value_pattern_03(0b1010'0101);
}

TEST(class_UnLimitetedInt_Ctor, test_uint8_t)
{
    uint8_t test_value(0b0101'1010);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 7);
    EXPECT_EQ(test_obj.GetByteCapacity(), 1);
    EXPECT_EQ(*test_obj.GetValuePtr(), static_cast<int8_t>(test_value));
}

TEST(class_UnLimitetedInt_Ctor, test_int8_t)
{
    int8_t test_value(0b0101'1010);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 7);
    EXPECT_EQ(test_obj.GetByteCapacity(), 1);
    EXPECT_EQ(test_obj.GetValuePtr()[0], test_value);
}

TEST(class_UnLimitetedInt_Ctor, test_int16_t)
{
    int16_t test_value(0b0101'1010'1111'0000);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 15);
    EXPECT_EQ(test_obj.GetByteCapacity(), 2);
    // 1010'0110
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(comp_value_pattern_00));
}

TEST(class_UnLimitetedInt_Ctor, test_uint16_t)
{
    int16_t test_value(0b0101'1010'1111'0000);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 15);
    EXPECT_EQ(test_obj.GetByteCapacity(), 2);
    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(comp_value_pattern_00));
}

TEST(class_UnLimitetedInt_Ctor, test_int32_t)
{
    int32_t test_value(0b0101'1010'1111'0000'0000'1111'1010'0101);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 31);
    EXPECT_EQ(test_obj.GetByteCapacity(), 4);

    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(comp_value_pattern_03));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(comp_value_pattern_02));
    EXPECT_EQ(test_obj.GetValuePtr()[2], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[3], static_cast<int8_t>(comp_value_pattern_00));
}

TEST(class_UnLimitetedInt_Ctor, test_uint32_t)
{
    int32_t test_value(0b0101'1010'1111'0000'0000'1111'1010'0101);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 31);
    EXPECT_EQ(test_obj.GetByteCapacity(), 4);

    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(comp_value_pattern_03));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(comp_value_pattern_02));
    EXPECT_EQ(test_obj.GetValuePtr()[2], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[3], static_cast<int8_t>(comp_value_pattern_00));
}

TEST(class_UnLimitetedInt_Ctor, test_int64_t)
{
    int64_t test_value(0b0101'1010'1111'0000'0000'1111'1010'0101'1010'0101'0000'1111'1111'0000'0101'1010);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 63);
    EXPECT_EQ(test_obj.GetByteCapacity(), 8);

    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(comp_value_pattern_00));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[2], static_cast<int8_t>(comp_value_pattern_02));
    EXPECT_EQ(test_obj.GetValuePtr()[3], static_cast<int8_t>(comp_value_pattern_03));
    EXPECT_EQ(test_obj.GetValuePtr()[4], static_cast<int8_t>(comp_value_pattern_03));
    EXPECT_EQ(test_obj.GetValuePtr()[5], static_cast<int8_t>(comp_value_pattern_02));
    EXPECT_EQ(test_obj.GetValuePtr()[6], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[7], static_cast<int8_t>(comp_value_pattern_00));
}

TEST(class_UnLimitetedInt_Ctor, test_uint64_t)
{
    int64_t test_value(0b0101'1010'1111'0000'0000'1111'1010'0101'1010'0101'0000'1111'1111'0000'0101'1010);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 63);
    EXPECT_EQ(test_obj.GetByteCapacity(), 8);

    EXPECT_EQ(test_obj.GetValuePtr()[0], static_cast<int8_t>(comp_value_pattern_00));
    EXPECT_EQ(test_obj.GetValuePtr()[1], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[2], static_cast<int8_t>(comp_value_pattern_02));
    EXPECT_EQ(test_obj.GetValuePtr()[3], static_cast<int8_t>(comp_value_pattern_03));
    EXPECT_EQ(test_obj.GetValuePtr()[4], static_cast<int8_t>(comp_value_pattern_03));
    EXPECT_EQ(test_obj.GetValuePtr()[5], static_cast<int8_t>(comp_value_pattern_02));
    EXPECT_EQ(test_obj.GetValuePtr()[6], static_cast<int8_t>(comp_value_pattern_01));
    EXPECT_EQ(test_obj.GetValuePtr()[7], static_cast<int8_t>(comp_value_pattern_00));
}


TEST(class_UnLimitetedInt_Ctor, test_int64_t_GetBitLength)
{
    int64_t test_value(0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000);
    UnLimitedInt test_obj(test_value);
    EXPECT_EQ(test_obj.GetBitLength(), 0);
    EXPECT_EQ(test_obj.GetByteCapacity(), 1);
}