#include "openmath/UnLimitedInt.hpp"

#include <algorithm>

#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"
#include "openmath_helper/UnLimitedIntClassHelper.hpp"

using namespace openmath;
using namespace openmath_helper;

UnLimitedInt UnLimitedInt::operator~() const
{
    int8_t* result(nullptr);
    int16_t result_bit_length = bitwise_not_opt_ptr(this->GetValuePtr(), this->GetByteCapacity(), &result);
    return UnLimitedInt(result, result_bit_length);
}

UnLimitedInt UnLimitedInt::bitwise_and( const UnLimitedInt& rhs) const
{   return bitwise_opt_unlimitedint(*this, rhs, bitwise_and_single_byte);   }

UnLimitedInt UnLimitedInt::bitwise_or( const UnLimitedInt& rhs) const
{   return bitwise_opt_unlimitedint(*this, rhs, bitwise_or_single_byte);    }


UnLimitedInt UnLimitedInt::bitwise_xor( const UnLimitedInt& rhs) const
{   return bitwise_opt_unlimitedint(*this, rhs, bitwise_xor_single_byte);   }

UnLimitedInt operator&(const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.bitwise_and(rhs);    }

UnLimitedInt operator|(const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.bitwise_or(rhs); }
UnLimitedInt operator^(const openmath::bigint& lhs, const openmath::bigint& rhs)
{   return lhs.bitwise_xor(rhs);    }