#pragma once

#include <stdint.h>
#include <ostream>
/*
    For Little Endian
 */

#include <type_traits>

namespace openmath {
    class UnLimitedInt final
    {
    public :
        // non-explicit 
        UnLimitedInt( const char* value );
        UnLimitedInt( const std::string& value );

        UnLimitedInt( const int8_t& value );
        UnLimitedInt( const uint8_t& value );
        UnLimitedInt( const int16_t& value );
        UnLimitedInt( const uint16_t& value );
        UnLimitedInt( const int32_t& value );
        UnLimitedInt( const uint32_t& value );
        UnLimitedInt( const int64_t& value );
        UnLimitedInt( const uint64_t& value );

        UnLimitedInt operator~() const;
        UnLimitedInt bitwise_and( const UnLimitedInt& rhs) const;
        UnLimitedInt bitwise_or( const UnLimitedInt& rhs) const;
        UnLimitedInt bitwise_xor( const UnLimitedInt& rhs) const;
    
        bool equal( const UnLimitedInt& rhs) const;
        bool smaller( const UnLimitedInt& rhs) const;
        bool not_equal( const UnLimitedInt& rhs) const;
        bool greater_or_equal( const UnLimitedInt& rhs) const;
        bool greater( const UnLimitedInt& rhs) const;
        bool smaller_or_equal( const UnLimitedInt& rhs) const;
        
        UnLimitedInt operator<<(const int16_t& value);
        UnLimitedInt operator>>(const int16_t& value);
    
        bool IsPositive() const;
        uint16_t GetBitLength() const;
        uint16_t GetByteCapacity() const;
        int8_t* const GetValuePtr() const;
        UnLimitedInt abs() const;
        const std::string ToString() const;
    
    // Impl Done & Test Done
        UnLimitedInt( const UnLimitedInt& rhs);
        UnLimitedInt& operator=(const UnLimitedInt& rhs);
        UnLimitedInt( UnLimitedInt&& rhs );
        UnLimitedInt& operator=( UnLimitedInt&& rhs );
        ~UnLimitedInt();

    // private :    
        UnLimitedInt(int8_t *value_ptr, int16_t bit_length);
    private :
        int8_t *value;
        int16_t bit_length;
    };
    using bigint = UnLimitedInt;
}

openmath::bigint operator&(const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator|(const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator^(const openmath::bigint& lhs, const openmath::bigint& rhs);

bool operator==(const openmath::bigint& lhs, const openmath::bigint& rhs);
bool operator!=( const openmath::bigint& lhs, const openmath::bigint& rhs);
bool operator>=( const openmath::bigint& lhs, const openmath::bigint& rhs);
bool operator>( const openmath::bigint& lhs, const openmath::bigint& rhs);
bool operator<(const openmath::bigint& lhs, const openmath::bigint& rhs);
bool operator<=( const openmath::bigint& lhs, const openmath::bigint& rhs);

openmath::bigint operator+( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator-( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator*( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator/( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator%( const openmath::bigint& lhs, const openmath::bigint& rhs);

std::ostream& operator<<( std::ostream& os, const openmath::bigint& rhs );