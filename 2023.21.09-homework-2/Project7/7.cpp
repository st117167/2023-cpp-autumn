#include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int a = 0;
	int b = 0;
	std::cin >> x;
	a = x / 10;
	b = x % 10;
	if (a == 1)
		std::cout << "X";
	if (a == 2)
		std::cout << "XX";
	if (a == 3)
		std::cout << "XXX";
	if (a == 4)
		std::cout << "XL";
	if (a == 5)
		std::cout << "L";
	if (a == 6)
		std::cout << "LX";
	if (a == 7)
		std::cout << "LXX";
	if (a == 8)
		std::cout << "LXXX";
	if (a == 9)
		std::cout << "XC";
	if (a == 10)
		std::cout << "C";
	if (b == 1)
		std::cout << "I";
	if (b == 2)
		std::cout << "II";
	if (b == 3)
		std::cout << "III";
	if (b == 4)
		std::cout << "IV";
	if (b == 5)
		std::cout << "V";
	if (b == 6)
		std::cout << "VI";
	if (b == 7)
		std::cout << "VII";
	if (b == 8)
		std::cout << "VIII";
	if (b == 9)
		std::cout << "IX";
	return 0;
}