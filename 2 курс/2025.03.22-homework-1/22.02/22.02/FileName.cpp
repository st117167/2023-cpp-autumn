#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

void printar(double* ar, int n)
{
    cout << endl << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << ar[i] << ' ';
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n = 0; // задаваемый параметр
    cin >> n;

    double* ar = new double[n + 1];
    const double step = M_PI / (2 * n);

    // Последовательный расчет

    double t = omp_get_wtime();

    for (int i = 0; i <= n; i++)
    {
        ar[i] = sin(i * step);
    }
    cout << "Последовательное время: " << (omp_get_wtime() - t) << endl;
    //printar(ar, n);

    // Параллельный расчет (2 секции)

    t = omp_get_wtime();

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i <= n / 2 - 1; i++)
            {
                ar[i] = sin(i * step);
            }
        }
#pragma omp section
        {
            for (int i = n / 2; i <= n; i++)
            {
                ar[i] = sin(i * step);
            }
        }
    }
    cout << "Параллельное время (2 секции): " << (omp_get_wtime() - t) << endl;
    //printar(ar, n);

  // Параллельный расчет (4 секции)
    t = omp_get_wtime();

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i <= n / 4 - 1; i++)
            {
                ar[i] = sin(i * step);
            }
        }
#pragma omp section
        {
            for (int i = n / 4; i <= n / 2 - 1; i++)
            {
                ar[i] = sin(i * step);
            }
        }
#pragma omp section
        {
            for (int i = n / 2; i <= n / 4 * 3 - 1; i++)
            {
                ar[i] = sin(i * step);
            }
        }
#pragma omp section
        {
            for (int i = n / 4 * 3; i <= n; i++)
            {
                ar[i] = sin(i * step);
            }
        }
    }
    cout << "Параллельное время (4 секции): " << (omp_get_wtime() - t) << endl;
    //printar(ar, n);

    delete[] ar;
    return EXIT_SUCCESS;
}