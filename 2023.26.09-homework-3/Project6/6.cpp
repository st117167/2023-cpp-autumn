#include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int s1 = 0;
	int s2 = 1;
	int s3 = 0;
	int i = 0;
	std::cin >> x;
	for(i = 1; i < x + 1; i++)
	{
		s1 = s2 + s3;
		s2 = s3;
		s3 = s1;
	}
	std::cout << s1;
	return 0;
}