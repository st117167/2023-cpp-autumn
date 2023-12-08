#include<iostream>

void hanoi(int k, int from, int to)
{
	if (k <= 0)
	{
		return;
	}

	int res = 6 - from - to;
	hanoi(k - 1, from, res);
	std::cout << k << " " << from << " " << to << std::endl;
	hanoi(k - 1, res, to);
}

int main(int argc, char* argv[])
{
	int mu = 0;
	std::cin >> mu;
	hanoi(mu, 1, 3);

	return 0;
}
