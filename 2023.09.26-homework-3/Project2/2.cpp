#include <iostream>

int main(int argc, char* argv[])
{
	int i = 0;
	int x = 0;
	std::cin >> x;
	while (x % 10 == 0)
	{
		x = x / 10;
	}
	while (x != 0)
	{
		std::cout << x % 10;
		x = x / 10;
	}
	return 0;
}
