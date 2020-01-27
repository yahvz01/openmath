#include "openmath/FixedByteLengthIntBuffer.hpp"

#include <cstdlib>
#include "openmath/Binary.hpp"

using namespace openmath;


void FixedByteLengthIntBuffer::sum(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > value_byte_length)? value_byte_length : this->GetByteCapacity() );
    int8_t* result(nullptr);
    int16_t result_bit_length( adder_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, valid_rhs_byte_length, &result, true, false));

    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void FixedByteLengthIntBuffer::subtract(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > value_byte_length)? value_byte_length : this->GetByteCapacity() );
    int8_t* complement( make_binary_complement_ptr(value_ptr, value_byte_length) );

    int8_t* result(nullptr);
    int16_t result_bit_length( adder_ptr(this->GetValuePtr(), this->GetByteCapacity(), complement, valid_rhs_byte_length, &result, true, false));
    
    free(complement);
    free(this->value_ptr);
    
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void FixedByteLengthIntBuffer::multiply(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t* result(nullptr);
    int16_t result_bit_length(multiply_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, &result, false));
    int16_t result_byte_length(bit_len_to_byte_len(result_bit_length));
    
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > result_byte_length)? result_byte_length : this->GetByteCapacity() );
    if(this->GetByteCapacity() > result_byte_length)
    {
        // fill empty space
        bool is_positive_of_result( is_positive_ptr(result, result_byte_length) );
        memset(this->value_ptr, (is_positive_of_result? 0b0000'0000 : 0b1111'1111), this->GetByteCapacity());
    }
    memcpy(this->value_ptr, result, valid_rhs_byte_length);

    free(result);
    this->bit_length = result_bit_length;
}
// 
void FixedByteLengthIntBuffer::divide(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t* result(nullptr);
    int16_t result_bit_length(divide_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, &result));
    int16_t result_byte_length(bit_len_to_byte_len(result_bit_length));
    
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > result_byte_length)? result_byte_length : this->GetByteCapacity() );
    if(this->GetByteCapacity() > result_byte_length)
    {
        bool is_positive_of_result( is_positive_ptr(result, result_byte_length) );
        memset(this->value_ptr, (is_positive_of_result? 0b0000'0000 : 0b1111'1111), this->GetByteCapacity());
    }
    memcpy(this->value_ptr, result, valid_rhs_byte_length);
    
    free(result);
    this->bit_length = result_bit_length;
}

void FixedByteLengthIntBuffer::remainder(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t* result(nullptr);
    int16_t result_bit_length(remainder_ptr(this->GetValuePtr(), this->GetByteCapacity(), value_ptr, value_byte_length, &result));
    int16_t result_byte_length(bit_len_to_byte_len(result_bit_length));
    
    int16_t valid_rhs_byte_length( (this->GetByteCapacity() > result_byte_length)? result_byte_length : this->GetByteCapacity() );
    if(this->GetByteCapacity() > result_byte_length)
    {
        bool is_positive_of_result( is_positive_ptr(result, result_byte_length) );
        memset(this->value_ptr, (is_positive_of_result? 0b0000'0000 : 0b1111'1111), this->GetByteCapacity());
    }
    memcpy(this->value_ptr, result, valid_rhs_byte_length);
    
    free(result);
    this->bit_length = result_bit_length;
}