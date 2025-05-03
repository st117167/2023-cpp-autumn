#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

void printar(double* ar, int n) {
    cout << endl << endl;
    for (int i = 0; i <= n; i++) {
        cout << ar[i] << ' ';
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n = 1e8; // Фиксированное значение n, как указано в задании
    double* ar = new double[n + 1];
    const double step = M_PI / (2 * n);

    // Последовательная версия
    double t_seq = omp_get_wtime();
    for (int i = 0; i <= n; i++) {
        ar[i] = sin(i * step);
    }
    t_seq = omp_get_wtime() - t_seq;
    cout << "Последовательная версия: " << t_seq << endl;

    // Параллельная версия с разными типами планирования
    double t_static, t_dynamic, t_guided;

    // Static
    t_static = omp_get_wtime();
#pragma omp parallel for schedule(static)
    for (int i = 0; i <= n; i++) {
        ar[i] = sin(i * step);
    }
    t_static = omp_get_wtime() - t_static;
    cout << "Static: " << t_static << endl;

    // Dynamic
    t_dynamic = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i <= n; i++) {
        ar[i] = sin(i * step);
    }
    t_dynamic = omp_get_wtime() - t_dynamic;
    cout << "Dynamic: " << t_dynamic << endl;

    // Guided
    t_guided = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for (int i = 0; i <= n; i++) {
        ar[i] = sin(i * step);
    }
    t_guided = omp_get_wtime() - t_guided;
    cout << "Guided: " << t_guided << endl;

    // Сравнение результатов (проверка корректности)
    bool correct = true;
    double* ar_seq = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        ar_seq[i] = sin(i * step);
    }
    for (int i = 0; i <= n; i++) {
        if (abs(ar[i] - ar_seq[i]) > 1e-10) {
            correct = false;
            break;
        }
    }
    cout << "Результаты корректны: " << (correct ? "да" : "нет") << endl;

    delete[] ar;
    delete[] ar_seq;
    return EXIT_SUCCESS;
}