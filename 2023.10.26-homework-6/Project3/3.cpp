#include<iostream>

void hanoi(int k, int from, int to)
{
	if (k <= 0)
	{
		return;
	}
	else
	{
		int res = 6 - from - to;

		if (from == 1 && to == 3 || from == 2 && to == 1 || from == 3 && to == 2)
		{
			hanoi(k - 1, from, to);
			std::cout << k << " " << from << " " << res << std::endl;
			hanoi(k - 1, to, from);
			std::cout << k << " " << res << " " << to << std::endl;
			hanoi(k - 1, from, to);
		}
		else
		{
			hanoi(k - 1, from, res);
			std::cout << k << " " << from << " " << to << std::endl;
			hanoi(k - 1, res, to);
		}
	}
}

int main(int argc, char* argv[])
{
	int mu = 0;
	std::cin >> mu;

	hanoi(mu, 1, 3);

	return 0;
}
