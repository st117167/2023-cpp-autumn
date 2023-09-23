#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	int s4 = 0;
	int s5 = 0;
	std::cin >> n;
	s1 = n / 60;
	s2 = n % 60 / 20;
	s3 = n % 60 % 20 / 10;
	s4 = n % 60 % 20 % 10 / 5;
	s5 = n % 5;
	std::cout << s5 << " " << s4 << " " << s3 << " " << s2 << " " << s1;
	return 0;
}