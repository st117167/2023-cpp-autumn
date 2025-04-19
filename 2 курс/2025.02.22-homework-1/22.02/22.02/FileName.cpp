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

    int n = 0; // ���������� ��������
    cin >> n;

    double* ar = new double[n + 1];
    const double step = M_PI / (2 * n);

    // ���������������� ������

    double t = omp_get_wtime();

    for (int i = 0; i <= n; i++)
    {
        ar[i] = sin(i * step);
    }
    cout << "���������������� �����: " << (omp_get_wtime() - t) << endl;
    //printar(ar, n);

    // ������������ ������ (2 ������)

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
    cout << "������������ ����� (2 ������): " << (omp_get_wtime() - t) << endl;
    //printar(ar, n);

  // ������������ ������ (4 ������)
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
    cout << "������������ ����� (4 ������): " << (omp_get_wtime() - t) << endl;
    //printar(ar, n);

    delete[] ar;
    return EXIT_SUCCESS;
}