#include "openmath/UnLimitedInt.hpp"

#include <type_traits>
#include "openmath/Binary.hpp"
#include "openmath_helper/CompResult.hpp"

using namespace openmath;
using namespace openmath_helper;


CompResult comp_unlimitedint(const UnLimitedInt& lhs, const UnLimitedInt& rhs)
{
    bool lhs_pos(lhs.IsPositive());
    bool rhs_pos(lhs.IsPositive());
    
    if(!lhs_pos && rhs_pos)
    {
        return CompResult::SMALL;
    }
    else if(lhs_pos && !rhs_pos)
    {
        return CompResult::LARGE;
    }
    else 
    {
        auto lhs_bit_length(lhs.GetBitLength());
        auto rhs_bit_length(rhs.GetBitLength());
        if(lhs_pos && rhs_pos)
        {
            if( lhs_bit_length > rhs_bit_length)
            {
                return CompResult::LARGE;
            }
            else if( lhs_bit_length < rhs_bit_length)
            {
                return CompResult::SMALL;
            }
            else
            {
                CompResult result( bit_comp(lhs.GetValuePtr(), rhs.GetValuePtr(), lhs.GetByteCapacity(), true) );
                return result;
            }
        }      
        else
        {
            // Negative && Negative
            if( lhs_bit_length > rhs_bit_length)
                return CompResult::SMALL;
            else if( rhs_bit_length < rhs_bit_length)
                return CompResult::LARGE;
            else
            {
                CompResult temp_result( bit_comp(lhs.GetValuePtr(), rhs.GetValuePtr(), lhs.GetByteCapacity(), true) );
                return reverse_CompResult( temp_result );
            }
        }
    }
}


bool UnLimitedInt::equal( const UnLimitedInt& rhs) const
{
    if(this->bit_length == rhs.bit_length)
    {
        // 여기서부터 고치기 시작
        CompResult comp_result( comp_unlimitedint(*this, rhs) );
        if(comp_result == CompResult::SAME)
            return true;
    }
    return false;
}

bool UnLimitedInt::smaller( const UnLimitedInt& rhs) const
{
    return comp_unlimitedint(*this, rhs) == CompResult::SMALL;
}

bool UnLimitedInt::greater( const UnLimitedInt& rhs) const
{
    return comp_unlimitedint(*this, rhs) == CompResult::LARGE;
}

bool UnLimitedInt::not_equal( const UnLimitedInt& rhs) const
{   return !(this->equal(rhs));   }
bool UnLimitedInt::greater_or_equal( const UnLimitedInt& rhs) const
{   return !(this->smaller(rhs));    }
bool UnLimitedInt::smaller_or_equal( const UnLimitedInt& rhs) const
{   return !(this->greater(rhs));    }






bool operator==(const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.equal(rhs);  }
bool operator!=( const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.not_equal(rhs);  }
bool operator>=( const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.greater_or_equal(rhs); }
bool operator>( const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.greater(rhs);  }
bool operator<(const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.smaller(rhs);    }
bool operator<=( const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.smaller_or_equal(rhs); }