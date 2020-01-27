#include "openmath/Binary.hpp"

using namespace openmath;

#include <iostream>
#include <bitset>
    
bool openmath::byte_carry_out_lookahead(const int8_t& lhs, const int8_t& rhs)
{
    bool generator(false);
    bool propaganda(true);
    
    for(int idx(8); (idx > 0 && propaganda); --idx)
    {
        bool lhs_and = (lhs & bit_pos[idx]);
        bool rhs_and = (rhs & bit_pos[idx]);
        
        generator = (lhs_and && rhs_and);
        if(generator)
        {
            return true;
        }
        propaganda = lhs_and || rhs_and;
    }
    return false;
}

std::pair<bool, bool> openmath::byte_carry_out_lookahead_with_propaganda(const int8_t& lhs, const int8_t& rhs, bool has_sign)
{
    bool generator(false);
    bool propaganda(true);
    
    for(int idx( has_sign? 7 : 8 ); idx > 0 && propaganda; --idx)
    {
            bool lhs_and = (lhs & bit_pos[idx]);
            bool rhs_and = (rhs & bit_pos[idx]);
            generator = lhs_and && rhs_and;
            if(generator)
                return std::make_pair(true, false);
            propaganda = lhs_and || rhs_and;
    }
    return std::make_pair(false, propaganda);
}

bool openmath::byte_half_adder(const int8_t& lhs, const int8_t& rhs, int8_t& result)
{
    int8_t carry(lhs & rhs);
    int8_t digit(lhs ^ rhs);
    int8_t t_carry(carry << 1);
    while(t_carry)
    {
        carry = t_carry & digit;
        digit = t_carry ^ digit;
        t_carry = (carry << 1);
    }
    result = digit;
    return byte_carry_out_lookahead(lhs, rhs);
}

bool openmath::byte_full_adder(const int8_t& lhs, const int8_t& rhs, bool carry_in, int8_t& result)
{
    int8_t temp_result;
    bool carry_out = byte_half_adder(lhs, rhs, temp_result);
    if(carry_in)
        carry_out = carry_out || byte_half_adder(temp_result, 0b0000'0001, result);
    else
        result = temp_result;
    return carry_out;
}

int16_t openmath::bit_len_to_byte_len(int16_t bit_length)
{   
    return ((bit_length / 8) + 1);
}

int16_t openmath::bit_len_to_byte_len_only_meaningfull(int16_t bit_length)
{   
    return ((bit_length / 8) + ((bit_length % 8)? 1 : 0) );
}