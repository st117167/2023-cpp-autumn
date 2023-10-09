#include<iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	int k = 0;
	for (int i = 0; i < n; i = i + 1)
	{
		std::cin >> *(a + i);
		if (*(a + i) > 0)
			k = k + 1;
	}

	std::cout << k;
	return 0;
}
