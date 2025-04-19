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

    int n = 0; // Количество элементов
    cin >> n;

    double* arr = new double[n + 1];
    const double step = M_PI / (2 * n);

    // Последовательная версия
    double t = omp_get_wtime();
    for (int i = 0; i <= n; i++) {
        arr[i] = sin(i * step);
    }
    cout << "Последовательная версия: " << (omp_get_wtime() - t) << endl;
    //print_array(arr, n);

    // Параллельная версия с автоматическим распределением
    t = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i <= n; i++) {
        arr[i] = sin(i * step);
    }
    cout << "Параллельная версия (auto): " << (omp_get_wtime() - t) << endl;
    //print_array(arr, n);

    // Параллельная версия с 2 потоками
    t = omp_get_wtime();
#pragma omp parallel for num_threads(2)
    for (int i = 0; i <= n; i++) {
        arr[i] = sin(i * step);
    }
    cout << "Параллельная версия (2 потока): " << (omp_get_wtime() - t) << endl;
    //print_array(arr, n);

    // Параллельная версия с 4 потоками
    t = omp_get_wtime();
#pragma omp parallel for num_threads(4)
    for (int i = 0; i <= n; i++) {
        arr[i] = sin(i * step);
    }
    cout << "Параллельная версия (4 потока): " << (omp_get_wtime() - t) << endl;
    //print_array(arr, n);

    delete[] arr;
    return EXIT_SUCCESS;
}