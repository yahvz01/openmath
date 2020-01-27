#pragma once


#include <cstdint>
#include <ostream>
#include "openmath/FixedByteLengthIntBuffer.hpp"
#include "openmath/FixedByteLengthInt.hpp"
#include "openmath/UnLimitedIntBuffer.hpp"
#include "openmath/UnLimitedInt.hpp"


// openmath::Bitset is proxy of out-stream of openmath's user defined classes.
namespace openmath {

    template <std::size_t N>
    class Bitset {
        // basic operation is not property
        Bitset( const int8_t&  value);
        Bitset( const uint8_t&  value);
        Bitset( const int16_t&  value);
        Bitset( const uint16_t&  value);
        Bitset( const int32_t&  value);
        Bitset( const uint32_t&  value);
        Bitset( const int64_t & value );
        Bitset( const uint64_t & value );
        // main function
        Bitset( const openmath::FixedByteLengthIntBuffer& value);
        Bitset( const openmath::FixedByteLengthInt& value);
        Bitset( const openmath::UnLimitedIntBuffer& value);
        Bitset( const openmath::UnLimitedInt& value);

        const int8_t* const GetValuePtr() const;

        template <std::size_t N>
        friend std::ostream& operator<<( std::ostream& os, const openmath::bitset<N>& rhs);
        
        
    private :
        uint64_t basic_int_store(0);
        int8_t* user_defined_value_ptr(nullptr);
    };
}

#include "Bitset_Impl.hpp"