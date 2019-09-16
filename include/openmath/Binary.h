#pragma once

namespace openmath {
    

    template <typename Tp>
    constexpr inline Tp create_max_value();

    template <typename Tp>
    Tp make_binary_complemetary(const Tp & value);
    
    template <typename Tp>
    bool carry_lookahead(const Tp& lhs, const Tp& rhs, bool hasSign = false);

    template <typename Tp>
    bool half_adder(const Tp& lhs, const Tp& rhs, Tp& result);

    template <typename Tp>
    bool full_adder(const Tp& lhs, const Tp& rhs, Tp& result, bool carry_in);

    
}

// hasSignBit => half_adder / full adder

#include "Binary_Impl.h"