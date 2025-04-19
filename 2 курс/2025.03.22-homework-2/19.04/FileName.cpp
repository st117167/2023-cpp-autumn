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

// Параллельная версия с явным разделением работы (аналог sections)
template<int num_threads>
double parallel_integral_divided() {
    double sums[num_threads] = { 0.0 };

#pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        int chunk_size = n / num_threads;
        int start = thread_id * chunk_size;
        int end = (thread_id == num_threads - 1) ? n : start + chunk_size;

        for (int i = start; i < end; ++i) {
            double x = a + (i + 0.5) * h;
            sums[thread_id] += f(x);
        }
    }

    double total_sum = 0.0;
    for (int i = 0; i < num_threads; ++i) {
        total_sum += sums[i];
    }

    return total_sum * h;
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

    // Параллельная версия с 2 потоками
    start_time = omp_get_wtime();
    double integral_par_2 = parallel_integral_divided<2>();
    end_time = omp_get_wtime();
    std::cout << "Parallel (2 threads) integral value: " << integral_par_2 << std::endl;
    std::cout << "Parallel (2 threads) time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    // Параллельная версия с 4 потоками
    start_time = omp_get_wtime();
    double integral_par_4 = parallel_integral_divided<4>();
    end_time = omp_get_wtime();
    std::cout << "Parallel (4 threads) integral value: " << integral_par_4 << std::endl;
    std::cout << "Parallel (4 threads) time: " << (end_time - start_time) * 1000 << " ms" << std::endl;

    return 0;
}