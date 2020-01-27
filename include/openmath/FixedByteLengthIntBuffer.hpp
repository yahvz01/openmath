#pragma once

#include <cstdint>

namespace openmath {
    class FixedByteLengthIntBuffer {
    public :
        explicit FixedByteLengthIntBuffer( const int8_t& value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const uint8_t& value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const int16_t& value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const uint16_t& value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const int32_t& value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const uint32_t& value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const int64_t & value, const int16_t& byte_capacity );
        explicit FixedByteLengthIntBuffer( const uint64_t & value, const int16_t& byte_capacity );

    // BitwiseOpt
    // return *this? or return void
    // Unary
        void bitwise_not();
        
    // Binary
        void bitwise_and(int8_t *value_ptr, const int16_t& value_byte_length);
        void bitwise_or(int8_t *value_ptr, const int16_t& value_byte_length);
        void bitwise_xor(int8_t *value_ptr, const int16_t& value_byte_length);

    // Bit Shift Opt 
        void bit_left_shift(const int16_t& shift_time);
        void bit_right_shift(const int16_t& shift_time);

    // Arithmetic Operation
        void sum(int8_t *value_ptr, const int16_t& value_byte_length);
        void subtract(int8_t *value_ptr, const int16_t& value_byte_length);
        void multiply(int8_t *value_ptr, const int16_t& value_byte_length);
        void divide(int8_t *value_ptr, const int16_t& value_byte_length);
        void remainder(int8_t *value_ptr, const int16_t& value_byte_length);

    // method
        bool IsPositive() const;
        int8_t* const GetValuePtr() const;
        int16_t GetBitLength() const;
        int16_t GetMeaningfullByteCapacity() const;
        int16_t GetByteCapacity() const;

    // Special-Member & Dtor
        FixedByteLengthIntBuffer( const FixedByteLengthIntBuffer& rhs);
        FixedByteLengthIntBuffer& operator=(const FixedByteLengthIntBuffer& rhs);
        FixedByteLengthIntBuffer( FixedByteLengthIntBuffer&& rhs);
        FixedByteLengthIntBuffer& operator=(FixedByteLengthIntBuffer&& rhs);
        ~FixedByteLengthIntBuffer();

    // private :
        FixedByteLengthIntBuffer(int8_t *value_ptr, int16_t bit_length, int16_t byte_capacity);
    private :
        int8_t *value_ptr;
        int16_t bit_length;
        int16_t byte_capacity;
    };
    using fintbuf = FixedByteLengthIntBuffer;
}