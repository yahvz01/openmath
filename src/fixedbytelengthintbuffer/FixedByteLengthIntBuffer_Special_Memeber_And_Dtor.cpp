#include "openmath/FixedByteLengthIntBuffer.hpp"

#include <cstdlib>
#include <cstring>

using namespace openmath;

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const FixedByteLengthIntBuffer& rhs )
{
    int8_t *new_value_ptr = (int8_t *)malloc(rhs.GetByteCapacity());
    memcpy(value_ptr, rhs.value_ptr, rhs.GetByteCapacity());
    this->value_ptr = new_value_ptr;
    this->bit_length = rhs.bit_length;
    this->byte_capacity = rhs.byte_capacity;
}

FixedByteLengthIntBuffer& FixedByteLengthIntBuffer::operator=(const FixedByteLengthIntBuffer& rhs)
{
    if(this == &rhs)
        return *this;
    int8_t *new_value_ptr = (int8_t *)malloc(rhs.byte_capacity);
    memcpy(new_value_ptr, rhs.value_ptr, rhs.byte_capacity);

    if(this->value_ptr != NULL && this->value_ptr != nullptr)
        free(this->value_ptr);
    this->value_ptr = new_value_ptr;
    this->bit_length = rhs.bit_length;
    this->byte_capacity = rhs.byte_capacity;
    return *this;
}

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( FixedByteLengthIntBuffer&& rhs )
{
    this->value_ptr = rhs.value_ptr;
    this->bit_length = rhs.bit_length;

    rhs.value_ptr = nullptr;
    rhs.bit_length = 0;
    rhs.byte_capacity = 0;
}

FixedByteLengthIntBuffer& FixedByteLengthIntBuffer::operator=( FixedByteLengthIntBuffer&& rhs )
{
    if(this == &rhs)
        return *this;
    this->value_ptr = rhs.value_ptr;
    this->bit_length = rhs.bit_length;
    this->byte_capacity = rhs.byte_capacity;
    
    rhs.value_ptr = nullptr;
    rhs.bit_length = 0;
    rhs.byte_capacity = 0;
    return *this;
}

FixedByteLengthIntBuffer::~FixedByteLengthIntBuffer()
{
    if(value_ptr != NULL && value_ptr != nullptr)
        free(value_ptr);
    bit_length = 0;
    byte_capacity = 0;
}
