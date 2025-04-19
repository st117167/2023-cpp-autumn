#include <iostream>
#include <cmath>
#include <omp.h>

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// Функция для вычисления интеграла с помощью адаптивной квадратуры
double adaptiveQuadrature(double (*func)(double), double a, double b, double epsilon) {
    double mid = (a + b) / 2.0;
    double h = b - a;

    // Вычисляем значения на краях и в середине
    double I1 = h * (func(a) + func(b)) / 2.0; // Простая квадратура
    double I2 = h * (func(a) + 4 * func(mid) + func(b)) / 6.0; // Улучшенная квадратура

    // Проверяем, достигнута ли необходимая точность
    if (fabs(I2 - I1) < epsilon) {
        return I2; // Если да, возвращаем результат
    }
    else {
        // Иначе делим интервал пополам и рекурсивно вычисляем интеграл
        double left = adaptiveQuadrature(func, a, mid, epsilon / 2);
        double right = adaptiveQuadrature(func, mid, b, epsilon / 2);
        return left + right; // Суммируем результаты
    }
}

int main() {
    double a = 0.0; // Начало интервала
    double b = 1.0; // Конец интервала
    double epsilon = 1e-6; // Точность

    // Используем директиву task для распараллеливания
#pragma omp parallel
    {
#pragma omp single
        {
            double result = adaptiveQuadrature(f, a, b, epsilon);
            std::cout << "Интеграл от f(x) на интервале [" << a << ", " << b << "] = " << result << std::endl;
        }
    }

    return 0;
}
