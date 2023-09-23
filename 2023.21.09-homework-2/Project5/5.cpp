#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	if (n % 10 == 1 && n % 100 != 11)
		std::cout << n << " bochka";
	else if (n % 10 >= 5 && n % 10 <= 9 || n % 100 >= 11 && n % 100 <= 14 || n % 10 == 0)
		std::cout << n << " bochek";
	else
		std::cout << n << " bochki";
	return 0;
}