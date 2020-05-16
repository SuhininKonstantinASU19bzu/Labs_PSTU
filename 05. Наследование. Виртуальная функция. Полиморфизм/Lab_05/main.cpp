#include <iostream>
#include <locale>
#include "Object.h"
#include "Vector.h"
#include "Pair.h"
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    Object* p; // Указатель
    Vector v(5); // Вектор из 5 элементов
    Pair a;
    Fraction b;

    cin >> a;
    cin >> b;
    cout << a; // Вывод с помощью перегруженой операции

    p = &b; // Установка указателя на b
    p->Show(); // Вывод с помощью метода Show() и указателя
    
    // Работа через вектор
    p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);
    cout << v << endl;

    return 0;
}