#include "openmath/FixedByteLengthInt.hpp"

#include "openmath/Binary.hpp"

using namespace openmath;

bool FixedByteLengthInt::IsPositive() const
{
    return is_positive_ptr(this->value_ptr, this->byte_capacity);
}

int8_t* const FixedByteLengthInt::GetValuePtr() const
{
    return this->value_ptr;
}
int16_t FixedByteLengthInt::GetBitLength() const
{
    return this->bit_length;
}

int16_t FixedByteLengthInt::GetMeaningfullByteCapacity() const
{
    return bit_len_to_byte_len(this->bit_length);
}

int16_t FixedByteLengthInt::GetByteCapacity() const
{
    return this->byte_capacity;
}