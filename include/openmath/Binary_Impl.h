#pragma once
#include "Binary.h"

#include <cstring>
#include <climits>

#include <iostream>
#include <bitset>
#include <type_traits>

template <typename Tp>
constexpr inline Tp openmath::create_max_value()
{
        Tp value(0);
        return ~value;
}

template <typename Tp>
Tp openmath::make_binary_complemetary(const Tp& value)
{
        Tp result;
        half_adder(~value, 1, result);
        return result;
}

template <typename Tp>
bool openmath::carry_lookahead(const Tp& lhs, const Tp& rhs, bool hasSign)
{
        using unsinged_Tp = typename std::make_unsigned<Tp>::type;
        // Both of lhs & rhs should be positive.
        auto digit = sizeof(unsinged_Tp) * 8;
        if(hasSign)
            --digit;    
        unsinged_Tp comp(1);
        comp <<= (digit - 1);
        
        bool generator(false);
        bool propaganda(true);
        bool result(false);
        
        unsinged_Tp lhs_result;
        unsinged_Tp rhs_result;
        do {
            lhs_result = (lhs & comp);
            rhs_result = (rhs & comp);
            comp >>= 1;
            generator = lhs_result && rhs_result;
            if( propaganda && generator )
            {
                result = true;
                break;
            }
            propaganda = lhs_result || rhs_result;
        } while ( propaganda && !(comp == 0) );
        return result;
}

template <typename Tp>
bool openmath::half_adder(const Tp& lhs, const Tp& rhs, Tp& result)
{   

        Tp carry = (lhs & rhs);
        Tp digit = (lhs ^ rhs);
        while(!(carry == 0))
        {
        Tp shifted_carry = carry << 1;
        carry = shifted_carry & digit;
        digit = shifted_carry ^ digit; 
        }
        result = digit;
        return carry_lookahead(lhs, rhs);
}

template <typename Tp>
bool openmath::full_adder(const Tp& lhs, const Tp& rhs, Tp& result, bool carry_in)
{
        bool carry_out(false);
        Tp lhs_with_carry_in;
        if(carry_in)
                carry_out = half_adder(lhs, static_cast<Tp>(1), lhs_with_carry_in);
        else
                lhs_with_carry_in = lhs;
        
        carry_out = carry_out || half_adder(lhs_with_carry_in, rhs, result);
        return carry_out;
}