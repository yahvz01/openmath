#include "openmath/FixedByteLengthIntBuffer.hpp"

#include "openmath/Binary.hpp"

using namespace openmath;

bool FixedByteLengthIntBuffer::IsPositive() const
{
    return is_positive_ptr(this->value_ptr, this->byte_capacity);
}

int8_t* const FixedByteLengthIntBuffer::GetValuePtr() const
{
    return this->value_ptr;
}
int16_t FixedByteLengthIntBuffer::GetBitLength() const
{
    return this->bit_length;
}

int16_t FixedByteLengthIntBuffer::GetMeaningfullByteCapacity() const
{
    return bit_len_to_byte_len(this->bit_length);
}

int16_t FixedByteLengthIntBuffer::GetByteCapacity() const
{
    return this->byte_capacity;
}