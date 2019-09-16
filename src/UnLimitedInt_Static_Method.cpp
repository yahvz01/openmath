#include "openmath/UnLimitedInt.hpp"
#include "Binary_Helper.h"

#include <cstring>

using namespace openmath;


UnLimitedInt UnLimitedInt::abs() const
{
    int16_t byte_length = GetByteCapacity();
    char *new_value = (char *) malloc( byte_length );
    memcpy(new_value, this->value, byte_length);
    new_value[byte_length - 1] = binary_helper::extract_without_bit_sign( new_value[byte_length - 1] );
    
    return UnLimitedInt(new_value, byte_length);
}