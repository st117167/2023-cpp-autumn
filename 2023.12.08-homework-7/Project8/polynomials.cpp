#include <iostream>
#include <vector>

// Функция для вычисления базисного полинома Лагранжа
double lagrange_basis(const std::vector<double>& x, const std::vector<double>& y, int i, double value) {
    double result = 1.0;
    for (int j = 0; j < x.size(); j++) {
        if (j != i) {
            result *= (value - x[j]) / (x[i] - x[j]);
        }
    }
    return result;
}

// Функция для вычисления многочлена Лагранжа
double lagrange_polynomial(const std::vector<double>& x, const std::vector<double>& y, double value) {
    double result = 0.0;
    for (int i = 0; i < x.size(); i++) {
        result += y[i] * lagrange_basis(x, y, i, value);
    }
    return result;
}

int main() {
    // Ввод количества точек
    int n;
    std::cout << "Введите количество точек: ";
    std::cin >> n;

    // Ввод точек
    std::vector<double> x(n);
    std::vector<double> y(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Введите x[" << i << "]: ";
        std::cin >> x[i];
        std::cout << "Введите y[" << i << "]: ";
        std::cin >> y[i];
    }

    // Вывод многочлена Лагранжа по точкам
    std::cout << "L(x) = ";
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << " + ";
        }
        std::cout << y[i] << " * ";
        for (int j = 0; j < n; j++) {
            if (j != i) {
                std::cout << "(x - " << x[j] << ") / (" << x[i] << " - " << x[j] << ")";
                if (j < n - 1) {
                    std::cout << " * ";
                }
            }
        }
    }
    std::cout << std::endl;

    // Ввод значения для вычисления многочлена Лагранжа
    double value;
    std::cout << "Введите значение для вычисления многочлена Лагранжа: ";
    std::cin >> value;

    // Вычисление значения многочлена Лагранжа в заданной точке
    double result = lagrange_polynomial(x, y, value);
    std::cout << "L(" << value << ") = " << result << std::endl;

    return 0;
}
