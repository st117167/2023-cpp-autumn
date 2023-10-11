#include <iostream>

int main(int*, char**)
{
    int n = 0;
    std::cin >> n;

    int* a = (int*)malloc(sizeof(int) * n); // array

    int k = 0;
    for (int i = 0; i < n; i = i + 1)
    {
        std::cin >> *(a + i);
        if (*(a + i) <= 0)
        {
            k = k + 1;
        }
    }

    int* b = (int*)malloc(sizeof(int) * (n - k)); // creating array of positive numbers

    int h = 0;
    for (int i = 0; i < n; i = i + 1)
    {
        if (*(a + i) > 0)
        {
            *(b + h) = *(a + i);
            h = h + 1;
        }

        if (h == n - k)
        {
            break;
        }
    }

    for (int i = 0; i < n - k; i = i + 1)
    {
        std::cout << *(b + i) << " ";
    }
    free(a);
    free(b);

    return 0;
}
