#include<iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int max = 0;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i = i + 1)
	{
		std::cin >> *(a + i);
		max = *(a);
		if (*(a + i) > max) 
		{
			max = *(a + i);
		}
	}
	free(a);

	std::cout << max;
	return 0;
}
