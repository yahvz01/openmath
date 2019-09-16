#pragma once

#include <stdint.h>
#include <ostream>

namespace openmath {
    class UnLimitedInt final
    {
        // non-explicit 
        UnLimitedInt( const char* value );
        UnLimitedInt( const std::string& value );
        UnLimitedInt( const char& value );
        UnLimitedInt( const unsigned char& value );
        UnLimitedInt( const int8_t&  value);
        UnLimitedInt( const uint8_t&  value);
        UnLimitedInt( const int16_t&  value);
        UnLimitedInt( const uint16_t&  value);
        UnLimitedInt( const int32_t&  value);
        UnLimitedInt( const uint32_t&  value);
        UnLimitedInt( const int64_t & value );
        UnLimitedInt( const uint64_t & value );

        ~UnLimitedInt();

        bool operator==( const UnLimitedInt& rhs) const;
        bool operator<( const UnLimitedInt& rhs) const;
        bool operator!=( const UnLimitedInt& rhs) const;
        bool operator>=( const UnLimitedInt& rhs) const;
        bool operator>( const UnLimitedInt& rhs) const;
        bool operator<=( const UnLimitedInt& rhs) const;
        
        UnLimitedInt operator+( const UnLimitedInt& rhs ) const;
        UnLimitedInt operator-( const UnLimitedInt& rhs ) const;
        UnLimitedInt operator*( const UnLimitedInt& rhs ) const;
        UnLimitedInt operator/( const UnLimitedInt& rhs ) const;
        UnLimitedInt operator%( const UnLimitedInt& rhs ) const;

        bool operator&( const UnLimitedInt& rhs) const;
        bool operator|( const UnLimitedInt& rhs) const;
        bool operator^( const UnLimitedInt& rhs) const;
        
        UnLimitedInt abs() const;
    public :
        bool IsPositive() const;
        uint16_t GetBitLength() const;
        uint16_t GetByteCapacity() const;
        
    private :
        explicit UnLimitedInt(char *value_ptr, uint8_t length);
        // char
        uint8_t *value;
        // 0 ~ 65'536 digit
        uint16_t bit_length;
    };

    using bigint = UnLimitedInt;
}

openmath::bigint operator+( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator-( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator*( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator/( const openmath::bigint& lhs, const openmath::bigint& rhs);
openmath::bigint operator%( const openmath::bigint& lhs, const openmath::bigint& rhs);

std::ostream& operator<<( std::ostream& os, const openmath::bigint& rhs );