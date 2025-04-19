#include<iostream>

void hanoi(int k, int from, int to)
{
	if (k <= 0)
	{
		return;
	}
	else 
	{
		if (from + to == 4)
		{
			hanoi(k, from, 2);
			hanoi(k, 2, to);
		}
		else
		{
			int res = 6 - from - to;
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
