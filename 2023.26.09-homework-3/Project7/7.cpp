#include <iostream>

int main(int argc, char* argv[])
{
	int k = 1;
	int i = 0;
	int n = 0;
	std::cin >> n;
	while (k < n)
	{
		i = i + 1;
		k = k * 2;
	}
	std::cout << i;
	return 0;
}