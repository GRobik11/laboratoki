#include "functions.hpp"
#include <iostream>


int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    bool flag;
    int matrix[100][100];

    std::cout << "Введите какого порядка матрица: ";
    std::cin >> n;

    jp::Read(matrix, n);

    flag = jp::Check_3or5(matrix, n);
    if (flag == true) {
        std::cout << "Прошло" << flag;
        jp::changeMatrix(matrix, n);
    }
    jp::Write(matrix, n);
}

