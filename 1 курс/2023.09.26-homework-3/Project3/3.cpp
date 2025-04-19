#include <iostream>

int main(int argc, char* argv[])
{
	int i = 0;
	int x = 0;
	int k = 0;
	int s = 0;
	std::cin >> x;
	while (s * s < x)
	{
		s = s + 1;
	}
	if (x != 1)
	{
		for (i = 1; i <= s - 1; i++)
		{
			if (x % i == 0)
			{
				k = k + 2;
			}
		}
		if (s * s == x)
		{
			k = k + 1;
		}
		std::cout << k;
	}
	else
	{
		std::cout << '1';
	}
	return 0;
}
