#include <iostream>
#include <cmath>
#include <omp.h>

const int n = 1e8;  // Количество разбиений
double a = -1.0;     // Нижний предел интегрирования
double b = 1.0;      // Верхний предел интегрирования
double h = (b - a) / n;  // Шаг разбиения

double alpha = 0.5;  // Параметр α
double beta = 0.5;   // Параметр β

// Функция подынтегрального выражения
double f(double x) {
    double term1 = sqrt(1 - 2 * alpha * x + alpha * alpha);
    double term2 = sqrt(1 - 2 * beta * x + beta * beta);
    return 1.0 / (term1 * term2);
}

// Последовательная версия (для проверки)
double sequential_integral() {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return sum * h;
}

// Параллельная версия с разными типами планирования
double parallel_integral(const char* schedule_type) {
    double sum = 0.0;
#pragma omp parallel for reduction(+: sum) schedule(runtime)
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return sum * h;
}

int main() {
    // Последовательная версия (эталон)
    double start_time = omp_get_wtime();
    double integral_seq = sequential_integral();
    double seq_time = omp_get_wtime() - start_time;
    std::cout << "Sequential integral: " << integral_seq << std::endl;
    std::cout << "Sequential time: " << seq_time * 1000 << " ms" << std::endl;

    // Параллельные версии с разными типами планирования
    double t_static, t_dynamic, t_guided;
    double integral_static, integral_dynamic, integral_guided;

    // Static
    omp_set_schedule(omp_sched_static, 0);
    start_time = omp_get_wtime();
    integral_static = parallel_integral("static");
    t_static = omp_get_wtime() - start_time;
    std::cout << "\nStatic schedule:" << std::endl;
    std::cout << "Integral: " << integral_static << std::endl;
    std::cout << "Time: " << t_static * 1000 << " ms" << std::endl;

    // Dynamic
    omp_set_schedule(omp_sched_dynamic, 1000);  // Чанк = 1000 итераций
    start_time = omp_get_wtime();
    integral_dynamic = parallel_integral("dynamic");
    t_dynamic = omp_get_wtime() - start_time;
    std::cout << "\nDynamic schedule:" << std::endl;
    std::cout << "Integral: " << integral_dynamic << std::endl;
    std::cout << "Time: " << t_dynamic * 1000 << " ms" << std::endl;

    // Guided
    omp_set_schedule(omp_sched_guided, 1000);  // Чанк уменьшается от 1000
    start_time = omp_get_wtime();
    integral_guided = parallel_integral("guided");
    t_guided = omp_get_wtime() - start_time;
    std::cout << "\nGuided schedule:" << std::endl;
    std::cout << "Integral: " << integral_guided << std::endl;
    std::cout << "Time: " << t_guided * 1000 << " ms" << std::endl;

    // Проверка корректности
    bool is_correct =
        (fabs(integral_static - integral_seq) < 1e-10) &&
        (fabs(integral_dynamic - integral_seq) < 1e-10) &&
        (fabs(integral_guided - integral_seq) < 1e-10);
    std::cout << "\nResults are " << (is_correct ? "CORRECT" : "INCORRECT") << std::endl;

    return 0;
}