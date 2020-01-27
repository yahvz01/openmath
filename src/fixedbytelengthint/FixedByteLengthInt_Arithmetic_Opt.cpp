#include "openmath/FixedByteLengthInt.hpp"

#include "openmath/Binary.hpp"

#include <iostream>
#include <bitset>

using namespace openmath;

openmath::fbint operator+( const openmath::fbint& lhs, const openmath::fbint& rhs)
{
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length = adder_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr, false, false);
    return FixedByteLengthInt(result_ptr, result_bit_length, lhs.GetByteCapacity());
}

openmath::fbint operator-( const openmath::fbint& lhs, const openmath::fbint& rhs)
{
    int8_t *compl_ptr( make_binary_complement_ptr(rhs.GetValuePtr(), rhs.GetByteCapacity()) );
    int16_t compl_bit_length = get_digit_binary_number_ptr(compl_ptr, true, rhs.GetByteCapacity());
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length( adder_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), compl_ptr, bit_len_to_byte_len(compl_bit_length), &result_ptr, true, false) );
    return FixedByteLengthInt(result_ptr, result_bit_length, lhs.GetByteCapacity());
}

openmath::fbint operator*( const openmath::fbint& lhs, const openmath::fbint& rhs)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(multiply_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr, false));
    return FixedByteLengthInt(result_ptr, result_bit_length, lhs.GetByteCapacity());
}

openmath::fbint operator/( const openmath::fbint& lhs, const openmath::fbint& rhs)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(divide_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr));
    return FixedByteLengthInt(result_ptr, result_bit_length, lhs.GetByteCapacity());
}

openmath::fbint operator%( const openmath::fbint& lhs, const openmath::fbint& rhs)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(remainder_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr));
    return FixedByteLengthInt(result_ptr, result_bit_length, lhs.GetByteCapacity());
}