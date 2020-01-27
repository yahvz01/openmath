#include "openmath/FixedByteLengthInt.hpp"

#include <type_traits>
#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"

using namespace openmath;

template <typename Tp>
FixedByteLengthInt left_bit_shift_fixedbytelengthint(const FixedByteLengthInt& value, const Tp& shift_jump)
{
    static_assert(std::is_integral<Tp>::value);
    int8_t *result(nullptr);
    int16_t bit_length = left_bit_shift(value.GetValuePtr(), value.GetByteCapacity(), shift_jump, &result, false);
    return FixedByteLengthInt(result, bit_length, value.GetByteCapacity());
}

template <typename Tp>
FixedByteLengthInt right_bit_shift_fixedbytelengthint(const FixedByteLengthInt& value, const Tp& shift_jump)
{
    static_assert(std::is_integral<Tp>::value);
    int8_t *result(nullptr);
    int16_t bit_length = right_bit_shift(value.GetValuePtr(), value.GetByteCapacity(), shift_jump, &result, false);
    return FixedByteLengthInt(result, bit_length, value.GetByteCapacity());
}

FixedByteLengthInt FixedByteLengthInt::operator<<(const int8_t& value)
{   return left_bit_shift_fixedbytelengthint(*this, value);    }
FixedByteLengthInt FixedByteLengthInt::operator<<(const int16_t& value)
{   return left_bit_shift_fixedbytelengthint(*this, value);    }
FixedByteLengthInt FixedByteLengthInt::operator<<(const int32_t& value)
{   return left_bit_shift_fixedbytelengthint(*this, value);    }
FixedByteLengthInt FixedByteLengthInt::operator<<(const int64_t& value)
{   return left_bit_shift_fixedbytelengthint(*this, value);    }


FixedByteLengthInt FixedByteLengthInt::operator>>(const int8_t& value)
{   return right_bit_shift_fixedbytelengthint(*this, value);    }
FixedByteLengthInt FixedByteLengthInt::operator>>(const int16_t& value)
{   return right_bit_shift_fixedbytelengthint(*this, value);    }
FixedByteLengthInt FixedByteLengthInt::operator>>(const int32_t& value)
{   return right_bit_shift_fixedbytelengthint(*this, value);    }
FixedByteLengthInt FixedByteLengthInt::operator>>(const int64_t& value)
{   return right_bit_shift_fixedbytelengthint(*this, value);    }