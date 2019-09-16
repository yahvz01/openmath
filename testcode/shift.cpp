#include <iostream>
#include <bitset>

int main(void)
{
	unsigned char value(1);
	for(int i(0); i < 7; ++i)
	{
		value = value << 1;
		std::cout << std::bitset<16>(value) << std::endl;
	}
	for(int i(0); i < 7; ++i)
	{
		value = value >> 1;
		std::cout << std::bitset<16>(value) << std::endl;
	}
	return 0;
}
