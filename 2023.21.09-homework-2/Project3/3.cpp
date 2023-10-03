#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	if (a == b && a == 0)
	{
		std::cout << "IMF";
	}
	else if (a == 0 || b % a != 0 || a * d == b * c || c == 0 && d == 0)
	{
		std::cout << "NO";
	}
	else if ((-b) % a == 0)
	{
		std::cout << -b / a << std::endl;
	}
	else
	{
		std::cout << "NO";
	}
	return 0;
}
