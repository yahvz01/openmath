#include <gtest/gtest.h>

#include "openmath/UnLimitedInt.hpp"

using namespace openmath;

TEST(class_unlimitedint_special_member, test_copy_ctor)
{
    UnLimitedInt init_value(5);
    //UnLimitedInt copyed_value(init_value);

    //EXPECT_EQ(copyed_value.GetBitLength(), init_value.GetBitLength());
    //EXPECT_EQ(copyed_value.GetByteCapacity(), init_value.GetByteCapacity());
}

//TEST(class_unlimitedint_special_member)e