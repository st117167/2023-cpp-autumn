#include<iostream>

class CGraph {

public:

	void inputAdjencyList(int a[101][101], int& n);
	void outputAdjencyList(int a[101][101], int n);
	void inputMatrix(int a[101][101], int& n);

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

void CGraph::inputAdjencyList(int a[101][101], int& n)
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int edges = 0;
		std::cin >> edges;
		for (int j = 0; j < edges; ++j)
		{
			int end = 0;
			std::cin >> end;
			a[i][end] = 1;
		}
	}
}

void CGraph::outputAdjencyList(int a[101][101], int n)
{
	int count = 0;
	std::cout << n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			count += a[i][j];
		}
	}
	std::cout << " " << count << std::endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
			{
				std::cout << i << " " << j << std::endl;
			}
		}
	}
}

int main(int argc, int argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph Graph;

	Graph.inputMatrix(a, n);
	Graph.outputAdjencyList(a, n);
}
