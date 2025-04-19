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

// Параллельная версия с reduction
double parallel_integral_reduction() {
    double sum = 0.0;

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }

    return sum * h;
}

// Параллельная версия с использованием parallel for без явного разделения
double parallel_integral_parallel_for() {
    double sum = 0.0;

#pragma omp parallel
    {
        double local_sum = 0.0;

#pragma omp for
        for (int i = 0; i < n; ++i) {
            double x = a + (i + 0.5) * h;
            local_sum += f(x);
        }

#pragma omp atomic
        sum += local_sum;
    }

    return sum * h;
}

int main() {
    // Последовательная версия
    double start_time = omp_get_wtime();
    double integral_seq = sequential_integral();
    double end_time = omp_get_wtime();
    std::cout << "Sequential integral value: " << integral_seq << std::endl;
    std::cout << "Sequential time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    // Параллельная версия с reduction
    start_time = omp_get_wtime();
    double integral_par_red = parallel_integral_reduction();
    end_time = omp_get_wtime();
    std::cout << "Parallel (reduction) integral value: " << integral_par_red << std::endl;
    std::cout << "Parallel (reduction) time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    // Параллельная версия с parallel for
    start_time = omp_get_wtime();
    double integral_par_for = parallel_integral_parallel_for();
    end_time = omp_get_wtime();
    std::cout << "Parallel (parallel for) integral value: " << integral_par_for << std::endl;
    std::cout << "Parallel (parallel for) time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    return 0;
}
