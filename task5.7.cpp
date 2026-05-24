#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть n (n >= 3): ";
    std::cin >> n;

    // Базові значення для k=1 та k=2
    double a1 = 0.0, a2 = 1.0;
    double b1 = 1.0, b2 = 0.0;

    // Початкова сума для перших двох членів
    double S = (2.0 / (a1 + b1)) + (4.0 / (a2 + b2));

    // Тимчасові змінні для кроків k-1 та k-2
    double a_prev2 = a1, a_prev1 = a2;
    double b_prev2 = b1, b_prev1 = b2;

    double power_of_two = 4.0; // 2^k, починаємо з 2^2 = 4

    for (int k = 3; k <= n; ++k) {
        double a_curr = (a_prev2 / k) + a_prev1 * b_prev1;
        double b_curr = b_prev1 + a_prev2;
        power_of_two *= 2.0;

        S += power_of_two / (a_curr + b_curr);

        // Оновлення значень для наступної ітерації
        a_prev2 = a_prev1;
        a_prev1 = a_curr;
        b_prev2 = b_prev1;
        b_prev1 = b_curr;
    }

    std::cout << "Сума S_n = " << S << std::endl;
    return 0;
}
