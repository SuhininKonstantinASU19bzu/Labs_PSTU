#include <iostream>
#include <locale>
#include <cstdlib>
#include <vector>
#include "Time.h"

using namespace std;

typedef vector<Time> Vec; // Определение типа данных для работы с вектором

// Функция формирования вектора
Vec make_vector(int n) {
    Vec v;

    for (int i = 0; i < n; i++) {
        int m = rand() % 60;
        int s = rand() % 60;

        Time a(m, s);

        v.push_back(a); // Добавление элемента в конец вектора
    }

    return v;
}

// Функция для печати вектора
void print_vector(Vec v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " | ";

    cout << endl;
}

// Удаление элемента из позиции pos
void del_pos(Vec& v, int pos) {
    v.erase(v.begin() + pos);
}

// Добавление элемента el в позицию pos
void add_pos(Vec& v, Time el, int pos) {
    v.insert(v.begin() + pos - 1, el);
}

// Добавление элемента el в начало вектора
void add_begin(Vec& v, Time el) {
    v.insert(v.begin(), el);
}

// Вычисление среднего арифметического
Time average(Vec v) {
    Time a;
    int n = v.size();

    for (int i = 0; i < v.size(); i++) {
       a = a + v[i];
        cout << a << endl;
    }

    return a / n;
}

// Поиск максимального элемента
int max(Vec v) {
    Time m = v[0]; // Максимальный элемент
    int n = 0; // Номер максимального элемента

    for (int i = 0; i < v.size(); i++) {
        if (m < v[i]) {
            m = v[i]; // Найденый максимальный элемент
            n = i; // Найденый номер максимального элемента
        }
    }

    return n;
}

// Поиск минимального элемента
int min(Vec v) {
    Time m = v[0]; // Минимальный элемент
    int n = 0; // Номер минимального элемента

    for (int i = 0; i < v.size(); i++) {
        if (m > v[i]) {
            m = v[i]; // Найденый минимальный элемент
            n = i; // Найденый номер минимального элемента
        }
    }

    return n;
}


int main() {
    setlocale(LC_ALL, "rus");

    try {
        vector<Time> v;
        vector<Time>::iterator vi = v.begin();
        int n;

        cout << "Введите размер вектора: ";
        cin >> n;

        v = make_vector(n);

        print_vector(v);

        int pos;

        pos = min(v);

        del_pos(v, pos);

        print_vector(v);

    }
    catch (int e) {
        cout << "ERROR_CODE_" << e << endl;
    }

    return 0;
}