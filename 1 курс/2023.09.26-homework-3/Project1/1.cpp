#include <iostream>

int main(int argc, char* argv[])
{
	int i = 0;
	int j = 1;
	int n = 1;
	int k = 0;
	int t = 0;
	std::cin >> t;
	while (j < t)
	{
		for (i = 1; i <= n; i = i + 1)
		{
			std::cout << n << " ";
		}
		n = n + 1;
		j = j + n;
	}
	k = j - n;
	for (k; k < t; k = k + 1)
	{
		std::cout << n << " ";
	}
	return 0;
}
