#include "openmath/UnLimitedIntBuffer.hpp"

#include <cstdlib>
#include <cstring>
#include "openmath/Binary.hpp"
#include "openmath_helper/UnLimitedIntClassHelper.hpp"

using namespace openmath;
using namespace openmath_helper;

  
UnLimitedIntBuffer::UnLimitedIntBuffer( const int8_t& input_value)
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const uint8_t& input_value)
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const int16_t& input_value)
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const uint16_t& input_value)
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const int32_t& input_value)
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const uint32_t& input_value)
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const int64_t& input_value )
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

UnLimitedIntBuffer::UnLimitedIntBuffer( const uint64_t& input_value )
{   bit_length = get_bit_length_and_set_value(input_value, &this->value_ptr);   }

// private Ctor
UnLimitedIntBuffer::UnLimitedIntBuffer(int8_t *input_value_ptr, int16_t bit_length)
    : value_ptr(input_value_ptr), bit_length(bit_length)
{   
    int16_t byte_length(bit_len_to_byte_len(bit_length));
    int16_t valid_bit_length = get_digit_binary_number_ptr(input_value_ptr, true, byte_length);
        
    // reallocate heap memory
    if( valid_bit_length < bit_length )
    {  
        bool has_less_then_byte_valid( valid_bit_length % 8 );
        int16_t byte_length_valid( ((valid_bit_length) / 8) + (has_less_then_byte_valid? 1:0) );
        this->value_ptr = shrink_unlimitedint_memory_and_free(input_value_ptr, byte_length, byte_length_valid);
        this->bit_length = valid_bit_length;
    }
}