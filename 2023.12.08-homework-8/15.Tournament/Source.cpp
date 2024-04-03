#include<iostream>

class CGraph {

public:

	void inputEdges(int a[101][101], int& n);
	bool tournament(int a[101][101], int n);

};

bool CGraph::tournament(int a[101][101], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i][i] == 1)
		{
			return false;
		}
		for (int j = i + 1; j <= n; ++j)
		{
			if (a[i][j] + a[j][i] != 1)
			{
				std::cout << "NO";
				return false;
			}
		}
	}
	std::cout << "YES";
	return true;
}
void CGraph::inputEdges(int a[101][101], int& n)
{
	std::cin >> n;
	int m = 0;
	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int s = 0;
		int e = 0;
		std::cin >> s >> e;
		a[s][e] += 1;
	}

	tournament(a, n);
}

int main(int argc, int argv[])
{
	int a[101][101]{ 0 };
	int n = 0;
	int m = 0;

	CGraph Graph;

	Graph.inputEdges(a, n);

}
