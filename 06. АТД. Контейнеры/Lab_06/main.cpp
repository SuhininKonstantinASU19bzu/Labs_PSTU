#include <iostream>
#include <locale>
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    // Создание вектора из 5 элементов, заполненного 0
    Vector a(5);

    cout << a << endl;

    // Ввели значения элементов вектора
    cin >> a;

    cout << a << endl;

    // Присвоили новое значение элементу 2
    a[2] = 100;

    cout << a << endl;

    Vector b(10);

    cout << b << endl;

    // Присвоили вектору b значение вектора a
    b = a;

    cout << b << endl;

    Vector c(10);

    // К значениям вектора b прибавили константу 100 и присвоили вектору c
    c = b + 100;

    cout << c << endl;

    cout << "Длина вектора A = " << a() << endl;

    // Вывод значения 1 элемента посредством указателя
    cout << *(a.first()) << endl;

    // Установка указателя на 1 элемент
    Iterator i = a.first();

    // Перемещение указателя
    ++i;

    // Вывод значения 2 элемента посредством указателя
    cout << *i << endl;

    // Вывод значений всего вектора
    for (i = a.first(); i != a.last(); ++i) cout << *i << " ";

    return 0;
}