#include<iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i = i + 1)
	{
		std::cin >> *(a + i);
		if (i % 2 == 0)
		{
			std::cout << *(a + i) << " ";
		}
	}
	free(a);

	return 0;
}
