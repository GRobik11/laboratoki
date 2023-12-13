#include <iostream>

void sort(int* mass, int kol) {
    for (unsigned short i = 0; i < kol - 1; i++) {
        for (unsigned short j = i + 1; j < kol; j++)
        {
            if (mass[i] > mass[j])
            {
                unsigned short tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned short kol;
    int* mass = new int[10000];

    std::cout << "Введите колличество цифр: ";
    std::cin >> kol; //вводится будущее кол-во цифр

    for (unsigned short i = 0; i < kol; i++) { //заполняем массив
        std::cout << "\n" << i << ". число: ";
        std::cin >> mass[i];
    }

    unsigned short x = 0;
    bool flag = false;
    for (unsigned short i = 0; i < kol; i++) { //проходится по числам в массиве
        std::cout << "\nПроход начался:" << mass[i];
        unsigned short chislo = mass[i]; //помещаем число массива в переменную для обработки
        x = 0;

        for (unsigned short i = 0; chislo != 0; i++) { //отдельно взятое число, у которого ищем сумму всех чего чисел
            std::cout << "\nПрепарация (x, chislo)" << x << " " << chislo;
            x = x + chislo % 10;
            std::cout << "\nПрепарация (x, chislo)" << x << " " << chislo;
            chislo /= 10;
            std::cout << "\nПрепарация (x, chislo)" << x << " " << chislo;
        }
        if (x == 14) {
            flag = true;
            break;
        }
    }
    if (flag) {
        sort(mass, kol);
    }

    for (unsigned short i = 0; i < kol; i++) {
        std::cout << "\n" << mass[i];
    }

    delete[] mass;
}
