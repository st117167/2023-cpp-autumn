#include <iostream>

void swap(int* a, int* b)
	{
		a = b;
		b = a;
	}

int main(int argc, char* argv[])
{
	int x = 0;
	int y = 0;
	int z = 0;
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;
	if (x > y)
	{
		std::swap(x, y);
	}
	if (y > z)
	{
		std::swap(y, z);
	}
	if (x > z)
	{
		std::swap(x, y);
	}
	std::cout << x << " " << y << " " << z;
	return 0;
}
