#include<iostream>

class CGraph {

public:

	void inputAdjencyList(int a[101][101], int& n);
	void outputAdjencyList(int a[101][101], int n);

};

void CGraph::inputAdjencyList(int a[101][101], int& n)
{
	int edges = 0;
	std::cin >> n;
	std::cin >> edges;
	for (int i = 1; i <= edges; ++i)
	{
		int start = 0;
		int end = 0;
		std::cin >> start;
		std::cin >> end;
		a[start][end] = 1;
	}
}

void CGraph::outputAdjencyList(int a[101][101], int n)
{
	std::cout << n << std::endl;
	for (int i = 1; i <= n; ++i)
	{
		int count = 0;
		for (int j = 1; j <= n; ++j)
		{
			count += a[i][j];
		}
		std::cout << count << " ";
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
			{
				std::cout << j << " ";
			}
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
	Graph.outputAdjencyList(a, n);
}