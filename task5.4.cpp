#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    // а) P_n = добуток (1 + 1/i)
    double P_a = 1.0;
    for (int i = 1; i <= n; ++i) {
        double multiplier = 1.0 + (1.0 / i);
        P_a *= multiplier;
    }
    std::cout << "а) Добуток P_n = " << P_a << "\n";

    // б) P_n = добуток (1 + ( (-1)^(i+1) ) / i^2)
    double P_b = 1.0;
    for (int i = 1; i <= n; ++i) {
        double sign = (i % 2 != 0) ? 1.0 : -1.0; // (-1)^(i+1)
        double multiplier = 1.0 + (sign / (i * i));
        P_b *= multiplier;
    }
    std::cout << "б) Добуток P_n = " << P_b << "\n";

    return 0;
}
