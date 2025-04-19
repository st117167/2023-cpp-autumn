#include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int y = 0;
	std::cin >> x;
	std::cin >> y;
	if (x != 1 && y != 1 || x == 1 && y == 1)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return 0;
}
