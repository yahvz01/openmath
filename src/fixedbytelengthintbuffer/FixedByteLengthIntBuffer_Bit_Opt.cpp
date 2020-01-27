#include "openmath/FixedByteLengthIntBuffer.hpp"

#include <cstdlib>
#include "openmath/Bitwise.hpp"

using namespace openmath;

/*
 *  this->byte_capacity 유지  
 */

void FixedByteLengthIntBuffer::bitwise_not()
{
    int8_t* result(nullptr);
    int16_t result_bit_length(bitwise_not_opt_ptr(this->value_ptr, this->byte_capacity, &result));
    
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void FixedByteLengthIntBuffer::bitwise_and(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t *result(nullptr);
    int16_t result_bit_length(bitwise_opt_ptr(this->value_ptr, this->GetBitLength(), value_ptr, value_byte_length, bitwise_and_single_byte, &result, false));
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}
void FixedByteLengthIntBuffer::bitwise_or(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t *result(nullptr);
    int16_t result_bit_length(bitwise_opt_ptr(this->value_ptr, this->GetBitLength(), value_ptr, value_byte_length, bitwise_or_single_byte, &result, false));
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}
void FixedByteLengthIntBuffer::bitwise_xor(int8_t *value_ptr, const int16_t& value_byte_length)
{
    int8_t *result(nullptr);
    int16_t result_bit_length(bitwise_opt_ptr(this->value_ptr, this->GetBitLength(), value_ptr, value_byte_length, bitwise_xor_single_byte, &result, false));
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}