#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, m;
    int matrix[100][100];

    std::cout << "Введите количество строк (n): ";
    std::cin >> n;

    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;

    for (int i = 0; i < n; i++) { // Ввод элементов матрицы
        for (int j = 0; j < m; j++) {
            std::cout << "Введите элемент матрицы [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    int minColumn = 0;
    int minElement = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {  // Нахождение столбца с наименьшим элементом
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minColumn = j;
            }
        }
    }

    for (int i = 0; i < n; i++) { // Замена отрицательных элементов столбца на 0
        if (matrix[i][minColumn] < 0) {
            matrix[i][minColumn] = 0;
        }
    }


    std::cout << "Измененная матрица:\n";
    for (int i = 0; i < n; i++) { // Вывод измененной матрицы
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}