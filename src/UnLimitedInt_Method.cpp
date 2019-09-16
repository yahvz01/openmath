#include "openmath/UnLimitedInt.hpp"

constexpr int8_t BIT_IN_BYTE = 8;


using namespace openmath;

bool UnLimitedInt::IsPositive() const
{
    if(this->value[ (GetByteCapacity() - 1) ] & 0b1000'0000)
        return false;
    else
        return true;
}

uint16_t UnLimitedInt::GetBitLength() const
{
    return length;
}

uint16_t UnLimitedInt::GetByteCapacity() const
{
    if(length % BIT_IN_BYTE)
        return length;
    return (length + 1);
}