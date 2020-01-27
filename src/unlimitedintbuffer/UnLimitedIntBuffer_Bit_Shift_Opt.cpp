#include "openmath/UnLimitedIntBuffer.hpp"

#include <cstdlib>
#include "openmath/Bitwise.hpp"

#include <iostream>
#include <bitset>


using namespace openmath;

void UnLimitedIntBuffer::bit_left_shift(const int16_t& shift_jump)
{
    
    bool debug(this->GetByteCapacity() == 2);
    int8_t *result(nullptr);
    int16_t result_bit_length( left_bit_shift(this->GetValuePtr(), this->GetByteCapacity(), shift_jump, &result, true) );
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}

void UnLimitedIntBuffer::bit_right_shift(const int16_t& shift_jump)
{
    int8_t *result(nullptr);
    
    int16_t result_bit_length( right_bit_shift(this->GetValuePtr(), this->GetByteCapacity(), shift_jump, &result, true) );
    
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}