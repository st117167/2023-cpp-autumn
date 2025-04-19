#include <iostream>
#include <cmath>
#include <omp.h>

const int n = 1e8;  // Количество разбиений
double a = -1.0;    // Нижний предел интегрирования
double b = 1.0;     // Верхний предел интегрирования
double h = (b - a) / n;  // Шаг разбиения

double alpha = 0.5;  // Параметр α
double beta = 0.5;   // Параметр β

// Функция подынтегрального выражения
double f(double x) {
    double term1 = sqrt(1 - 2 * alpha * x + alpha * alpha);
    double term2 = sqrt(1 - 2 * beta * x + beta * beta);
    return 1.0 / (term1 * term2);
}

// Последовательная версия
double sequential_integral() {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return sum * h;
}

// Параллельная версия с 2 секциями
double parallel_integral_2_sections() {
    double sum1 = 0.0, sum2 = 0.0;

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i < n / 2; ++i) {
                double x = a + (i + 0.5) * h;
                sum1 += f(x);
            }
        }

#pragma omp section
        {
            for (int i = n / 2; i < n; ++i) {
                double x = a + (i + 0.5) * h;
                sum2 += f(x);
            }
        }
    }

    return (sum1 + sum2) * h;
}

// Параллельная версия с 4 секциями
double parallel_integral_4_sections() {
    double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0, sum4 = 0.0;

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i < n / 4; ++i) {
                double x = a + (i + 0.5) * h;
                sum1 += f(x);
            }
        }

#pragma omp section
        {
            for (int i = n / 4; i < n / 2; ++i) {
                double x = a + (i + 0.5) * h;
                sum2 += f(x);
            }
        }

#pragma omp section
        {
            for (int i = n / 2; i < 3 * n / 4; ++i) {
                double x = a + (i + 0.5) * h;
                sum3 += f(x);
            }
        }

#pragma omp section
        {
            for (int i = 3 * n / 4; i < n; ++i) {
                double x = a + (i + 0.5) * h;
                sum4 += f(x);
            }
        }
    }

    return (sum1 + sum2 + sum3 + sum4) * h;
}

int main() {
    // Последовательная версия
    double start_time = omp_get_wtime();
    double integral_seq = sequential_integral();
    double end_time = omp_get_wtime();
    std::cout << "Sequential integral value: " << integral_seq << std::endl;
    std::cout << "Sequential time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    // Параллельная версия с 2 секциями
    start_time = omp_get_wtime();
    double integral_par_2 = parallel_integral_2_sections();
    end_time = omp_get_wtime();
    std::cout << "Parallel (2 sections) integral value: " << integral_par_2 << std::endl;
    std::cout << "Parallel (2 sections) time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    // Параллельная версия с 4 секциями
    start_time = omp_get_wtime();
    double integral_par_4 = parallel_integral_4_sections();
    end_time = omp_get_wtime();
    std::cout << "Parallel (4 sections) integral value: " << integral_par_4 << std::endl;
    std::cout << "Parallel (4 sections) time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    return 0;
}