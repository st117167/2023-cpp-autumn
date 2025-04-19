#include<iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	for (int j = n - 1; j >= 0; j = j - 1) 
	{
		std::cout << *(a + j) << " ";
	}
	free(a);

	return 0;
}
