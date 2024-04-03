#include<iostream>

class CGraph {

public:

	void inputMatrix(int a[101][101], int& n);
	std::string isOriented(int a[101][101], int n);

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

std::string CGraph::isOriented(int a[101][101], int n)
{
	std::string result = "NO";
	for (int i = 1; i <= n; ++i)
	{
		if (a[i][i] == 1)
		{
			result = "NO";
			break;
		}
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] != a[j][i])
			{
				result = "YES";
			}
		}
	}
	std::cout << result;
	return result;
}

int main(int argc, int argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph Graph;

	Graph.inputMatrix(a, n);
	Graph.isOriented(a, n);
}
