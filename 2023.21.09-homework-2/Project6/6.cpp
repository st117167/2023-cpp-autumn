#include <iostream>

int main(int argc, char* argv[])
{
    int t = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    if (k >= n)
    {
        t = m * 2;
    }
    else
    {
        t = 2 * n / k * m;
        if (n % k != 0 && n % k != k / 2)
        {
            t = t + m;
        }
    }
    std::cout << t;
    return 0;
}
