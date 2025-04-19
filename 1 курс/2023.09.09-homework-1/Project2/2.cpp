#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int s1 = 0;
    int s2 = 0;
    std::cin >> n;
    s1 = (abs(n) + 1) * abs(n) / 2 - 1;
    s2 = abs(n) / n * (abs(n) + 1) * abs(n) / 2;
    std::cout << abs(n) / n * s1 + 1;
    return 0;
}