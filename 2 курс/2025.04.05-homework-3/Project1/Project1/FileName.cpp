#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

// Функция, которую нужно интегрировать
double f(double x, double alpha, double beta) {
    return 1.0 / (sqrt(1 - 2 * alpha * x + alpha * alpha) * sqrt(1 - 2 * beta * x + beta * beta));
}

// Метод трапеций для численного интегрирования
double trapezoidal(double a, double b, int n, double alpha, double beta) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a, alpha, beta) + f(b, alpha, beta));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h, alpha, beta);
    }
    return h * sum;
}


// Адаптивная квадратура
double adaptiveQuadrature(double a, double b, double alpha, double beta, double tolerance, int maxDepth) {
    double midpoint = (a + b) / 2.0;
    double wholeArea = trapezoidal(a, b, 10, alpha, beta);  // Оценим площадь на грубом разбиении
    double leftArea = trapezoidal(a, midpoint, 10, alpha, beta);
    double rightArea = trapezoidal(midpoint, b, 10, alpha, beta);

    if (abs(leftArea + rightArea - wholeArea) <= 3 * tolerance || maxDepth == 0) {
        return leftArea + rightArea;
    }
    else {
#pragma omp task shared(leftArea)
        {
            leftArea = adaptiveQuadrature(a, midpoint, alpha, beta, tolerance / 2.0, maxDepth - 1);
        }

#pragma omp task shared(rightArea)
        {
            rightArea = adaptiveQuadrature(midpoint, b, alpha, beta, tolerance / 2.0, maxDepth - 1);
        }

#pragma omp taskwait
        return leftArea + rightArea;
    }
}

// Функция для вычисления аналитического значения
double analyticalSolution(double alpha, double beta) {
    double rootAlphaBeta = sqrt(alpha * beta);
    return (1.0 / rootAlphaBeta) * log((1 + rootAlphaBeta) / (1 - rootAlphaBeta));
}

int main() {
    double alpha = 0.5;
    double beta = 0.7;
    double a = -1.0;
    double b = 1.0;
    double tolerance = 1e-6;
    int maxDepth = 10; // Ограничиваем глубину рекурсии

    double result;

#pragma omp parallel
    {
#pragma omp single
        {
            result = adaptiveQuadrature(a, b, alpha, beta, tolerance, maxDepth);
        }
    }

    cout << "Численное значение интеграла: " << result << endl;
    cout << "Аналитическое значение интеграла: " << analyticalSolution(alpha, beta) << endl;
    cout << "Абсолютная погрешность: " << abs(result - analyticalSolution(alpha, beta)) << endl;


    return 0;
}