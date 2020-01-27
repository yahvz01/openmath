#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"

using namespace openmath;

#include <iostream>
#include <bitset>

namespace {
    int8_t lhs(0b0110'1001);
    int8_t lhs_one_left_shift(0b1101'0010);
    int8_t lhs_one_right_shift(0b0011'0100);
    
    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t lhs_multi_two_left_shift(0b1010'0110'0101'1000);
    int16_t lhs_multi_two_right_shift(0b0001'1010'0110'0101);

    int8_t rhs(0b1001'0110);
    int8_t rhs_one_left_shift(0b0010'1100);
    int8_t rhs_one_right_shift(0b1100'1011);
    
    int16_t rhs_multi(0b1001'0110'0110'1001);
    int16_t rhs_multi_two_left_shift(0b0101'1001'1010'0100);
    int16_t rhs_multi_two_right_shift(0b1110'0101'1001'1010);
    
    UnLimitedInt lhs_obj(lhs);
    UnLimitedInt lhs_obj_comp(lhs_one_left_shift);
    UnLimitedInt lhs_obj_comp_r(lhs_one_right_shift);

    UnLimitedInt rhs_obj(rhs);
    UnLimitedInt rhs_obj_comp(rhs_one_left_shift);
    UnLimitedInt rhs_obj_comp_r(rhs_one_right_shift);

    UnLimitedInt lhs_obj_multi(lhs_multi);
    UnLimitedInt lhs_obj_comp_multi(lhs_multi_two_left_shift);
    UnLimitedInt lhs_obj_comp_multi_r(lhs_multi_two_right_shift);

    UnLimitedInt rhs_obj_multi(rhs_multi);
    UnLimitedInt rhs_obj_comp_multi(rhs_multi_two_left_shift);
    UnLimitedInt rhs_obj_comp_multi_r(rhs_multi_two_right_shift);
}

// Left shift 
TEST(test_class_unlimitedint_bit_shift_opt, test_left_shift_by_single_byte_pos)
{
    UnLimitedInt result(lhs_obj << 1);
    
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs_one_left_shift);
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj.GetByteCapacity());
}

TEST(test_class_unlimitedint_bit_shift_opt, test_left_shift_by_single_byte_neg)
{
    UnLimitedInt result(rhs_obj << 1);
    
    EXPECT_TRUE(result.IsPositive());
    std::cout
        << std::boolalpha
        << std::bitset<8>(result.GetValuePtr()[0])
        << " : " << result.GetByteCapacity()
        << std::endl;
    EXPECT_EQ(result.GetValuePtr()[0], rhs_one_left_shift);
    EXPECT_EQ(result.GetByteCapacity(), rhs_obj.GetByteCapacity());
}

TEST(test_class_unlimitedint_bit_shift_opt, test_left_shift_by_multi_byte_pos)
{
    UnLimitedInt result(lhs_obj_multi << 2);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[1], lhs_obj_comp_multi.GetValuePtr()[1]);
    EXPECT_EQ(result.GetValuePtr()[0], lhs_obj_comp_multi.GetValuePtr()[0]);
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj_multi.GetByteCapacity());
}

TEST(test_class_unlimitedint_bit_shift_opt, test_left_shift_by_multi_byte_neg)
{
    // 0b1001'0110'0110'1001 - origin
    // 0b0101'1001'1010'0100 - comp
    UnLimitedInt result(rhs_obj_multi << 2);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[1], rhs_obj_comp_multi.GetValuePtr()[1]);
    EXPECT_EQ(result.GetValuePtr()[0], rhs_obj_comp_multi.GetValuePtr()[0]);
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), rhs_obj_multi.GetByteCapacity());
    
}

TEST(test_class_unlimitedint_bit_shift_opt, test_left_shift_over_byte_by_multi_byte_pos)
{
    //  0b1001'0110'0110'1001;
    //  0b1010'0100'0000'0000;
    //  0b0101'1000
    UnLimitedInt result(lhs_obj_multi << 10);
    std::cout << "bytes : " << result.GetByteCapacity() << std::endl;
    std::cout 
        << std::bitset<8>(result.GetValuePtr()[1])
        << std::bitset<8>(result.GetValuePtr()[0])
        << std::endl;
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[1], lhs_obj_comp_multi.GetValuePtr()[0]);
    EXPECT_EQ(result.GetValuePtr()[0], 0);
    EXPECT_EQ(result.GetBitLength(), 15);
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj_multi.GetByteCapacity());
}

TEST(test_class_unlimitedint_bit_shift_opt, test_left_shift_over_byte_by_multi_byte_neg)
{
    // 0b1001'0110'0110'1001 - origin
    // 0b1010'0100'0000'0000 - origin_<<_10
    
    // 0b0101'1100'0000'0000 - origin_<<_10_compl
    

    // 0b0101'1001'1010'0100 - comp
    
 
    // Double free or corruption
    UnLimitedInt result(rhs_obj_multi << 10);
    
//    EXPECT_FALSE(result.IsPositive());
//    
//    EXPECT_EQ(result.GetValuePtr()[1], rhs_obj_comp_multi.GetValuePtr()[0]);
//    EXPECT_EQ(result.GetValuePtr()[0], 0);
//    EXPECT_EQ(result.GetBitLength(), 15);
//    EXPECT_EQ(result.GetByteCapacity(), rhs_obj_multi.GetByteCapacity());
}
// Right shift 

TEST(test_class_unlimitedint_bit_shift_opt, test_right_shift_by_single_byte_pos)
{
    UnLimitedInt result(lhs_obj >> 1);
    
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs_one_right_shift);
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj.GetByteCapacity());
}

TEST(test_class_unlimitedint_bit_shift_opt, test_right_shift_by_single_byte_neg)
{
    UnLimitedInt result(rhs_obj >> 1);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], rhs_one_right_shift);
    EXPECT_EQ(result.GetByteCapacity(), rhs_obj.GetByteCapacity());
}


TEST(test_class_unlimitedint_bit_shift_opt, test_right_shift_by_multi_byte_pos)
{
    UnLimitedInt result(lhs_obj_multi >> 2);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[1], lhs_obj_comp_multi_r.GetValuePtr()[1]);
    EXPECT_EQ(result.GetValuePtr()[0], lhs_obj_comp_multi_r.GetValuePtr()[0]);
    EXPECT_EQ(result.GetBitLength(), 13);
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj_comp_multi_r.GetByteCapacity());
}

TEST(test_class_unlimitedint_bit_shift_opt, test_right_shift_by_multi_byte_neg)
{
   UnLimitedInt result(rhs_obj_multi >> 2);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[1], rhs_obj_comp_multi_r.GetValuePtr()[1]);
    EXPECT_EQ(result.GetValuePtr()[0], rhs_obj_comp_multi_r.GetValuePtr()[0]);
    EXPECT_EQ(result.GetBitLength(), 13);
    EXPECT_EQ(result.GetByteCapacity(), rhs_obj_comp_multi_r.GetByteCapacity());
    
}

TEST(test_class_unlimitedint_bit_shift_opt, test_right_shift_over_byte_by_multi_byte_ps)
{
    // 0b0110'1001'1001'0110
    // 0b0001'1010'0110'0101
    //           0b0001'1010

    UnLimitedInt result(lhs_obj_multi >> 10);
    EXPECT_TRUE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], lhs_obj_comp_multi_r.GetValuePtr()[1]);
    EXPECT_EQ(result.GetBitLength(), 5);
    EXPECT_EQ(result.GetByteCapacity(), lhs_obj_comp_multi_r.GetByteCapacity() - 1);
}

TEST(test_class_unlimitedint_bit_shift_opt, test_right_shift_over_byte_by_multi_byte_neg)
{
    // 0b1001'0110'0110'1001
    // 0b1110'0101'1001'1010
    //           0b1110'0101

    UnLimitedInt result(rhs_obj_multi >> 10);
    EXPECT_FALSE(result.IsPositive());
    EXPECT_EQ(result.GetValuePtr()[0], rhs_obj_comp_multi_r.GetValuePtr()[1]);
    EXPECT_EQ(result.GetBitLength(), 5);
    EXPECT_EQ(result.GetByteCapacity(), rhs_obj_comp_multi_r.GetByteCapacity() - 1);
}
