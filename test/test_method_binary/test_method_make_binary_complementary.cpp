#include <gtest/gtest.h>

#include "openmath/Binary.hpp"

namespace {
    int8_t  value_t_8 (0b1010'1010);
    int16_t value_t_16(0b1010'1010'1010'1010);
    int32_t value_t_32(0b1010'1010'1010'1010'1010'1010'1010'1010);
    int64_t value_t_64(0b1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010);

    uint8_t  u_value_t_8 (0b1010'1010);
    uint16_t u_value_t_16(0b1010'1010'1010'1010);
    uint32_t u_value_t_32(0b1010'1010'1010'1010'1010'1010'1010'1010);
    uint64_t u_value_t_64(0b1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010'1010);

    uint8_t comp_t_8 (0b0101'0110);
    uint16_t comp_t_16(0b0101'0101'0101'0110);
    uint32_t comp_t_32(0b0101'0101'0101'0101'0101'0101'0101'0110);
    uint64_t comp_t_64(0b0101'0101'0101'0101'0101'0101'0101'0101'0101'0101'0101'0101'0101'0101'0101'0110);
}

using namespace openmath;

TEST(method_make_binary_comp, test_signed_integer)
{
    auto result_t_8 = make_binary_complement(value_t_8);
    EXPECT_EQ(static_cast<uint8_t>(result_t_8), comp_t_8);

    auto result_t_16 = make_binary_complement(value_t_16);
    EXPECT_EQ(static_cast<uint16_t>(result_t_16), comp_t_16);

    auto result_t_32 = make_binary_complement(value_t_32);
    EXPECT_EQ(static_cast<uint32_t>(result_t_32), comp_t_32);

    auto result_t_64 = make_binary_complement(value_t_64);
    EXPECT_EQ(static_cast<uint64_t>(result_t_64), comp_t_64);
}


TEST(method_make_binary_comp, test_unsigned_interger)
{
    auto result_t_8 = make_binary_complement(u_value_t_8);
    EXPECT_EQ(result_t_8, comp_t_8);

    auto result_t_16 = make_binary_complement(u_value_t_16);
    EXPECT_EQ(result_t_16, comp_t_16);

    auto result_t_32 = make_binary_complement(u_value_t_32);
    EXPECT_EQ(result_t_32, comp_t_32);

    auto result_t_64 = make_binary_complement(u_value_t_64);
    EXPECT_EQ(result_t_64, comp_t_64);
}