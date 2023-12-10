#include <iostream>


int cough(int T) {
    std::cout << " Число: " << T << " ";
    return 0;
}

int main() {

    setlocale(LC_ALL, "Rus");

    const int MAX_SIZE = 20000;
    int arr[MAX_SIZE];
    int n;
    std::cout << "Введите количество элементов последовательности (не более " << MAX_SIZE << "): ";
    std::cin >> n;
    std::cout << "\nВведите последовательность: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }


    for (int a = 0; a < n; a++) {
        for (int i = arr[a]; i != 0;) {
            int test = i % 10; //3
            i = i / 10; //вмест 543 оставляю 54
            for (int j = i; j != 0; j /= 10) { //здесь обрабатывается 54
                int test2 = j % 10; //4
                //сравниваем между собой 3 и 4 числа 543
                if (test == test2) {

                    for (int dlt = a; dlt < n + 1; dlt++) {
                        arr[dlt] = arr[dlt + 1]; //543[0] 44[1] 1[2] ...[3]
                    }
                    n = n - 1;
                    a = a - 1;
                }
            }
        }
        std::cout << "\nGоследовательность: ";
        for (int i = 0; i < n + 2; i++)
            cough(arr[i]);
    }

    for (int a = 0; a < n; a++) {
        for (int i = arr[a]; i != 0; i /= 10) {
            int test = i % 10; //4
            //сравниваем между собой 3 и 4 числа 543
            //удаление
            if (test == 5) {
                for (int dbl = n; dbl > a;) {
                    arr[dbl] = arr[dbl - 1];

                    std::cout << "\ndbl: ";

                    cough(dbl);
                    dbl = dbl - 1;

                }

                n = n + 1;
                a = a + 1;
            }

        }
        std::cout << "\nпоследовательность: ";
        for (int i = 0; i < n + 2; i++)
            cough(arr[i]);
    }
}
