#include "openmath/UnLimitedIntBuffer.hpp"

#include <algorithm>
#include <cstdlib>

#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"
#include "openmath_helper/UnLimitedIntClassHelper.hpp"

using namespace openmath;
using namespace openmath_helper;

void UnLimitedIntBuffer::bitwise_not()
{
    int8_t* result(nullptr);
    int16_t result_bit_length( bitwise_not_opt_ptr(this->GetValuePtr(), this->GetByteCapacity(), &result) );
    
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void UnLimitedIntBuffer::bitwise_and(int8_t* value_ptr, const int16_t& value_byte_length)
{
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length( bitwise_opt_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, bitwise_and_single_byte, &result_ptr, true) );
    free(this->value_ptr);
    this->value_ptr = result_ptr;
    this->bit_length = result_bit_length;
}

void UnLimitedIntBuffer::bitwise_or(int8_t* value_ptr, const int16_t& value_byte_length)
{  
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length( bitwise_opt_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, bitwise_or_single_byte, &result_ptr, true) );
    free(this->value_ptr);
    this->value_ptr = result_ptr;
    this->bit_length = result_bit_length;
}


void UnLimitedIntBuffer::bitwise_xor(int8_t* value_ptr, const int16_t& value_byte_length)
{
    int8_t *result_ptr(nullptr);
    int16_t result_bit_length( bitwise_opt_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, bitwise_xor_single_byte, &result_ptr, true) );
    free(this->value_ptr);
    this->value_ptr = result_ptr;
    this->bit_length = result_bit_length;
}