#include <iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	int s = 0;
	int t = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	s = n / k + 1;
	t = s * m;
	std::cout << t;
	return 0;
}