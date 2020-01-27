#include <gtest/gtest.h>

namespace {
    int8_t lhs(0b0110'1001);
    int8_t rhs(0b1001'0110);

    int16_t lhs_multi(0b0110'1001'1001'0110);
    int16_t rhs_multi(0b1001'0110'0110'1001);
}

// 음수는 carry_out을 어떻게 알 수 있는가

TEST(method_byte_carry_out_lookahead_with_propaganda, )