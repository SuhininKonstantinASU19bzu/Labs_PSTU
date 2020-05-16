#include <iostream>
#include <locale>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

// Глобальные функции
// Функция принимает объект базового класса как параметр
void f1(Pair& p) {
    p.set_second(9);
    cout << p;
}

// функция возвращает объект базового класса как результат
Pair f2() {
    Fraction f(9, 6);

    return f;
}

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    // Работа с классом Pair
    Pair A;

    cin >> A;
    cout << A;

    Pair B(5, 6);

    cout << B;

    // Работа со сравнениями Pair
    if (A > B) cout << A << ">" << B << endl;

    A = B; // Присвоение

    cout << A;

    // Работа с классом Fraction
    Fraction C;

    cin >> C;
    cout << C;

    int h = C.get_first(); // Использование селектора

    cout << "Целая часть дроби C: " << h << endl;

    // Работа со сравнениями Fraction
    Fraction F1;
    Fraction F2;

    cout << "Для проверки сравнения задайте две дроби:";
    cin >> F1;
    cin >> F2;

    if (F1 != F2) cout << F1 << "!=" << F2 << endl;
    if (F1 == F2) cout << F1 << "==" << F2 << endl;
    if (F1 >= F2) cout << F1 << ">=" << F2 << endl;
    if (F1 <= F2) cout << F1 << "<=" << F2 << endl;
    if (F1 > F2) cout << F1 << ">" << F2 << endl; // Тоже используется принцип подстановки
    if (F1 < F2) cout << F1 << "<" << F2 << endl;

    // Принцип подстановки
    f1(C); // Передаем объект класса Fraction

    A = f2(); // Создаем в функции объект класса Fraction

    cout << A;

    return 0;
}