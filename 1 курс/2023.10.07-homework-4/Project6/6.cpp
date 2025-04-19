#include<iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int max = 0;
	int min = 0;
	int* a = (int*)malloc(sizeof(int) * n);

	max = -1000000;
	min = 1000000;
	
	for (int i = 0; i < n; i = i + 1)
	{
		std::cin >> *(a + i);

		if (*(a + i) > max)
		{
			max = *(a + i);
		}

		if (*(a + i) < min)
		{
			min = *(a + i);
		}
	}

	for (int i = n - 1; i >= 0; i = i - 1)
	{
		if (*(a + i) == max)
		{
			*(a + i) = min;
			break;
		}
	}

	for (int i = 0; i < n; i = i + 1)
	{
		if (*(a + i) == min)
		{
			*(a + i) = max;
			break;
		}
	}

	for (int i = 0; i < n; i = i + 1)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);

	return 0;
}
