#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

void print_array(double* arr, int n) {
    cout << endl << endl;
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n = 0; // ���������� ���������
    cin >> n;

    double* arr = new double[n + 1];
    const double step = M_PI / (2 * n);

    // ���������������� ������
    double t = omp_get_wtime();
    for (int i = 0; i <= n; i++) {
        arr[i] = sin(i * step);
    }
    cout << "���������������� ������: " << (omp_get_wtime() - t) << " ������" << endl;
    // print_array(arr, n);

    // ������������ ������
    for (int num_threads : {1, 2, 4}) {
        t = omp_get_wtime();
#pragma omp parallel for num_threads(num_threads)
        for (int i = 0; i <= n; i++) {
            arr[i] = sin(i * step);
        }
        cout << "������������ ������ (" << num_threads << " �������): " << (omp_get_wtime() - t) << " ������" << endl;
        // print_array(arr, n);
    }

    delete[] arr;
    return EXIT_SUCCESS;
}
