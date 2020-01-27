#include "openmath/UnLimitedInt.hpp"

#include "openmath/Binary.hpp"


using namespace openmath;

openmath::bigint operator+( const openmath::bigint& lhs, const openmath::bigint& rhs)
{
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length = adder_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr, false, false);
    return UnLimitedInt(result_ptr, result_bit_length);
}

openmath::bigint operator-( const openmath::bigint& lhs, const openmath::bigint& rhs)
{
    int8_t *compl_ptr( make_binary_complement_ptr(rhs.GetValuePtr(), rhs.GetByteCapacity()) );
    int16_t compl_bit_length = get_digit_binary_number_ptr(compl_ptr, true, rhs.GetByteCapacity());

    int8_t *result_ptr(nullptr);
    int16_t result_bit_length = adder_ptr(lhs.GetValuePtr(), lhs.GetBitLength(), compl_ptr, compl_bit_length, &result_ptr, false, false);
    return UnLimitedInt(result_ptr, result_bit_length);
}

openmath::bigint operator*( const openmath::bigint& lhs, const openmath::bigint& rhs)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(multiply_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr, false));
    return UnLimitedInt(result_ptr, result_bit_length);
}

openmath::bigint operator/( const openmath::bigint& lhs, const openmath::bigint& rhs)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(divide_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr));
    return UnLimitedInt(result_ptr, result_bit_length);
}

openmath::bigint operator%( const openmath::bigint& lhs, const openmath::bigint& rhs)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(remainder_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), &result_ptr));
    return UnLimitedInt(result_ptr, result_bit_length);
}