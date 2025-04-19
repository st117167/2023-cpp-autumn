#include <iostream>
#include <cmath>
#include <omp.h>

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// ������� ��� ���������� ��������� � ������� ���������� ����������
double adaptiveQuadrature(double (*func)(double), double a, double b, double epsilon) {
    double mid = (a + b) / 2.0;
    double h = b - a;

    // ��������� �������� �� ����� � � ��������
    double I1 = h * (func(a) + func(b)) / 2.0; // ������� ����������
    double I2 = h * (func(a) + 4 * func(mid) + func(b)) / 6.0; // ���������� ����������

    // ���������, ���������� �� ����������� ��������
    if (fabs(I2 - I1) < epsilon) {
        return I2; // ���� ��, ���������� ���������
    }
    else {
        // ����� ����� �������� ������� � ���������� ��������� ��������
        double left = adaptiveQuadrature(func, a, mid, epsilon / 2);
        double right = adaptiveQuadrature(func, mid, b, epsilon / 2);
        return left + right; // ��������� ����������
    }
}

int main() {
    double a = 0.0; // ������ ���������
    double b = 1.0; // ����� ���������
    double epsilon = 1e-6; // ��������

    // ���������� ��������� task ��� �����������������
#pragma omp parallel
    {
#pragma omp single
        {
            double result = adaptiveQuadrature(f, a, b, epsilon);
            std::cout << "�������� �� f(x) �� ��������� [" << a << ", " << b << "] = " << result << std::endl;
        }
    }

    return 0;
}
