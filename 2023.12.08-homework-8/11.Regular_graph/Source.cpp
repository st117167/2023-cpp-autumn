#include<iostream>

class CGraph {

public:

	void inputMatrix(int a[101][101], int& n);
	bool isRegular(int a[101][101], int n);

};

void CGraph::inputMatrix(int a[101][101], int& n)
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> a[i][j];
		}
	}
}

bool CGraph::isRegular(int a[101][101], int n)
{
	int powers[101] = { 0 };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			powers[i] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (powers[i] != powers[1])
		{
			std::cout << "NO";
			return false;
		}
	}
	std::cout << "YES";
	return true;
}

int main(int argc, int argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph Graph;

	Graph.inputMatrix(a, n);
	Graph.isRegular(a, n);
}
