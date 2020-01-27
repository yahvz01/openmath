#include "openmath/FixedByteLengthIntBuffer.hpp"

#include "openmath/Binary.hpp"
#include "openmath/Bitwise.hpp"

using namespace openmath;

void FixedByteLengthIntBuffer::bit_left_shift(const int16_t& bit_shift)
{
    int8_t *result(nullptr);
    int16_t result_bit_length(left_bit_shift(this->GetValuePtr(), this->GetByteCapacity(), bit_shift, &result, false));
    
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}
void FixedByteLengthIntBuffer::bit_right_shift(const int16_t& bit_shift)
{
    int8_t *result(nullptr);
    int16_t result_bit_length(right_bit_shift(this->GetValuePtr(), this->GetByteCapacity(), bit_shift, &result, false));
    
    free(this->value_ptr);
    this->value_ptr = result;
    this->bit_length = result_bit_length;
}