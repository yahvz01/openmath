#include <iostream>
#include <iomanip>
#include <bitset>

#include "openmath/Binary.h"


int main(void)
{
	char lhs = 0b0001'0000;
	char rhs = 0b1110'1111;
	using namespace openmath;
	char value(0);	
	
	bool carry_out = openmath::full_adder(lhs, rhs, value, true);
	std::cout << std::boolalpha << carry_out << " " << std::bitset<8>(value) << std::endl;
	return 0;
}