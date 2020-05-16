#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include "Time.h"
#include <list>

using namespace std;

typedef vector<Time> Vec; // Определение типа данных для работы с вектором
Vec::iterator it;

typedef list<Time> Lis;
Lis::iterator lit;

Time Z;

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

// Вычисление среднего арифметического
Time average(Vec v) {
    Time a;
    int n = v.size();

    for (int i = 0; i < v.size(); i++) {
        a = a + v[i];
    }

    return a / n;
}

void add_average(Time& t) {
    t = t + Z;
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

    Vec v;
    int n;

    cout << "Введите размер вектора: ";
    cin >> n;

    v = make_vector(n);

    print_vector(v);

    // Поиск и замена максимального элемента
    Vec v1(v.size()), v2(v.size()), v3;

    it = max_element(v.begin(),v.end());

    Z = *(it);

    Lis L;

    lit = max_element(L.begin(), L.end());

    Time el1;

    cout << "Введите новый элемент:" << endl;
    cout << "> ";
    cin >> el1;
    
    // replace_if
    cout << "Замена элемента через replace_if" << endl;

    replace_if(v.begin(), v.end(), Equal_Z(), el1);

    print_vector(v);

    // replace_copy
    cout << "Замена элемента через replace_copy" << endl;

    replace_copy(v.begin(), v.end(), v1.begin(), Z, el1);

    print_vector(v1);

    // replace_copy_if
    cout << "Замена элемента через replace_copy_if" << endl;

    replace_copy_if(v.begin(), v.end(), v2.begin(), Equal_Z(), el1);

    print_vector(v2);

    // fill
    cout << "Замена элемента через fill" << endl;

    v3 = v;

    it = max_element(v3.begin(), v3.end());

    fill(it, it, el1);

    print_vector(v3);

    // Поиск и удаление минимального элемента
    Vec v4, v5, v6(v.size()), v7(v.size());

    // remove
    v4 = v;

    cout << "Действие производится над копией вектора v" << endl;
    cout << "Удаление минимального элемента через remove" << endl;

    it = min_element(v4.begin(), v4.end());

    Z = *(it);

    remove(v4.begin(), v4.end(), Z);

    print_vector(v4);

    // remove_if
    v5 = v;

    cout << "Действие производится над копией вектора v" << endl;
    cout << "Удаление минимального элемента через remove_if" << endl;

    it = min_element(v5.begin(), v5.end());

    Z = *(it);

    remove_if(v5.begin(), v5.end(), Equal_Z());

    print_vector(v5);

    // remove_copy
    cout << "Удаление минимального элемента через remove_copy с записью на вектор v3" << endl;

    it = min_element(v.begin(), v.end());

    Z = *(it);

    remove_copy(v.begin(), v.end(), v6.begin(), Z);

    print_vector(v6);

    // remove_copy_if
    cout << "Удаление минимального элемента через remove_copy с записью на вектор v4" << endl;

    it = min_element(v.begin(), v.end());

    Z = *(it);

    remove_copy_if(v.begin(), v.end(), v7.begin(), Equal_Z());

    print_vector(v7);

    // Сортировка
    cout << "Сортировка по убыванию:" << endl;

    sort(v.begin(), v.end(), Compare_less());

    print_vector(v);

    cout << "Сортировка по возрастанию:" << endl;

    sort(v.begin(), v.end());

    print_vector(v);

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
    cout << "> "<< Z << endl;
    cout << "Добавление среднего арифметического ко всем элементам:" << endl;

    for_each(v.begin(), v.end(), add_average);

    print_vector(v);

    return 0;
}