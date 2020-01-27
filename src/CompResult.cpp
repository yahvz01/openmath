#include "openmath_helper/CompResult.hpp"

#include "openmath/Binary.hpp"

using namespace openmath;
using namespace openmath_helper;

CompResult openmath_helper::reverse_CompResult(const CompResult& value)
{
    if(CompResult::LARGE == value)
        return CompResult::SMALL;
    else if(CompResult::SMALL == value)
        return CompResult::LARGE;
    return CompResult::SAME;
}

std::ostream& operator<<(std::ostream& os, const CompResult& value)
{
    if(value == CompResult::LARGE)
        os << "LARGE";
    else if(value == CompResult::SMALL)
        os << "SMALL";
    else
        os << "SAME";
    return os;
}

CompResult openmath_helper::bit_comp_not_consider_sign_bit(const int8_t* lhs_ptr, const int8_t* rhs_ptr, int16_t byte_length)
{
    CompResult current_state(CompResult::SAME);
    for(int32_t byte_idx(byte_length - 1); byte_idx >= 0; --byte_idx)
    {
        if(lhs_ptr[byte_idx] > rhs_ptr[byte_idx])
        {
            current_state = CompResult::LARGE;
            break;
        }
        else if(lhs_ptr[byte_idx] < rhs_ptr[byte_idx])
        {
            current_state = CompResult::SMALL;
            break;
        }
    }
    return current_state;
}

CompResult openmath_helper::bit_comp(const int8_t* lhs, const int8_t* rhs, int16_t byte_length, bool has_signed)
{   
    if( !(has_signed) )
    {
        return bit_comp_not_consider_sign_bit(lhs, rhs, byte_length);
    }
    else
    {
        // 처음 Sign Bit check
        // e다음 프로세싱   
        bool lhs_pos( is_positive(lhs[byte_length - 1]) );
        bool rhs_pos( is_positive(rhs[byte_length - 1]) );
        
        // result check
        const CompResult result_based_bit(bit_comp_not_consider_sign_bit(lhs, rhs, byte_length));
        
        if( !lhs_pos && rhs_pos )
        {
            // negative && positive
            return CompResult::SMALL;
        }
        else if( lhs_pos && !rhs_pos )
        {
            // positive && negative
            return CompResult::LARGE;
        }
        else if( lhs_pos && rhs_pos )
        {
            // positive && positive
            return result_based_bit;
        } 
        else
        {
            // negative && negative
            return reverse_CompResult( result_based_bit );
        }
    }
}