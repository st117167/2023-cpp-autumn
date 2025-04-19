#include <iostream>

int main(int argc, char* argv[])
{
	int s1 = 15;
	int s5 = 70;
	int s10 = 125;
	int s20 = 230;
	int s60 = 440;
	int n = 0;
	int n1 = 0;
	int n5 = 0;
	int n10 = 0;
	int n20 = 0;
	int n60 = 0;
	std::cin >> n;
	n60 = n / 60;
	n20 = (n - 60 * n60) / 20;
	n10 = (n - 60 * n60 - 20 * n20) / 10;
	n5 = (n - 60 * n60 - 20 * n20 - 10 * n10) / 5;
	n1 = (n - 60 * n60 - 20 * n20 - 10 * n10 - 5 * n5);
	if (n1 * s1 + n5 * s5 >= 125)
	{
		n1 = 0;
		n5 = 0;
		n10 = n10 + 1;
	}
	if (n1 * s1 + n5 * s5 + n10 * s10 >= 230)
	{
		n1 = 0;
		n5 = 0;
		n10 = 0;
		n20 = n20 + 1;
	}
	if (n1 * s1 + n5 * s5 + n10 * s10 + n20 * s20 >= 440)
	{
		n1 = 0;
		n5 = 0;
		n10 = 0;
		n20 = 0;
		n60 = n60 + 1;
	}
	std::cout << n1 << " ";
	std::cout << n5 << " ";
	std::cout << n10 << " ";
	std::cout << n20 << " ";
	std::cout << n60 << " ";
	return 0;
}
