#include <iostream>
#include <locale>
#include "Vector.h"
#include "Error.h"

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

        cout << x[i] << endl;

        y = x + 3;

        cout << y;

        y = y.Add(4);

        cout << y;
        cout << "Размер вектора y: " << y() << endl;
        cout << "Сколько элементов удалить из вектора: ";

        cin >> n;

        y = y - n;

        cout << "y - " << "n" << endl << y;

        --x; // Удаление одного элемента из вектора

        cout << x;

        --x;

        cout << x; // Вектор пустой

        --x;
    }
    // Обработчик исключений
    catch (Error e) {
        e.what();
    }

    return 0;
}