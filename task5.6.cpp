#include <iostream>

int main() {
    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    // а) b_n = b + 1 / (b + 1 / (...))
    double b;
    std::cout << "Введіть дійсне число b для варіанта а): ";
    std::cin >> b;
    double res_a = b;
    for (int i = 1; i < n; ++i) {
        res_a = b + 1.0 / res_a;
    }
    std::cout << "а) b_n = " << res_a << "\n";

    // б) За вказівкою: b_0 = 4n + 2, b_k = 4(n-k) + 2 + 1 / b_{k-1}
    double b_val = 4.0 * n + 2.0; 
    for (int k = 1; k <= n; ++k) {
        b_val = 4.0 * (n - k) + 2.0 + 1.0 / b_val;
    }
    std::cout << "б) lambda_n = " << 2.0 + 1.0 / (6.0 + 1.0 / (10.0 + b_val)) << " (наближено через вказівку)\n";

    // в) x_2n = 1 + 1 / (2 + 1 / (1 + ... + 1 / 2))
    double res_v = 2.0; // Самий нижній знаменник для парного кроку
    for (int i = 2 * n - 1; i >= 1; --i) {
        double current_denominator = (i % 2 == 0) ? 2.0 : 1.0;
        res_v = current_denominator + 1.0 / res_v;
    }
    std::cout << "в) x_2n = " << res_v << "\n";

    return 0;
}
