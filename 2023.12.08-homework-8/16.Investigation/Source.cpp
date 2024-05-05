#include<iostream>

class CGraph {
public:

    void Investigation(int prev[101], int n);

};

int main() {
    int n = 0;

    int* prev = new int[101];
    prev[0] = 0;

    CGraph Graph;
    Graph.Investigation(prev, n);

    return 0;
}

void CGraph::Investigation(int prev[101], int n)
{
    for (int i = 1; i < n; i++)
    {
        std::cin >> prev[i];
    }

    int a = 0;
    std::cin >> a;

    int b = 0;
    std::cin >> b;

    while (a != b)
    {
        if (a > b)
        {
            a = prev[a - 1];
        }
        else
        {
            b = prev[b - 1];
        }

    }
    std::cout << a;
}
