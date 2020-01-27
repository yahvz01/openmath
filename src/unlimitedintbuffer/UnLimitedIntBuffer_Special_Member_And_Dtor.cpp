#include "openmath/UnLimitedIntBuffer.hpp"

#include <cstring>
#include <cstdlib>

using namespace openmath;

UnLimitedIntBuffer::UnLimitedIntBuffer( const UnLimitedIntBuffer& rhs )
{
    int8_t *value_ptr = (int8_t *)malloc(rhs.GetByteCapacity());
    memcpy(value_ptr, rhs.value_ptr, rhs.GetByteCapacity());
    this->value_ptr = value_ptr;
    this->bit_length = rhs.bit_length;
}

UnLimitedIntBuffer& UnLimitedIntBuffer::operator=(const UnLimitedIntBuffer& rhs)
{
    if(this == &rhs)
        return *this;
    int16_t byte_length( rhs.GetByteCapacity() );
    int8_t *value_ptr = (int8_t *)malloc(byte_length);
    memcpy(value_ptr, rhs.value_ptr, byte_length);

    if(this->value_ptr != NULL && this->value_ptr != nullptr)
        free(this->value_ptr);
    this->value_ptr = value_ptr;
    this->bit_length = bit_length;
    return *this;
}

UnLimitedIntBuffer::UnLimitedIntBuffer( UnLimitedIntBuffer&& rhs )
{
    this->value_ptr = rhs.value_ptr;
    this->bit_length = rhs.bit_length;

    rhs.value_ptr = nullptr;
    rhs.bit_length = 0;
}

UnLimitedIntBuffer& UnLimitedIntBuffer::operator=( UnLimitedIntBuffer&& rhs )
{
    if(this == &rhs)
        return *this;
    if(this->value_ptr != NULL && this->value_ptr != nullptr)
        free(this->value_ptr);
    this->value_ptr = rhs.value_ptr;
    this->bit_length = rhs.bit_length;
    return *this;
}

UnLimitedIntBuffer::~UnLimitedIntBuffer()
{
    free(this->value_ptr);
    this->bit_length = 0;
}