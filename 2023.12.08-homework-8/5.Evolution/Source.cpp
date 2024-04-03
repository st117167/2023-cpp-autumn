#include<iostream>

class CGraph {

public:
	void Evolution(int n, int first, int second)
	{
		while (first != second)
		{
			if (first > second)
			{
				first = first >> 1;
			}
			else
			{
				second = second >> 1;
			}
		}
		std::cout << first;
	}
};

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	long long int first = 0;
	std::cin >> first;

	long long int second = 0;
	std::cin >> second;

	CGraph Graph;

	Graph.Evolution(n, first, second);

	return 0;
}

