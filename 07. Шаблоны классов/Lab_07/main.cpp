#include <iostream>
#include "Vector.h"
#include "Time.h"

int main() {
    setlocale(LC_ALL, "rus");

    // Создание вектора из 5 элементов, заполненного 0
    Vector<int> a(5,0);

    cout << a << endl;

    // Ввели значения элементов вектора
    cin >> a;

    cout << a << endl;

    // Присвоили новое значение элементу 2 посредством доступа по индексу
    a[2] = 100;

    cout << a << endl;

    Vector<int> b(10,1);

    cout << b << endl;

    // Присвоили вектору b значение вектора a
    b = a;

    cout << b << endl;

    Vector<int> c(10,0);

    // К значениям вектора b прибавили константу 100 и присвоили вектору c
    c = b + 100;

    cout << c << endl;

    cout << "Длина вектора a = " << a() << endl;

    Time t;

    cin >> t;
    cout << t << endl;

    Vector<Time> A(5, t);

    cin >> A;
    cout << A << endl;

    Vector<Time> B(10, t);

    cout << B << endl;

    B = A;

    cout << B << endl;
    cout << A[2] << endl;
    cout << "Длина вектора A = " << A() << endl;

    B = A + t;

    cout << B << endl;

	return 0;
}