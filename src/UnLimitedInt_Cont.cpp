#include "openmath/UnLimitedInt.hpp"`

using namespace openmath;

/*
    char * => 
    바이트 단위로 Parsing 해서
    0b1001
    8byte 128
 */

UnLimitedInt::UnLimitedInt( const char* value )
{

}
UnLimitedInt::UnLimitedInt( const std::string& value )
{

}
UnLimitedInt::UnLimitedInt( const char& value )
{

}
UnLimitedInt::UnLimitedInt( const unsigned char& value )
{

}
UnLimitedInt::UnLimitedInt( const int8_t&  value)
{

}
UnLimitedInt::UnLimitedInt( const uint8_t&  value)
{

}
UnLimitedInt::UnLimitedInt( const int16_t&  value)
{

}
UnLimitedInt::UnLimitedInt( const uint16_t&  value)
{

}
UnLimitedInt::UnLimitedInt( const int32_t&  value)
{

}
UnLimitedInt::UnLimitedInt( const uint32_t&  value)
{

}
UnLimitedInt::UnLimitedInt( const int64_t & value )
{

}
UnLimitedInt::UnLimitedInt( const uint64_t & value )
{

}


UnLimitedInt::~UnLimitedInt()
{
    delete [] value;
}