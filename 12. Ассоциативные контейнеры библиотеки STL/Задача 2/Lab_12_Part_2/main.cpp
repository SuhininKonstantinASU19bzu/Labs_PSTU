#include <iostream>
#include <locale>
#include <map>
#include "Time.h"

using namespace std;

typedef multimap<int, Time> TMap;
typedef TMap::iterator it;


// Функция формирования вектора
TMap make_map(int n) {
    TMap M;

    for (int i = 0; i < n; i++) {
        int m = rand() % 60;
        int s = rand() % 60;

        Time a(m, s);

        M.insert(make_pair(i, a));
    }

    return M;
}

// Функция для печати вектора
void print_map(TMap m) {
    for (it i = m.begin(); i != m.end(); i++) {
        cout << (*i).first << " | " << (*i).second << " | ";
    }

    cout << endl;
}

// Удаление элемента из позиции pos
void del_pos(TMap& m, int pos) {
    m.erase(pos);
}

// Добавление элемента el в позицию pos
void add_pos(TMap& m, Time el, int pos) {
    m.emplace(pos, el);
}

// Добавление в конец
void add_end(TMap& m, Time el) {
    it i = m.end();

    --i;

    m.insert(make_pair((*i).first + 1, el));
}

// Добавление элемента el в начало
void add_begin(TMap& m, Time el) {
    TMap temp;

    temp.emplace(0, el);

    for (it i = m.begin(); i != m.end(); i++) {

        add_end(temp, (*i).second);
    }

    m = temp;
}

void add_multibeg(TMap& m, Time el) {
    m.emplace(0, el);
}


// Вычисление среднего арифметического
Time average(TMap m) {
    Time a;
    int n = m.size();

    for (it i = m.begin(); i != m.end(); i++) {
        a = a + (*i).second;
    }

    return a / n;
}

void add_el(TMap& m, Time a) {
    for (it i = m.begin(); i != m.end(); i++) {
        (*i).second = (*i).second + a;
    }
}

// Поиск ключа максимального элемента
int max_key(TMap m) {
    it i = m.begin();

    Time max = (*i).second; // Максимальный элемент (Значение первого элемента)
    int key = (*i).first;

    for (i = m.begin(); i != m.end(); i++) {
        if (max < (*i).second) {
            max = (*i).second;
            key = (*i).first;
        }
    }

    return key;
}

// Поиск значения максимального элемента
Time max_el(TMap m) {
    Time max;

    for (it i = m.begin(); i != m.end(); i++) {
        if (max < (*i).second) {
            max = (*i).second;
        }
    }

    return max;
}

// Поиск ключа минимального элемента
int min(TMap m) {
    it i = m.begin();
    Time min = (*i).second; // Значение первого элемента
    int key;

    for (i = m.begin(); i != m.end(); i++) {
        if (min > (*i).second) {
            min = (*i).second;
            key = (*i).first;
        }
    }

    return key;
}


int main() {
    setlocale(LC_ALL, "rus");

    TMap m1, m2;
    int n;

    cout << "Введите размер контейнера:" << endl;
    cout << "> ";
    cin >> n;

    m1 = make_map(n);

    cout << "Сформированый контейнер:" << endl;
    cout << "> | ";
    print_map(m1);

    int findMin = min(m1);

    del_pos(m1, findMin);

    cout << "Минимальный элемент удален" << endl;
    cout << "> | ";
    print_map(m1);

    return 0;
}