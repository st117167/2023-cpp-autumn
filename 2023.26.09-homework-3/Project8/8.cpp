#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    std::cin >> a;

    int b = 0;
    std::cin >> b;

    int n = 0;
    std::cin >> n;

    int c = 0;
    int r = 0;
    int a1 = a;
    int b1 = b;
    char aa = 'A';
    char bb = 'B';

    if (a > b)
    {
        c = a;
        a = b;
        b = c;
        aa = 'B';
        bb = 'A';
    }

    if (n == b)
    {
        std::cout << ">" << bb;
        return 0;
    }

    while (b1 != 0)
    {
        c = a1 % b1;
        a1 = b1;
        b1 = c;
    }

    while (b1 != 0)
    {
        c = a1 % b1;
        a1 = b1;
        b1 = c;
    }

    if ((n % a1 != 0) || ((n > a) && (n > b)))
    {
        std::cout << "Impossible" << std::endl;
    }

    else
    {
        while (1)
        {
            r = r + a;
            std::cout << ">" << aa << std::endl;
            std::cout << aa << ">" << bb << std::endl;
            if (r >= b)
            {
                std::cout << bb << ">" << std::endl;
                std::cout << aa << ">" << bb << std::endl;
                r = r % b;
            }
            if ((r == n) || (r == 0))
            {
                break;
            }
        }
    }
    return 0;
}
