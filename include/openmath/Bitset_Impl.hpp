#pragma once

#include "Bitset.hpp"

#include <bitset>
//{   std::bitset<N>(value);  }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const int8_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const uint8_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const int16_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const uint16_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const int32_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const uint32_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const int64_t& value)
{   this->basic_int_store(value);   }
template <std::size_t N>
openmath::Bitset<N>::Bitset(const uint64_t& value)
{   this->basic_int_store(value);   }

template <std::size_t N>
const int8_t* const openmath::Bitset<N>::GetValuePtr() const
{
    return this->user_defined_value_ptr;
}

template <std::size_t N>
std::ostream& operator<<( std::ostream& os, const openmath::Bitset<N>& rhs)
{
    const int8_t* const value_ptr(rhs.GetValuePtr());
    if(rhs.GetValuePtr() != nullptr)
    {
        // return user_defined_value
    }
    else
    {
        // return basic_int_value
    }
}