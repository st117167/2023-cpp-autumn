#include <iostream>

int main(int argc, char* argv[])
{
	int i = 0;
	int n = 0;
	int x = 0;
	int s = 0;
	int e = 0;
	int k = 0;
	std::cin >> n;
	for (i = 1; i <= n; i = i + 1)
	{
		x = i;
		e = x % 10;
		s = e;
		x = x / 10;
		while (x > 0)
		{
			e = x % 10;
			x = x / 10;
			s = s * 10;
			s = s + e;
		}
		if (s == i)
			k = k + 1;
	}
	std::cout << k;
	return 0;
}