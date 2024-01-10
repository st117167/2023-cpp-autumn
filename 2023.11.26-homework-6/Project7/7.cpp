#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from, int to)
{
    std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
    d[to][n[to]++] = d[from][--n[from]];
}

void h(int count, int from, int to)
{
    if (count == 0)
    {
        return;
    }

    int res = 6 - from - to;

    h(count - 1, from, res);
    shift(from, to);
    h(count - 1, res, to);
}

void sort()
{
    int from = 2;
    int to = 3;
    while (n[1] != 0)
    {
        while ((n[to] > 0) && (d[1][n[1] - 1] > d[to][n[to] - 1]) != 0)
        {
            int k = 0;
            while ((d[from][n[from] - 1 - k] < d[to][n[to] - 1]) && (n[from] - k > 0) != 0)
            {
                ++k;
            }
            h(k, from, to);
            std::swap(from, to);
            k = 0;
        }
        h(1, 1, to);
    }

    while (n[to] != 0)
    {
        int k = 0;
        while ((d[from][n[from] - 1 - k] < d[to][n[to] - 1]) && (d[from][n[from] - 1 - k] > 0) != 0)
        {
            ++k;
        }
        h(k, from, to);
        std::swap(from, to);
    }
}


int main(int argc, char* argv[])
{
    std::cin >> n[1];
    for (int i = n[1] - 1; i >= 0; --i)
    {
        std::cin >> d[1][i];
    }

    sort();

    return 0;
}