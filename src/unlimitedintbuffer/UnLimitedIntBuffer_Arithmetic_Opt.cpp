#include "openmath/UnLimitedIntBuffer.hpp"

#include <cstdlib>
#include "openmath/Binary.hpp"

using namespace openmath;


void UnLimitedIntBuffer::sum(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > value_byte_length)? value_byte_length : this->GetByteCapacity() );
    int8_t* result(nullptr);
    int16_t result_bit_length( adder_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, valid_rhs_byte_length, &result, false, false));

    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void UnLimitedIntBuffer::subtract(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > value_byte_length)? value_byte_length : this->GetByteCapacity() );
    int8_t* complement( make_binary_complement_ptr(value_ptr, value_byte_length) );

    int8_t* result(nullptr);
    int16_t result_bit_length( adder_ptr(this->GetValuePtr(), this->GetByteCapacity(), complement, valid_rhs_byte_length, &result, false, false));
    
    free(complement);
    free(this->value_ptr);
    
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void UnLimitedIntBuffer::multiply(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(multiply_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, &result_ptr, false));
    
    free(this->value_ptr);
    this->value_ptr = result_ptr;
    this->bit_length = result_bit_length;
}
// 
void UnLimitedIntBuffer::divide(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(divide_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, &result_ptr));
    
    free(this->value_ptr);
    this->value_ptr = result_ptr;
    this->bit_length = result_bit_length;
}

void UnLimitedIntBuffer::remainder(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t* result_ptr(nullptr);
    int16_t result_bit_length(remainder_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, &result_ptr));
    
    free(this->value_ptr);
    this->value_ptr = result_ptr;
    this->bit_length = result_bit_length;
}