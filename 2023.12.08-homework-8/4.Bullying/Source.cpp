#include<iostream>

using namespace std;

class CGraph {

public:

	void inputMatrix(int a[101][101], int& n);
	void outputMatrix(int a[101][101], int n);
	void Bulluing(int a[101][101], int n);

private:

	void inputEdges(int a[101][101], int& n);
	void outputEdges(int a[101][101], int n);

};

int main(int argc, char* argv[])
{
	int a[101][101]{ 0 };
	int n = 0;

	CGraph Graph;

	Graph.inputMatrix(a, n);


	return 0;
}

void CGraph::outputMatrix(int a[101][101], int n)
{
	cout << n << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void CGraph::Bulluing(int a[101][101], int n)
{
	int s = 0;
	int min_dist = 3001;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				s = a[i][j] + a[j][k] + a[k][i];
				if (s < min_dist) min_dist = s;
			}
		}
	}

	std::cout << min_dist;
}

void CGraph::outputEdges(int a[101][101], int n)
{
	int m = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			m += a[i][j];
		}
	}
	cout << n << " " << m << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
			{
				cout << i << " " << j << endl;
			}
		}
	}
}

void CGraph::inputEdges(int a[101][101], int& n)
{
	cin >> n;
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		a[s][e] += 1;
	}
}

void CGraph::inputMatrix(int a[101][101], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	Bulluing(a, n);
}
