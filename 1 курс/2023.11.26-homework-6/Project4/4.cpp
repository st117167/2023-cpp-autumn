#include<iostream>

void han(int k, int from, int to)
{
	if (k <= 0)
	{
		return;
	}
	else
	{
		if (k == 1)
		{
			std::cout << k << " " << from << " " << to << std::endl;
		}
		else
		{
			int res = 6 - from - to;
			han(k - 1, from, to);
			std::cout << k << " " << from << " " << res << std::endl;
			han(k - 1, to, from);
			std::cout << k << " " << res << " " << to << std::endl;
			han(k - 1, from, to);

		}
	}
}

int main(int argc, char* argv[])
{
	int mu = 0;
	std::cin >> mu;

	han(mu, 1, 3);

	return 0;
}
