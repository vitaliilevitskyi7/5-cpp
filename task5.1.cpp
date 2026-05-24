#include <iostream>

int main() {
    double a;
    std::cout << "Введіть дійсне число a: ";
    std::cin >> a;

    // а) Пошук першого числа, більшого за a
    double sum_a = 0.0;
    int i = 1;
    while (sum_a <= a) {
        sum_a += 1.0 / i;
        i++;
    }
    std::cout << "а) Перше число, більше за a: " << sum_a << "\n";

    // б) Пошук найменшого n > 0, що 1 + 1/2 + ... + 1/n > a
    double sum_b = 0.0;
    int n = 0;
    while (sum_b <= a) {
        n++;
        sum_b += 1.0 / n;
    }
    std::cout << "б) Найменше n: " << n << "\n";

    return 0;
}
