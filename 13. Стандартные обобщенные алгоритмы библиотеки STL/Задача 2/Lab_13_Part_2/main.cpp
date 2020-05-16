#include <iostream>
#include <locale>
#include <vector>
#include <stack>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef vector<Time> Vec; // Определение типа данных для работы с вектором
typedef stack<Time> St;

Vec::iterator it;

Time Z;

// Функция формирования стека
St make_stack(int n) {
    St S;

    for (int i = 0; i < n; i++) {
        int m = rand() % 60;
        int s = rand() % 60;

        Time a(m, s);

        S.push(a); // Добавление элемента в конец
    }

    return S;
}

Vec stack_to_vector(St S) {
    Vec v;

    while (!S.empty()) {
        v.push_back(S.top());
        S.pop();
    }

    return v;
}

St vector_to_stack(Vec v) {
    St S;

    for (int i = 0; i < v.size(); i++) {
        S.push(v[i]);
    }

    return S;
}

// Функция для печати вектора
void print_stack(St& S) {
    Vec v = stack_to_vector(S);

    while (!S.empty()) {
        cout << S.top() << " | ";
        S.pop();
    }

    cout << endl;

    S = vector_to_stack(v);
}

// Вычисление среднего арифметического
Time average(St S) {
    Vec v = stack_to_vector(S);
    Time a;
    int n = 0;

    do
    {
        a = a + S.top();
        S.pop();
        n++;

    } while (!S.empty());

    S = vector_to_stack(v);

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
    St S;
    int n;

    cout << "Введите размер стека: ";
    cin >> n;

    S = make_stack(n);

    print_stack(S);

    // Поиск и замена максимального элемента
    v = stack_to_vector(S);

    it = max_element(v.begin(), v.end());

    Z = *(it);

    Time el1;

    cout << "Введите новый элемент:" << endl;
    cout << "> ";
    cin >> el1;

    // replace_if
    cout << "Замена элемента через replace_if" << endl;

    replace_if(v.begin(), v.end(), Equal_Z(), el1);

    S = vector_to_stack(v);

    print_stack(S);

    // Поиск и удаление минимального элемента
    Vec v2(v.size() - 1);

    // remove_copy
    cout << "Удаление минимального элемента через remove_copy" << endl;

    it = min_element(v.begin(), v.end());

    Z = *(it);

    remove_copy(v.begin(), v.end(), v2.begin(), Z);

    S = vector_to_stack(v2);

    print_stack(S);

    // Поиск заданного элемента
    // find
    cout << "Поиск через find" << endl;
    cout << "Введите элемент для поиска:" << endl;
    cout << "> ";
    cin >> Z;

    v = stack_to_vector(S);

    it = find(v.begin(), v.end(), Z);

    cout << "Найденный элемент: " << (*it) << endl;

    it = v.begin();

    S = vector_to_stack(v);

    print_stack(S);

    // Вычисление среднего и добавление ко всем элементам
    Z = average(S);

    v = stack_to_vector(S);

    cout << "Среднее арифметическое:" << endl;
    cout << "> " << Z << endl;
    cout << "Добавление среднего арифметического ко всем элементам:" << endl;

    for_each(v.begin(), v.end(), add_average);

    S = vector_to_stack(v);

    print_stack(S);

    return 0;
}