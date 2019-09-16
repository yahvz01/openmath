#include "openmath/UnLimitedInt.hpp"
#include "openmath/Binary_Helper.h"

using namespace openmath;
using namespace binary_helper;




bool UnLimitedInt::operator==( const UnLimitedInt& rhs) const
{   
    if(this->bit_length != rhs.bit_length)
        return false;
    
    bool result(true);
    auto max_idx(this->GetByteCapacity());

    for(decltype(max_idx) idx(0); idx < max_idx; ++idx)
    {
        if( this->value[idx] != rhs.value[idx] )
        {
            result = false;
            break;
        }   
    }
    return result;
}

bool UnLimitedInt::operator<( const UnLimitedInt& rhs) const
{
    // sign bit checking
    bool lhs_positive = IsPositive();
    bool rhs_positive = rhs.IsPositive();
    if(lhs_positive && !rhs_positive )
        return false;
    else if(!lhs_positive && rhs_positive )
        return true;
    else
    {
        // Length check
        bool length_comp_bigger = this->bit_length > rhs.bit_length;
        bool length_comp_smaller= this->bit_length < rhs.bit_length;
        if(lhs_positive && rhs_positive)
        {
            if(length_comp_bigger)
                return false;
            else if( length_comp_smaller)
                return true;
            else
            {
                bool result(true);
                for(int32_t idx(GetByteCapacity() - 1); idx >= 0; --idx)
                {
                    if(this->value[idx] > rhs.value[idx])
                    {
                        result = false;
                        break;
                    }
                }
                return result;
            }
        }
        else
        {
            if(length_comp_bigger)
                return true;
            else if( length_comp_smaller)
                return false;
            else
            {
                bool result(true);
                int32_t idx(GetByteCapacity() - 1);
                if(extract_without_bit_sign(this->value[idx]) < extract_without_bit_sign(rhs.value[idx]))
                    return false;
                --idx;
                for(; idx >= 0; --idx)
                {
                    if(this->value[idx] < rhs.value[idx])
                    {
                        result = false;
                        break;
                    }
                }
                return result;
            }
        }
    }
}

bool UnLimitedInt::operator>( const UnLimitedInt& rhs) const
{
    return !(operator==(rhs)) && !(operator<(rhs));
}

bool UnLimitedInt::operator!=( const UnLimitedInt& rhs) const
{
        return !(operator!=(rhs));
}
bool UnLimitedInt::operator>=( const UnLimitedInt& rhs) const
{
        return !(operator<(rhs));
}
bool UnLimitedInt::operator>( const UnLimitedInt& rhs) const
{
        return !(operator==(rhs)) && !(operator<(rhs));
}
bool UnLimitedInt::operator<=( const UnLimitedInt& rhs) const
{
        return !(operator>(rhs));
}