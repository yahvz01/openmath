
#include <ostream>

//using namespace openmath;

namespace openmath_helper {
    
    enum class CompResult
    {
        LARGE, SAME, SMALL
    };

    std::ostream& operator<<(std::ostream& os, const CompResult& value);

    CompResult reverse_CompResult(const CompResult& value);

    CompResult bit_comp_not_consider_sign_bit(const int8_t* lhs_ptr, const int8_t* rhs_ptr, int16_t byte_length);

    CompResult bit_comp(const int8_t* lhs, const int8_t* rhs, int16_t byte_length, bool has_signed);
}


// Implmented "==" "<" ">"
