#include <iostream>
#include <locale>
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    Time a;
    Time b;
    Time c;
    Time d;
    Time f;

    cout << "Введите a:" << endl;
    cin >> a;
    cout << "Введите b:" << endl;
    cin >> b;

    ++a;

    cout << "++a = " << a << endl;

    c = (a++) + b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "Операция сравнения" << endl;
    cout << "Введите d: " << endl;
    cin >> d;
    cout << "Введите f: " << endl;
    cin >> f;
    cout << "d = " << d << endl;
    cout << "f = " << f << endl;

    if (d == f) cout << "d и f равны!" << endl;
    
    else cout << "d и f не равны!" << endl;

    cout << "Операция сложения" << endl;
    cout << d << " + " << f << " = " << d + f << endl;

    return 0;
}