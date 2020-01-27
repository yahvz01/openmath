#include "openmath/UnLimitedInt.hpp"

#include <type_traits>
#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"

using namespace openmath;

template <typename Tp>
UnLimitedInt left_bit_shift_unlimitedint(const UnLimitedInt& value, const Tp& shift_jump)
{
    static_assert(std::is_integral<Tp>::value);
    int8_t *result(nullptr);
    int16_t bit_length = left_bit_shift(value.GetValuePtr(), value.GetByteCapacity(), shift_jump, &result, false);
    return UnLimitedInt(result, bit_length);
}

template <typename Tp>
UnLimitedInt right_bit_shift_unlimitedint(const UnLimitedInt& value, const Tp& shift_jump)
{
    static_assert(std::is_integral<Tp>::value);
    int8_t *result(nullptr);
    int16_t bit_length = right_bit_shift(value.GetValuePtr(), value.GetByteCapacity(), shift_jump, &result, false);
    return UnLimitedInt(result, bit_length);
}

UnLimitedInt UnLimitedInt::operator<<(const int16_t& value)
{   return left_bit_shift_unlimitedint(*this, value);    }

UnLimitedInt UnLimitedInt::operator>>(const int16_t& value)
{   return right_bit_shift_unlimitedint(*this, value);   }