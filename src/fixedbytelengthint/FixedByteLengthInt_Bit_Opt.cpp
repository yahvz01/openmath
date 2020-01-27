#include "openmath/FixedByteLengthInt.hpp"

#include <algorithm>

#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"

using namespace openmath;

namespace {
    
    FixedByteLengthInt bitwise_opt_FixedByteLengthInt(const FixedByteLengthInt& lhs, const FixedByteLengthInt& rhs, bit_opt func)
    {
        int16_t lhs_byte_capacity(lhs.GetByteCapacity());
        int16_t rhs_byte_capacity(rhs.GetByteCapacity());
        int8_t *result_ptr = nullptr;
        int16_t result_bit_length( bitwise_opt_ptr(lhs.GetValuePtr(), lhs_byte_capacity, rhs.GetValuePtr(), rhs_byte_capacity, func, &result_ptr, true) );
        return FixedByteLengthInt(result_ptr, result_bit_length, (lhs_byte_capacity > rhs_byte_capacity ? lhs_byte_capacity : rhs_byte_capacity ) );
    }
}

FixedByteLengthInt FixedByteLengthInt::operator~() const
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length( bitwise_not_opt_ptr(this->GetValuePtr(), this->GetByteCapacity(), &result_ptr) );
    return FixedByteLengthInt(result_ptr, result_bit_length, this->GetByteCapacity());
}

FixedByteLengthInt FixedByteLengthInt::bitwise_and( const FixedByteLengthInt& rhs) const
{
    return bitwise_opt_FixedByteLengthInt(*this, rhs, bitwise_and_single_byte);
}

FixedByteLengthInt FixedByteLengthInt::bitwise_or( const FixedByteLengthInt& rhs) const
{
    return bitwise_opt_FixedByteLengthInt(*this, rhs, bitwise_or_single_byte);
}


FixedByteLengthInt FixedByteLengthInt::bitwise_xor( const FixedByteLengthInt& rhs) const
{
    return bitwise_opt_FixedByteLengthInt(*this, rhs, bitwise_xor_single_byte);
}

FixedByteLengthInt operator&(const openmath::FixedByteLengthInt& lhs, const openmath::FixedByteLengthInt& rhs)
{
    return lhs.bitwise_and(rhs);
}
FixedByteLengthInt operator|(const openmath::FixedByteLengthInt& lhs, const openmath::FixedByteLengthInt& rhs)
{
    return lhs.bitwise_or(rhs);
}
FixedByteLengthInt operator^(const openmath::FixedByteLengthInt& lhs, const openmath::FixedByteLengthInt& rhs)
{
    return lhs.bitwise_xor(rhs);
}