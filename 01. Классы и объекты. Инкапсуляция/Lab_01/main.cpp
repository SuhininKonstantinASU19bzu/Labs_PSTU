
#include <iostream>
#include <locale>
#include "ipart.h"

using namespace std;

ipart make_ipart(unsigned F, unsigned S) {
    ipart t; // Создали временную переменную
    t.Init(F, S); // Инициализировали поля переменной t с помощью параметров функции
    return t; // Вернули значение переменной
}

int main() {
    setlocale(LC_ALL, "rus");

    // Работа через определение переменной A и B
    cout << endl <<"Определение переменных A, B" << endl;

    ipart A;
    ipart B;

    A.Init(3, 2); // Инициализация предварительно заданной переменной A
    B.Read(); // Ввод значений полей переменной B
    A.Show(); // Вывод значений полей переменной A
    B.Show(); // Вывод значений полей переменной B

    cout << "Целая часть дроби A ("<< A.first << "/" << A.second << ") равна: " << A.Resolve() << endl;
    cout << "Целая часть дроби B (" << B.first << "/" << B.second << ") равна: " << B.Resolve() << endl;
    
    // Работа через указатели
    cout << endl << "Указатель X" << endl;

    ipart* X = new ipart; // Выделение памяти под динамическую переменную

    X->Init(5.6, 2.3); // Инициализация
    X->Show(); // Вывод значений полей
    X->Resolve(); // Вычисление целой части

    cout << "Целая часть дроби X (" << X->first << "/" << X->second << ") равна: " << X->Resolve() << endl;

    // Работа через статический массив
    cout << endl << "Статический массив" << endl;

    ipart mas[3];

    for (int i = 0; i < 3; i++) mas[i].Read();
    for (int i = 0; i < 3; i++) mas[i].Show();
    for (int i = 0; i < 3; i++) {
        mas[i].Resolve();
        cout << "Целая часть дроби Static I : " << i << " (" << mas[i].first << "/" << mas[i].second << ") равна: ";
        cout << mas[i].Resolve() << endl;
    }

    // Работа через динамический массив
    cout << endl << "Динамический массив" << endl;

    ipart* p_mas = new ipart[3];

    for (int i = 0; i < 3; i++) p_mas[i].Read();
    for (int i = 0; i < 3; i++) p_mas[i].Show();
    for (int i = 0; i < 3; i++) {
        p_mas[i].Resolve();
        cout << "Целая часть дроби Dynamic I : " << i << " (" << p_mas[i].first << "/" << p_mas[i].second << ") равна: ";
        cout << p_mas[i].Resolve() << endl;
    }

    // Работа через вызов функции make_ipart()
    cout << endl <<"Функция make_ipart()" << endl;

    unsigned y;
    unsigned z;

    cout << endl << "введите значение first: ";
    cin >> y;
    cout << endl << "введите значение second: ";
    cin >> z;

    ipart F = make_ipart(y, z);
    F.Show();
    F.Resolve();

    cout << "Целая часть дроби F (" << F.first << "/" << F.second << ") равна: " << F.Resolve() << endl;

    return 0;
}