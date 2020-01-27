#include "openmath/FixedByteLengthInt.hpp"

#include <cstdlib>
#include <cstring>

using namespace openmath;

FixedByteLengthInt::FixedByteLengthInt( const FixedByteLengthInt& rhs )
{
    int8_t *new_value_ptr = (int8_t *)malloc(rhs.GetByteCapacity());
    memcpy(value_ptr, rhs.value_ptr, rhs.GetByteCapacity());
    this->value_ptr = new_value_ptr;
    this->bit_length = rhs.bit_length;
    this->byte_capacity = rhs.byte_capacity;
}

FixedByteLengthInt& FixedByteLengthInt::operator=(const FixedByteLengthInt& rhs)
{
    if(this == &rhs)
        return *this;
    int8_t *new_value_ptr = (int8_t *)malloc(rhs.byte_capacity);
    memcpy(new_value_ptr, rhs.value_ptr, rhs.byte_capacity);
    
    if(this->value_ptr != NULL && this->value_ptr != nullptr)
        free(value_ptr);
    this->value_ptr = new_value_ptr;
    this->bit_length = rhs.bit_length;
    this->byte_capacity = rhs.byte_capacity;
    return *this;
}

FixedByteLengthInt::FixedByteLengthInt( FixedByteLengthInt&& rhs )
{
    this->value_ptr = rhs.value_ptr;
    this->bit_length = rhs.bit_length;
    rhs.value_ptr = nullptr;
    rhs.bit_length = 0;
    rhs.byte_capacity = 0;
}

FixedByteLengthInt& FixedByteLengthInt::operator=( FixedByteLengthInt&& rhs )
{
    if(this == &rhs)
        return *this;
    if(this->value_ptr != NULL && this->value_ptr != nullptr)
        free(value_ptr);
    this->value_ptr = rhs.value_ptr;
    this->bit_length = rhs.bit_length;
    this->byte_capacity = rhs.byte_capacity;
    
    rhs.value_ptr = nullptr;
    rhs.bit_length = 0;
    rhs.byte_capacity = 0;
    
    return *this;
}

FixedByteLengthInt::~FixedByteLengthInt()
{
    if(value_ptr != NULL && value_ptr != nullptr)
        free(value_ptr);
    bit_length = 0;
    byte_capacity = 0;
}
