#include "openmath/FixedByteLengthIntBuffer.hpp"

#include <stdexcept>

#include "openmath/Binary.hpp"
#include "openmath_helper/FixedByteLengthClassHelper.hpp"

using namespace openmath;
using namespace openmath_helper;


FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const int8_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const uint8_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const int16_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const uint16_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const int32_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const uint32_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const int64_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }

FixedByteLengthIntBuffer::FixedByteLengthIntBuffer( const uint64_t& value, const int16_t& byte_capacity )
    : byte_capacity(byte_capacity)
{ bit_length = data_copy_get_length_in_fixed_bit(value, byte_capacity, &this->value_ptr); }


FixedByteLengthIntBuffer::FixedByteLengthIntBuffer(int8_t *value_ptr, int16_t value_bit_length, int16_t byte_capacity)
{
    // validation bit_length & byte_capacity
    if((value_bit_length / 8) > byte_capacity)
        throw std::invalid_argument("FixedByteLengthIntBuffer : bit_length is over byte_capacity");

    int16_t invalid_bit_capacity(value_bit_length);
    int16_t input_byte_length(bit_len_to_byte_len(value_bit_length));

    int8_t* result_ptr( static_cast<int8_t*>( malloc(byte_capacity) ) );
    bool is_positive(is_positive_ptr(value_ptr, input_byte_length));
    
    if(input_byte_length > byte_capacity)
    {
        invalid_bit_capacity = (byte_capacity * 8);
        memcpy(result_ptr, value_ptr, byte_capacity);
    }
    else
    {
        memset(result_ptr, (is_positive ? 0 : 0b1111'1111), byte_capacity);
        memcpy(result_ptr, value_ptr, input_byte_length);
    }
    free(value_ptr);
    this->value_ptr = result_ptr;
    this->byte_capacity = byte_capacity;
    this->bit_length = get_digit_binary_number_ptr(this->value_ptr, true, this->byte_capacity);
}