#include<iostream>

class CGraph {

public:

	void inputAdjencyList(int a[101][101], int& n);
	void outputMatrix(int a[101][101], int n);

};

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

void CGraph::outputMatrix(int a[101][101], int n)
{
	std::cout << n << std::endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, int argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph Graph;

	Graph.inputAdjencyList(a, n);
	Graph.outputMatrix(a, n);
}