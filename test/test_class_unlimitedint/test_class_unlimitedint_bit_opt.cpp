#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"

/*
 *  test bit operation ( not / and / or / xor )
 *  single byte / multibyte
 */

#include <iostream>
#include <bitset>

using namespace openmath;


namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);
    int8_t empty_binary_value(0b0000'0000);
    int8_t full_binary_value(0b1111'1111);
    int16_t full_multi_binary_value(0b1111'1111'1111'1111);

    UnLimitedInt lhs_obj(lhs);
    UnLimitedInt rhs_obj(rhs);
    UnLimitedInt empty_obj(empty_binary_value);
    UnLimitedInt full_obj(full_binary_value);

    int16_t lhs_multi(0b0110'1001'0110'1001);
    int16_t rhs_multi(0b1001'0110'1001'0110);
    
    UnLimitedInt lhs_obj_multi(lhs_multi);
    UnLimitedInt rhs_obj_multi(rhs_multi);
    UnLimitedInt full_obj_multi(full_multi_binary_value);
}
void bit_check(const UnLimitedInt& lhs, const UnLimitedInt& rhs, uint16_t byte_length);

// Unary Bit Operation

TEST(test_class_unlimitedint_bit_opt, test_not_opt_one_byte_by_pos)
{
    // 0b0'0110'1001
    // 0b1'1001'0110
    
    auto result = ~lhs_obj;
    EXPECT_FALSE(result.IsPositive());
    //EXPECT_EQ(result, rhs_obj);
    EXPECT_EQ(result.GetBitLength(), 7);
    EXPECT_EQ(result.GetByteCapacity(), 1);
}

TEST(test_class_unlimitedint_bit_opt, test_not_opt_one_byte_by_neg)
{
    // 0b1'1001'0110
    // 0b0'0110'1001
    auto result = ~rhs_obj;
    EXPECT_TRUE(result.IsPositive());
    
    EXPECT_EQ(result.GetBitLength(), 7);
    EXPECT_EQ(result.GetByteCapacity(), 1);
}


TEST(test_class_unlimitedint_bit_opt, test_not_opt_multi_byte_by_pos)
{
    // 0b0110'1001'0110'1001
    // 0b1001'0110'1001'0110
    auto result = ~lhs_obj_multi;
    EXPECT_FALSE(result.IsPositive());
    bit_check(result, rhs_obj_multi, result.GetByteCapacity());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(lhs_obj_multi.GetByteCapacity(), 2);
    EXPECT_EQ(result.GetByteCapacity(), 2);
}

TEST(test_class_unlimitedint_bit_opt, test_not_opt_multi_byte_by_neg)
{
    // 0b0'1001'0110'1001'0110
    // 0b0'0110'1001'0110'1001

    auto result = ~rhs_obj_multi;
    EXPECT_TRUE(result.IsPositive());
    bit_check(result, lhs_obj_multi, result.GetByteCapacity());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(lhs_obj_multi.GetByteCapacity(), 2);
    EXPECT_EQ(result.GetByteCapacity(), 2);
}



// Binary Operation 
TEST(test_class_unlimitedint_bit_opt, test_and_opt_one_byte)
{
    // lhs(0b0110'1001);
    // rhs(0b1001'0110);
    UnLimitedInt result_empty(lhs_obj & rhs_obj);
    bit_check(result_empty, empty_obj, result_empty.GetByteCapacity());
    
    EXPECT_TRUE(result_empty.IsPositive());
    EXPECT_EQ(result_empty.GetBitLength(), 0);
    EXPECT_EQ(result_empty.GetByteCapacity(), 1);
}

// DO

TEST(test_class_unlimitedint_bit_opt, test_and_opt_multi_byte)
{
    UnLimitedInt result(lhs_obj_multi & full_obj_multi);
    bit_check(result, lhs_obj_multi, result.GetByteCapacity());

    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), lhs_obj_multi.GetBitLength());
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj_multi.GetByteCapacity());
}
//

TEST(test_class_unlimitedint_bit_opt, test_int16_t_and_opt_diff_data_length)
{
    UnLimitedInt result(lhs_obj_multi & rhs_obj);
    //bit_check(result_empty, empty_obj, result_empty.GetByteCapacity());
    EXPECT_EQ(result.GetValuePtr()[0], empty_binary_value);
    EXPECT_EQ(result.GetValuePtr()[1], lhs);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), 2);
}

TEST(test_class_unlimitedint_bit_opt, test_int8_t_or_opt_one_byte)
{
    UnLimitedInt result( lhs_obj | rhs_obj );
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 1);
    EXPECT_EQ(result.GetByteCapacity(), 1);
}
TEST(test_class_unlimitedint_bit_opt, test_int8_t_or_opt_multi_byte)
{
    UnLimitedInt result( lhs_obj_multi | rhs_obj_multi );
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 1);
    EXPECT_EQ(result.GetByteCapacity(), 1);
}

TEST(test_class_unlimitedint_bit_opt, test_int8_t_or_opt_multi_byte_01)
{
    UnLimitedInt result( lhs_obj_multi | empty_obj );
    bit_check(result, lhs_obj_multi, result.GetByteCapacity());
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), 2);
}
TEST(test_class_unlimitedint_bit_opt, test_int8_t_xor_opt_one_byte)
{
    UnLimitedInt result( lhs_obj ^ rhs_obj );
    bit_check(result, full_obj_multi, result.GetByteCapacity());
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 1);
    EXPECT_EQ(result.GetByteCapacity(), 1);
}

TEST(test_class_unlimitedint_bit_opt, test_int8_t_xor_opt_one_byte_01)
{
    UnLimitedInt result( lhs_obj ^ empty_obj );
    bit_check(result, lhs_obj, result.GetByteCapacity());
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetBitLength(), 7);
    EXPECT_EQ(result.GetByteCapacity(), 1);
}

TEST(test_class_unlimitedint_bit_opt, test_int8_t_xor_opt_multi_byte)
{
    UnLimitedInt result_empty( lhs_obj ^ lhs_obj );
    EXPECT_EQ(result_empty.GetBitLength(), 0);
    EXPECT_EQ(result_empty.GetByteCapacity(), 1);
}

// int8_t lhs       (0b0110'1001);
// int16_t lhs_multi(0b0110'1001'0110'1001);

TEST(test_class_unlimitedint_bit_opt, test_int16_t_xor_opt_diff_data_length)
{   
    UnLimitedInt lhs_obj_multi(0b0110'1001'1001'0110);
    UnLimitedInt result( lhs_obj ^ lhs_obj_multi );
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[1], lhs);
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), 2);
}

void bit_check(const UnLimitedInt& lhs, const UnLimitedInt& rhs, uint16_t byte_length)
{
    for(int16_t idx(0); idx < byte_length; ++idx)
        EXPECT_EQ(lhs.GetValuePtr()[idx], rhs.GetValuePtr()[idx]);
}

