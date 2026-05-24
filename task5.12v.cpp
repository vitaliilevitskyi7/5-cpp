#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть натуральне число n (n >= 2): ";
    std::cin >> n;

    // Базові значення для k = 1
    double a_prev = 1.0; // a_1 = 1
    double b_prev = 1.0; // b_1 = 1

    // Початкові значення для накопичення компонентів суми на кроці k = 1
    double power_of_two = 2.0;   // 2^1
    double factorial = 1.0;      // 1!
    
    // Перший доданок суми для k = 1
    double S = power_of_two / ((1.0 + std::abs(a_prev + b_prev)) * factorial);

    // Цикл для обчислення доданків від k = 2 до n
    for (int k = 2; k <= n; ++k) {
        // Рекурентні співвідношення для поточних a_k та b_k
        double a_curr = 3.0 * b_prev + 2.0 * a_prev;
        double b_curr = 2.0 * a_prev + b_prev;

        // Оновлення накопичувальних значень степеня та факторіалу
        power_of_two *= 2.0; // 2^k
        factorial *= k;      // k!

        // Додавання поточного члена до загальної суми
        S += power_of_two / ((1.0 + std::abs(a_curr + b_curr)) * factorial);

        // Зсув змінних для наступного кроку циклу
        a_prev = a_curr;
        b_prev = b_curr;
    }

    std::cout << "Сума S_n = " << S << std::endl;

    return 0;
}
