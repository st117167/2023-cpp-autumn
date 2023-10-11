#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    if (n % 100 <= 10 || n % 100 >= 20)
    {
        if (n % 10 == 0 || n % 10 >= 5) // 0, 5 - 10, 20, 25 - 30 ...
        {
            std::cout << n << " bochek";
        }
        else if (n % 10 == 1)
        {
            std::cout << n << " bochka"; // 1, 21, 31, 41, 51 ...
        }
        else
        {
            std::cout << n << " bochki"; // 2 - 4, 22 - 24, 32 - 34 ...
        }
    }
    else
    {
        std::cout << n << " bochek"; // 11, 15 - 19
    }
    return 0;
}
