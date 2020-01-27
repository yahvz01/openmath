#pragma once

#include <cstdint>
#include <ostream>

namespace openmath {
    class FixedByteLengthInt
    {
    public :
        FixedByteLengthInt( const int8_t&  value, const int16_t& bit_capacity = 1);
        FixedByteLengthInt( const uint8_t&  value, const int16_t& bit_capacity = 1);
        FixedByteLengthInt( const int16_t&  value, const int16_t& bit_capacity = 2);
        FixedByteLengthInt( const uint16_t&  value, const int16_t& bit_capacity = 2);
        FixedByteLengthInt( const int32_t&  value, const int16_t& bit_capacity = 4);
        FixedByteLengthInt( const uint32_t&  value, const int16_t& bit_capacity = 4);
        FixedByteLengthInt( const int64_t & value , const int16_t& bit_capacity = 8);
        FixedByteLengthInt( const uint64_t & value , const int16_t& bit_capacity = 8);

        FixedByteLengthInt operator~() const;
        FixedByteLengthInt bitwise_and( const FixedByteLengthInt& rhs) const;
        FixedByteLengthInt bitwise_or( const FixedByteLengthInt& rhs) const;
        FixedByteLengthInt bitwise_xor( const FixedByteLengthInt& rhs) const;

        bool equal( const FixedByteLengthInt& rhs) const;
        bool smaller( const FixedByteLengthInt& rhs) const;
        bool not_equal( const FixedByteLengthInt& rhs) const;
        bool greater_or_equal( const FixedByteLengthInt& rhs) const;
        bool greater( const FixedByteLengthInt& rhs) const;
        bool smaller_or_equal( const FixedByteLengthInt& rhs) const;

        FixedByteLengthInt operator<<(const int8_t& value);
        FixedByteLengthInt operator<<(const int16_t& value);
        FixedByteLengthInt operator<<(const int32_t& value);
        FixedByteLengthInt operator<<(const int64_t& value);
        FixedByteLengthInt operator>>(const int8_t& value);
        FixedByteLengthInt operator>>(const int16_t& value);
        FixedByteLengthInt operator>>(const int32_t& value);
        FixedByteLengthInt operator>>(const int64_t& value);

        bool IsPositive() const;
        int16_t GetBitLength() const;
        int16_t GetMeaningfullByteCapacity() const;
        int16_t GetByteCapacity() const;
        int8_t* const GetValuePtr() const;
        FixedByteLengthInt abs() const;
        const std::string ToString() const;

        FixedByteLengthInt( const FixedByteLengthInt& rhs);
        FixedByteLengthInt& operator=(const FixedByteLengthInt& rhs);
        FixedByteLengthInt( FixedByteLengthInt&& rhs);
        FixedByteLengthInt& operator=(FixedByteLengthInt&& rhs);
        ~FixedByteLengthInt();

    // private :    
        FixedByteLengthInt(int8_t *value_ptr, int16_t bit_length, int16_t byte_capacity);
    private :
        int8_t *value_ptr;
        int16_t bit_length;
        int16_t byte_capacity;
    };

    using fbint = FixedByteLengthInt;
}

openmath::fbint operator&(const openmath::fbint& lhs, const openmath::fbint& rhs);
openmath::fbint operator|(const openmath::fbint& lhs, const openmath::fbint& rhs);
openmath::fbint operator^(const openmath::fbint& lhs, const openmath::fbint& rhs);

bool operator==(const openmath::fbint& lhs, const openmath::fbint& rhs);
bool operator!=( const openmath::fbint& lhs, const openmath::fbint& rhs);
bool operator>=( const openmath::fbint& lhs, const openmath::fbint& rhs);
bool operator>( const openmath::fbint& lhs, const openmath::fbint& rhs);
bool operator<(const openmath::fbint& lhs, const openmath::fbint& rhs);
bool operator<=( const openmath::fbint& lhs, const openmath::fbint& rhs);

openmath::fbint operator+( const openmath::fbint& lhs, const openmath::fbint& rhs);
openmath::fbint operator-( const openmath::fbint& lhs, const openmath::fbint& rhs);
openmath::fbint operator*( const openmath::fbint& lhs, const openmath::fbint& rhs);
openmath::fbint operator/( const openmath::fbint& lhs, const openmath::fbint& rhs);
openmath::fbint operator%( const openmath::fbint& lhs, const openmath::fbint& rhs);

std::ostream& operator<<( std::ostream& os, const openmath::fbint& rhs );