#include<iostream>

void h(int n, int from = 1, int to = 3)
{
	if (n <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	if (n == 1)
	{
		std::cout << "1 " << from << " " << to << std::endl;
	}
	else
	{
		h(n - 1, from, to);
		h(n - 2, to, res);
		std::cout << "0 " << from << " "  << to << std::endl;
		h(n - 2, res, from);
		h(n - 1, from, to);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	h(n);

	return 0;
}
