#include<iostream>

class CGraph {

public:

	void inputMatrix(bool a[101][101], int n);
	void check_colour(bool a[101][101], int colors[101], int n);
	

};

int main(int argc, char* argv[])
{
	bool a[101][101]{ 0 };

	int n = 0;
	std::cin >> n;

	CGraph Graph;

	Graph.inputMatrix(a, n);

	return 0;
}

void CGraph::check_colour(bool a[101][101], int colors[101], int n)
{
	int colored = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			colored += a[i][j] && colors[i] != colors[j];
		}
	}

	std::cout << colored;
}

void CGraph::inputMatrix(bool a[101][101], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bool connected;
			std::cin >> connected;
			a[i][j] = connected;
		}
	}

	int colors[101]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		std::cin >> colors[i];
	}

	check_colour(a, colors, n);
}
