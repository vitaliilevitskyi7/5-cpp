#include <iostream>

// а) Функція для обчислення F_n за номером члену
long long get_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long f0 = 0, f1 = 1, f_curr = 1;
    for (int k = 2; k <= n; ++k) {
        f_curr = f0 + f1;
        f0 = f1;
        f1 = f_curr;
    }
    return f_curr;
}

// б) Номер найбільшого числа Фібоначчі, яке не перевищує a
int get_index_not_exceeding(double a) {
    int k = 0;
    while (get_fibonacci(k + 1) <= a) {
        k++;
    }
    return k;
}

// в) Номер найменшого числа Фібоначчі, яке більше заданого a
int get_index_greater(double a) {
    int k = 0;
    while (get_fibonacci(k) <= a) {
        k++;
    }
    return k;
}

// г) Сума всіх чисел Фібоначчі, які не перевищують 1000
long long sum_fibonacci_1000() {
    long long sum = 0;
    int k = 0;
    while (true) {
        long long fib = get_fibonacci(k);
        if (fib > 1000) break;
        sum += fib;
        k++;
    }
    return sum;
}

int main() {
    double a;
    std::cout << "Введіть число a (для пунктів б та в): ";
    std::cin >> a;

    std::cout << "а) F_6 = " << get_fibonacci(6) << "\n";
    std::cout << "б) Номер найбільшого F_k <= a: " << get_index_not_exceeding(a) << "\n";
    std::cout << "в) Номер найменшого F_k > a: " << get_index_greater(a) << "\n";
    std::cout << "г) Сума чисел Фібоначчі <= 1000: " << sum_fibonacci_1000() << "\n";

    return 0;
}
