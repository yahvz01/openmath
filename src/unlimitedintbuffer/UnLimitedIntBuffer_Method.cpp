#include "openmath/UnLimitedIntBuffer.hpp"

#include "openmath/Binary.hpp"

using namespace openmath;

bool UnLimitedIntBuffer::IsPositive() const
{
    return is_positive_ptr(this->value_ptr, bit_len_to_byte_len(this->bit_length));
}

int8_t* const UnLimitedIntBuffer::GetValuePtr() const
{
    return this->value_ptr;
}
int16_t UnLimitedIntBuffer::GetBitLength() const
{
    return this->bit_length;
}

int16_t UnLimitedIntBuffer::GetByteCapacity() const
{
    return bit_len_to_byte_len(this->bit_length);
}