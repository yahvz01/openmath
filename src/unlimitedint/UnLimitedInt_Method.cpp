#include "openmath/UnLimitedInt.hpp"

#include "openmath/Binary.hpp"


using namespace openmath;

bool UnLimitedInt::IsPositive() const
{
    auto biggest_pos_byte = this->value[this->GetByteCapacity() - 1];
    return !(biggest_pos_byte & SIGN_BIT_POS);
}

uint16_t UnLimitedInt::GetBitLength() const
{
    return this->bit_length;
}

uint16_t UnLimitedInt::GetByteCapacity() const
{
    return  (this->bit_length / 8) + 1;
}

int8_t* const UnLimitedInt::GetValuePtr() const
{
    // We need to instinctially fix it (first pointer is not represent MSB)
    return this->value;
}

const std::string UnLimitedInt::ToString() const
{
    
}

UnLimitedInt UnLimitedInt::abs() const
{
    // abs == make_complement
    if(this->IsPositive())
        return UnLimitedInt(*this);
    else
    {
        // need debug
        int8_t *new_value_ptr = make_binary_complement_ptr(this->value, this->GetByteCapacity());
        return UnLimitedInt(new_value_ptr, this->GetBitLength());
    }
}