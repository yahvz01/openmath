#include "openmath/UnLimitedInt.hpp"


using namespace openmath;

UnLimitedInt UnLimitedInt::operator+( const UnLimitedInt& rhs ) const
{
    if(this->IsPositive() && rhs.IsPositive())
    {

    }
    else if( (!this->IsPositive()) && (!rhs.IsPositive()) )
    {
        
    }
    else if( this->IsPositive() && (!rhs.IsPositive) )
    {
        
    }
    else
    {
        
    }

}

UnLimitedInt UnLimitedInt::operator-( const UnLimitedInt& rhs ) const
{
    
}

UnLimitedInt UnLimitedInt::operator*( const UnLimitedInt& rhs ) const
{
    // Booth's algorithm
    // remove unused byte and correct private member datahlb
}

UnLimitedInt UnLimitedInt::operator/( const UnLimitedInt& rhs ) const
{
    
}

UnLimitedInt UnLimitedInt::operator%( const UnLimitedInt& rhs ) const
{
    
}