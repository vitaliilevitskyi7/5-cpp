#include <iostream>
#include <cmath>
#include <iomanip>

// а) Обчислення e^x
void taylor_exp(double x, double eps) {
    double sum = 1.0;
    double term = 1.0;
    int k = 1;

    while (std::abs(term) >= eps) {
        term *= (x / k);
        sum += term;
        k++;
    }

    std::cout << "а) Ряд Тейлора e^x: " << sum << "\n";
    std::cout << "   Вбудований exp(x): " << std::exp(x) << "\n";
}

// б) Обчислення інтеграла функції Ф(x)
void taylor_integral(double x, double eps) {
    double sum = x;
    double term = x;
    int k = 1;

    while (std::abs(term) >= eps) {
        // Коефіцієнт переходу до наступного члену ряду
        term *= (-x * x) / k;
        // Додаємо з урахуванням нового знаменника (2k + 1)
        sum += term / (2 * k + 1);
        k++;
    }

    std::cout << "б) Ряд Тейлора Ф(x): " << sum << "\n";
    // Для порівняння використовується стандартна функція помилок erf(x)
    // Оскільки інтеграл від e^(-x^2) пов'язаний з erf як sqrt(pi)/2 * erf(x)
    double expected = (std::sqrt(3.14159265358979323846) / 2.0) * std::erf(x);
    std::cout << "   Очікуване значення: " << expected << "\n";
}

int main() {
    double x, eps;
    std::cout << "Введіть дійсне число x: ";
    std::cin >> x;
    std::cout << "Введіть точність eps (наприклад, 1e-6): ";
    std::cin >> eps;

    std::cout << std::fixed << std::setprecision(6);
    taylor_exp(x, eps);
    std::cout << "\n";
    taylor_integral(x, eps);

    return 0;
}
