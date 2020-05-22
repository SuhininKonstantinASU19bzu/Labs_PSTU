#pragma once
#include <iostream>
#include <iomanip>
#include <list>
#include "Weather.h"

using namespace std;

typedef list<Weather> List;
typedef List::iterator Lit;

// Функция формирования контейнера
List make_list(int n) {
    List l;

    for (int i = 0; i < n; i++) {
        int d = rand() % 30;
        int t = rand() % 60 - 30;

        Weather a(d, t);

        l.push_back(a);
    }

    return l;
}

// Функция для печати контейнера
void print_list(List l) {
    cout << "| Дата      : Температура |" << endl;

    for (Lit i = l.begin(); i != l.end(); i++) {
        cout << (*i);
    }

    cout << endl;
}

// Резервная копия
void backup(List l, List& b) {
        b.clear();

        for (Lit i = l.begin(); i != l.end(); i++) {
            b.push_back((*i));
        }
}

// Восстановление резервной копии
void rewind(List& l, List b) {
    l.clear();

    for (Lit i = b.begin(); i != b.end(); i++) {
        l.push_back((*i));
    }
}

// Удаление элемента из позиции pos
void del_pos(List& l, int pos, bool& cheange) {
    if (pos > l.size()) {
        cout << "Недопустимая позиция" << endl;
        return;
    }

    Lit i = l.begin();

    while (--pos) {
        i++;
    }

    (*i).set_del(true);

    if (!cheange) cheange = true;
}

// Удаление помеченых записей перезаписью контейнера
void del_mark(List& l) {
    List temp;

    for (Lit i = l.begin(); i != l.end(); i++) {
        if (!(*i).get_del()) //Проверка наличия отметки удаления
        temp.push_back((*i));
    }

    l = temp;
}

// Подсчет помеченых записей
int count_mark(List l) {
    int counter = 0;

    for (Lit i = l.begin(); i != l.end(); i++) {
        if ((*i).get_del()) counter++;
    }

    return counter;
}

// Функция удаления помеченых записей
void del_operation(List& l, List& b) {
    if (count_mark(l) > (l.size() / 2)) {
        del_mark(l);

        cout << "Помеченые записи удалены" << endl;
    }

    b.clear();

    b = l;
}

// Удаление по ключу
void del_key(List& l, Weather key, bool& cheange) {
    Lit i = l.begin();

    while ((*i) != key) {
        i++;

        if (i == l.end()) {
            cout << "Ключ не найден" << endl;
            return;
        }
    }

    (*i).set_del(true);

    if (!cheange) cheange = true;
}

// Добавление элемента el в позицию pos
void add_pos(List& l, Weather el, int pos, bool& cheange) {
    Lit i = l.begin();

    while (pos--) {
        i++;
    }

    l.emplace(i, el);

    if (!cheange) cheange = true;
}

void change_pos(List& l, Weather el, int pos, bool& cheange) {
    Lit i = l.begin();

    while (pos--) {
        i++;
    }

    (*i) = el;

    if (!cheange) cheange = true;
}

void change_key(List& l, Weather el, Weather key, bool& cheange) {
    for (Lit i = l.begin(); i != l.end(); i++) {
        if ((*i) == key) (*i) = el;
    }

    if (!cheange) cheange = true;
}

// Добавление в конец
void add_end(List& l, Weather el, bool& cheange) {
    l.push_back(el);

    if (!cheange) cheange = true;
}

// Добавление элемента el в начало
void add_begin(List& l, Weather el, bool& cheange) {
    l.push_front(el);

    if (!cheange) cheange = true;
}

// Вычисление среднего арифметического
Weather average(List l) {
    Weather a;
    int n = l.size() - count_mark(l);

    for (Lit i = l.begin(); i != l.end(); i++) {
        a = a + (*i);
    }

    return a / n;
}

void average_day(List l) {
    List temp;
    Weather a = average(l);

    cout << "Среднее значение температуры" << a.get_temp() << endl;

    for (Lit i = l.begin(); i != l.end(); i++) {
        if ((*i) > a) temp.push_back((*i));
    }

    print_list(temp);
}

// Наибольший промежуток с отрицательной погодой
int min_range(List l) {
    list<int> lt;
    list<int>::iterator it;
    int range = 0;
    int maxrange = 0;

    for (Lit i = l.begin(); i != l.end(); i++) {
        if ((*i) > 0) {
            if (!(*i).get_del()) {
            range++;
            }

            lt.push_back(range);
        }
        else range = 0;
    }

    for (it = lt.begin(); it != lt.end(); it++) {
        if (maxrange < (*it)) {
            maxrange = (*it);
        }
    }

    return maxrange;
}

void add_el(List& l, Weather el) {
    for (Lit i = l.begin(); i != l.end(); i++) {
        (*i) = (*i) + el;
    }
}