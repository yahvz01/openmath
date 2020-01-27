#include "openmath_helper/UnLimitedIntClassHelper.hpp"

#include "openmath/Bitwise.hpp"

using namespace openmath;

UnLimitedInt openmath_helper::bitwise_opt_unlimitedint(const UnLimitedInt& lhs, const UnLimitedInt& rhs, bit_opt func)
{
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length( bitwise_opt_ptr(lhs.GetValuePtr(), lhs.GetByteCapacity(), rhs.GetValuePtr(), rhs.GetByteCapacity(), func, &result_ptr, true) );
    return UnLimitedInt(result_ptr, result_bit_length);
}