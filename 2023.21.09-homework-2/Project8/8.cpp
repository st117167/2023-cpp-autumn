/*#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a <= b && a <= c)
	{
		if (b < c)
			std::cout << a << " " << b << " " << c;
		else
			std::cout << a << " " << c << " " << b;
		return 0;
	}
	if (b <= a && b <= c)
	{
		if (a < c)
			std::cout << b << " " << a << " " << c;
		else
			std::cout << b << " " << c << " " << a;
		return 0;
	}
	if (c <= a && c <= b)
	{
		if (a < b)
			std::cout << c << " " << a << " " << b;
		else
			std::cout << c << " " << b << " " << a;
		return 0;
	}
	return 0;
}
для подстраховки*/
#include <iostream>

void swap(int* a, int* b) // если swap-ом нельзя, тогда, пожалуйста, запустите прогу, что выше (в комменте)
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
		std::swap(x, y);
	if (y > z)
		std::swap(y, z);
	if (x > z)
		std::swap(x, y);
	std::cout << x << " " << y << " " << z;
	return 0;
}