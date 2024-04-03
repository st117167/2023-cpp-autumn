#include<iostream>

class CGraph {

public:

	void inputMatrix(int a[101][101], int& n);
	void Degree(int a[101][101], int n);
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

void CGraph::Degree(int a[101][101], int n)
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
		std::cout << powers[i] << " ";
	}
}


int main(int argc, int argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph Graph;

	Graph.inputMatrix(a, n);
	Graph.Degree(a, n);
}
