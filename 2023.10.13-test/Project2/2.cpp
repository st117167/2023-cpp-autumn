#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	{
		for (int i = 0; i < n; i = i + 1)
		{
			for (int j = 1; j <= n; j = j + 1)
			{
				std::cout << j;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 1; i <= n; i = i + 1)
		{
			for (int j = 1; j <= n; j = j + 1)
			{
				std::cout << i;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; i = i + 1)
		{
			for (int j = 0; j < n; j = j + 1)
			{
				std::cout << (i + j) % n + 1;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; i = i + 1)
		{
			for (int j = 9; j > 4; j = j - 1)
			{
				std::cout << j - i;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; i = i + 1)
		{
			for (int j = 0; j < n; j = j + 1)
			{
				std::cout << std::max(std::min(n - j, j + 1), std::min(n - i, i + 1));
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		for (int i = 0; i < n; i = i + 1)
		{
			for (int j = 0; j < n; j = j + 1)
			{
				std::cout << (i + 1) % 2 * (n - j) + i % 2 * (j + 1);
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
