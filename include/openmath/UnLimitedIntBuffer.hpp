#pragma once

#include <cstdint>

namespace openmath {
    class UnLimitedIntBuffer {
    public :
        UnLimitedIntBuffer( const int8_t& value );
        UnLimitedIntBuffer( const uint8_t& value );
        UnLimitedIntBuffer( const int16_t& value );
        UnLimitedIntBuffer( const uint16_t& value );
        UnLimitedIntBuffer( const int32_t& value );
        UnLimitedIntBuffer( const uint32_t& value );
        UnLimitedIntBuffer( const int64_t& value );
        UnLimitedIntBuffer( const uint64_t& value );

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
        int16_t GetByteCapacity() const;

    // Special-Member & Dtor
        UnLimitedIntBuffer( const UnLimitedIntBuffer& rhs);
        UnLimitedIntBuffer& operator=(const UnLimitedIntBuffer& rhs);
        UnLimitedIntBuffer( UnLimitedIntBuffer&& rhs);
        UnLimitedIntBuffer& operator=(UnLimitedIntBuffer&& rhs);
        ~UnLimitedIntBuffer();

    // private :
        UnLimitedIntBuffer(int8_t *value_ptr, int16_t bit_length);
    private :
        int8_t *value_ptr;
        int16_t bit_length;
    };
    using fintbuf = UnLimitedIntBuffer;
};