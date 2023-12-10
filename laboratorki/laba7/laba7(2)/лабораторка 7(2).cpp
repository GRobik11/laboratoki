#include <iostream>

int firstNum(short number) {
    std::cout << "\nОбработка " << number;
    short maxFirstN = 0;
    for (; number != 0; number /= 10) {
        maxFirstN = number % 10;
    }
    std::cout << "\nПервая цифра числа =" << maxFirstN;
    return maxFirstN;
}

int maxNum(short number) {
    std::cout << "\nОбработка " << number;
    short maxNum = 0;
    short maxFirstN = 0;
    for (; number != 0; number /= 10) {
        maxFirstN = number % 10;
        if (maxFirstN > maxNum) {
            maxNum = maxFirstN;
        }
    }
    std::cout << "\nМаксимальная цифра числа =" << maxNum;
    return maxNum;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    short kol;
    int mass[1000];

    std::cout << "Введите колличество цифр: ";
    std::cin >> kol; //вводится будущее кол-во цифр

    for (short i = 0; i < kol; i++) { //заполняем массив
        std::cout << "\n" << i << ". число: ";
        std::cin >> mass[i];
    }


    for (short i = 0; i < kol - 1; i++) {
        for (short j = i + 1; j < kol; j++) {
            short firstNum_i = firstNum(mass[i]);
            short maxNum_i = maxNum(mass[i]);
            short firstNum_j = firstNum(mass[j]);
            short maxNum_j = maxNum(mass[j]);

            if (firstNum_i > firstNum_j) {
                short tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
            else if (maxNum_i > maxNum_j and firstNum_i == firstNum_j) {
                short tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
            else if (mass[i] > mass[j] and maxNum_i == maxNum_j and firstNum_i == firstNum_j) {
                short tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
            std::cout << "\nМассив имеет вид:";
            for (unsigned short i = 0; i < kol; i++) {
                std::cout << " " << mass[i];
            }
        }
    }
    for (unsigned short i = 0; i < kol; i++) {
        std::cout << "\n" << mass[i];