#include <iostream>
#include <locale>
#include <set>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef set<Time, less<Time>> TSet;
typedef set<Time, greater<Time>> TSetG;

TSet::iterator it;
TSetG::iterator itg;

Time Z;

TSet FEA;

// Функция формирования вектора
TSet make_set(int n) {
    TSet T;

    for (int i = 0; i < n; i++) {
        int m = rand() % 60;
        int s = rand() % 60;

        Time a(m, s);

        T.insert(a);
    }

    return T;
}

// Функция для печати вектора
void print_set(TSet T) {
    for (it = T.begin(); it != T.end(); it++) {
        cout << (*it) << " | ";
    }

    cout << endl;
}

void print_set(TSetG T) {
    for (itg = T.begin(); itg != T.end(); itg++) {
        cout << (*itg) << " | ";
    }

    cout << endl;
}

// Вычисление среднего арифметического
Time average(TSet T) {
    Time a;
    int n = T.size();

    for (it = T.begin(); it != T.end(); it++) {
        a = a + (*it);
    }

    return a / n;
}

Time average_to_add(const Time& t) {

    const Time& TA = t + Z;

    return TA;
}

void resort(const TSet& in, TSetG& out) {
    for (it = in.begin(); it != in.end(); it++) {
        const Time& BE = *(it);
        out.insert(BE);
    }
}

// Предиктаты
struct Greater_Z {
    bool operator ()(Time t) {
        if (t > Z) return true;
        else return false;
    }
};

struct Lower_Z {
    bool operator ()(Time t) {
        if (t < Z) return true;
        else return false;
    }
};

struct Equal_Z {
    bool operator ()(Time t) {
        if (t == Z) return true;
        else return false;
    }
};

struct Compare_less {
    bool operator ()(Time t1, Time t2) {
        if (t1 > t2) return true;
        else return false;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    TSet v;
    int n;

    cout << "Введите размер контейнера: ";
    cin >> n;

    v = make_set(n);

    print_set(v);

    // Поиск и замена максимального элемента
    TSet v1, v2, v3;

    it = max_element(v.begin(), v.end());

    Z = *(it);

    cout << "Максимальный элемент: " << Z << endl;

    Time el1;

    cout << "Введите новый элемент:" << endl;
    cout << "> ";
    cin >> el1;

    v.erase(Z);

    v.insert(el1);

    cout << "Замена элемента:" << endl;

    print_set(v);

    // remove
    cout << "Удаление минимального элемента:" << endl;

    it = min_element(v.begin(), v.end());

    Z = *(it);

    v.erase(Z);

    print_set(v);

    // Сортировка
    TSetG v7;

    cout << "Сортировка по убыванию:" << endl;
    cout << "Возможна только путем заполнения иначе объявленного контейнера" << endl;

    resort(v, v7);

    print_set(v7);

    cout << "Сортировка по возрастанию используется по умолчанию" << endl;

    print_set(v);

    // Поиск заданного элемента
    // find
    cout << "Поиск через find" << endl;
    cout << "Введите элемент для поиска:" << endl;
    cout << "> ";
    cin >> Z;

    it = find(v.begin(), v.end(), Z);

    if (it != v.end()) cout << "> " << *(it) << endl;
    else cout << "Нет такого элемента" << endl;

    // find_if
    cout << "Поиск через find_if" << endl;
    cout << "Введите элемент для поиска:" << endl;
    cout << "> ";
    cin >> Z;

    it = find_if(v.begin(), v.end(), Equal_Z());

    if (it != v.end()) cout << "> " << *(it) << endl;
    else cout << "Нет такого элемента" << endl;

    // count;
    cout << "Поиск через count" << endl;
    cout << "Введите элемент для поиска:" << endl;
    cout << "> ";
    cin >> Z;

    int C = count(v.begin(), v.end(), Z);

    cout << "Количество найденых элементов:";
    cout << "> " << C << endl;

    //count_if();
    cout << "Поиск через count_if" << endl;
    cout << "Введите элемент для поиска:" << endl;
    cout << "> ";
    cin >> Z;

    C = count_if(v.begin(), v.end(), Equal_Z());

    cout << "Количество найденых элементов:";
    cout << "> " << C << endl;

    // Вычисление среднего и добавление ко всем элементам
    Z = average(v);

    cout << "Среднее арифметическое:" << endl;
    cout << "> " << Z << endl;
    cout << "Добавление среднего арифметического ко всем элементам:" << endl;

    for_each(v.begin(), v.end(), [](const Time& t) {FEA.insert(t + Z);});

    print_set(FEA);

    return 0;
}