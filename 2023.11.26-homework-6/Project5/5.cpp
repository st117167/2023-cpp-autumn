#include<iostream>

void h(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}
	int res = 6 - from - to;

	h(n - 1, from, res);
	std::cout << n << " " << from << " " << to << std::endl;
	h(n - 1, res, to);
}

int main(int argc, char* argv[])
{
	int count = 0;
	std::cin >> count;

	int from = 1;
	int to = 0;


	if (count % 2 == 0)
	{
		to = 3;
	}
	else
	{
		to = 2;
	}

	h(count, from, to);

	int res = 5 - to;

	for (int i = count; i > 0; i = i - 1)
	{
		h(i - 1, to, res);
		std::swap(to, res);
	}

	return 0;
}
