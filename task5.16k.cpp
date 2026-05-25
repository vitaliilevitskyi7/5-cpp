#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x, eps;
    std::cout << "Введіть дійсне число x (|x| < 1): ";
    std::cin >> x;
    std::cout << "Введіть точність eps (наприклад, 1e-6): ";
    std::cin >> eps;

    // Перевірка ОДЗ за умовою завдання
    if (std::abs(x) >= 1.0) {
        std::cout << "Помилка: модуль x має бути меншим за 1." << std::endl;
        return 1;
    }

    // Перший член ряду (при k = 0)
    double sum = 1.0;
    
    // Другий член ряду (при k = 1), який є базовим для рекурентного циклу
    double current_term = 0.5 * x; 
    
    int k = 1;

    // Додаємо члени ряду, поки їхня абсолютна величина не стане меншою за eps
    while (std::abs(current_term) >= eps) {
        sum += current_term;
        k++;
        
        // Рекурентна формула для обчислення наступного члена через попередній
        double factor = -x * (2.0 * k - 3.0) / (2.0 * k);
        current_term *= factor;
    }

    // Виведення результату з точністю до 6 знаків після коми
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Обчислена сума ряду:      " << sum << std::endl;
    std::cout << "Точне значення sqrt(1+x): " << std::sqrt(1.0 + x) << std::endl;

    return 0;
}
