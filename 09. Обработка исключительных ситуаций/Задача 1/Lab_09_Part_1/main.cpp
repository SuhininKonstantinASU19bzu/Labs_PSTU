#include <iostream>
#include <locale>
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    // Контролируемый блок
    try {
        Vector x(2); // Вектор из двух элементов
        Vector y; // Пустой вектор
        int i, n;

        cout << x; // Печать вектора x

        cout << "Номер(-1 или 2): ";

        cin >> i;

        cout << x[i] << endl; // Если i < 0 throw 57, i > 1 throw 58

        y = x + 3;

        cout << y;

        y = y.Add(4); // Добавление элемента в вектор, если MAX_SIZE throw 70

        cout << y;
        cout << "Размер вектора y: " << y() << endl;
        cout << "Сколько элементов удалить из вектора: ";

        cin >> n;
        y = y - n; // Если вектор пуст throw 90, если n больше размера вектора throw 98
        cout << "y - " << "n" << endl << y;


        --x; // Удаление одного элемента из вектора

        cout << x;

        --x;

        cout << x; // Вектор пустой

        --x; // Генерируется исключение throw 119
    }
    // Обработчик исключений
    catch (int e) {
        cout << "VECTOR_ERROR_CODE_" << e << endl;
    }

    return 0;
}