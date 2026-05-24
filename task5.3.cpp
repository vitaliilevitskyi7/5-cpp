#include <iostream>

// Функція обчислення кількості кроків до збіжності в 1
int count_collatz_steps(long long n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    int max_steps = 0;
    int best_n = 1;

    // Перевірка чисел для n < 1000
    for (int i = 1; i < 1000; ++i) {
        int steps = count_collatz_steps(i);
        if (steps > max_steps) {
            max_steps = steps;
            best_n = i;
        }
    }

    std::cout << "Для всіх n < 1000 послідовність збігається до одиниці.\n";
    std::cout << "Число з максимальною кількістю кроків: " << best_n << "\n";
    std::cout << "Максимальна кількість кроків: " << max_steps << "\n";

    return 0;
}
