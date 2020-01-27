#include "openmath/UnLimitedInt.hpp"

#include <cstring>
#include <cstdlib>

using namespace openmath;

UnLimitedInt::UnLimitedInt( const UnLimitedInt& rhs )
{
    int8_t *value_ptr = (int8_t *)malloc(rhs.GetByteCapacity());
    memcpy(value_ptr, rhs.value, rhs.GetByteCapacity());
    this->value = value_ptr;
    this->bit_length = rhs.bit_length;
}

UnLimitedInt& UnLimitedInt::operator=(const UnLimitedInt& rhs)
{
    if(this == &rhs)
        return *this;
    int16_t byte_length( rhs.GetByteCapacity() );
    int8_t *value_ptr = (int8_t *)malloc(byte_length);
    memcpy(value_ptr, rhs.value, byte_length);

    if(this->value != NULL && this->value != nullptr)
        free(this->value);
    this->value = value_ptr;
    this->bit_length = bit_length;
    return *this;
}

UnLimitedInt::UnLimitedInt( UnLimitedInt&& rhs )
{
    this->value = rhs.value;
    this->bit_length = rhs.bit_length;

    rhs.value = nullptr;
    rhs.bit_length = 0;
}

UnLimitedInt& UnLimitedInt::operator=( UnLimitedInt&& rhs )
{
    if(this == &rhs)
        return *this;
    if(this->value != NULL && this->value != nullptr)
        free(this->value);
    this->value = rhs.value;
    this->bit_length = rhs.bit_length;
    return *this;
}

UnLimitedInt::~UnLimitedInt()
{
    if(this->value != NULL && this->value != nullptr)
        free(this->value);
    this->bit_length = 0;
}