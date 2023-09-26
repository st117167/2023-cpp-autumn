#include <iostream>

int main(int argc, char* argv[])
{
	int s = 0;
	int v = 0;
	int t = 0;
	std::cin >> v >> t;
	s = v * t;
	std::cout << (s + 109) % 109 + 1;
	return 0;
}