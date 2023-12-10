#include<iostream>


int main() {

    setlocale(LC_ALL, "Russian");

    std::cout << "Лабораторная работа 6\nЗадание 1\n";

    int num1;
    int n; // длина последовательности
    int prod = 1; // произведение чисел на отрезке [-2,20]
    int min_num = INT_MAX; // наименьшее число на отрезке [-2,20]
    int min_num_pos = -1; // позиция наименьшего числа в последовательности

    // ввод последовательности
    std::cout << "Введите длину последовательности:";
    std::cin >> n;
    std::cout << "Введите последовательность целых чисел:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> num1;
        if (num1 >= -2 && num1 <= 20) {
            if (num1 != 0) {
                prod *= num1;
            }
            if (num1 < min_num) {
                min_num = num1;
                min_num_pos = i;
            }
        }

    }
    // вывод результатов
    std::cout << "Произведение чисел на отрезке [-2,20]: " << prod << std::endl;
    if (min_num_pos == -1) {
        std::cout << "В последовательности нет чисел на отрезке [-2,20]" << std::endl;
    }
    else {
        std::cout << "Наименьшее число на отрезке [-2,20]: " << min_num << std::endl;
        std::cout << "Позиция наименьшего числа в последовательности: " << min_num_pos << std::endl;
    }





    std::cout << "Лабораторная работа 6\nЗадание 2\n";

    int num2; // обрабатываемое число
    int prodEv = 1; //произведение чисел

    std::cout << "Введите число (не более 10^9):";
    std::cin >> num2;
    if ((10 ^ 9) > num2) {
        while (num2 != 0) {
            int numEv = num2 % 10; // переменная для определения чётности
            num2 = num2 / 10; // сокращение исходного числа
            if (numEv % 2 == 0) { //проверка на чётность
                prodEv *= numEv;
            }
        }
        if (prodEv == 1) {
            std::cout << "В числе отсуствуют чётные числа";
        }
        else {
            std::cout << "Произведение чётных чисел числа:" << prodEv;
        }
    }

    return 0;

}


