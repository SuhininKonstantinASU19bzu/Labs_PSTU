#include <iostream>
#include <locale>
#include <map>

using namespace std;

typedef multimap<int, double> TMap;
typedef TMap::iterator it;


// Функция формирования вектора
TMap make_map(int n) {
    TMap m;

    for (int i = 0; i < n; i++) {
        int a = rand() % 100 - 50;

        m.insert(make_pair(i, a));
    }

    return m;
}

// Функция для печати вектора
void print_map(TMap m) {
    for (it i = m.begin(); i != m.end(); i++) {
        cout << (*i).first << " : " << (*i).second << " | ";
    }

    cout << endl;
}

// Удаление элемента из позиции pos
void del_pos(TMap& m, double pos) {
    m.erase(pos);
}

// Добавление элемента el в позицию pos
void add_pos(TMap& m, double el, double pos) {
    m.emplace(pos, el);
}

// Добавление в конец
void add_end(TMap& m, double el) {
    it i = m.end();

    --i;

    m.insert(make_pair((*i).first + 1, el));
}

// Добавление элемента el в начало
void add_begin(TMap& m, double el) {
    TMap temp;

    temp.emplace(0, el);

    for (it i = m.begin(); i != m.end(); i++) {
        add_end(temp, (*i).second);
    }

    m = temp;
}

void add_multibeg(TMap& m, double el) {
    m.emplace(0, el);
}


// Вычисление среднего арифметического
double average(TMap m) {
    double a = 0;
    int n = m.size();

    for (it i = m.begin(); i != m.end(); i++) {
        a += (*i).second;
    }

    return a / n;
}

void add_el(TMap& m, double a) { 
    for (it i = m.begin(); i != m.end(); i++) {
        (*i).second += a;
    }
}

// Поиск ключа максимального элемента
int max_key(TMap m) {
    it i = m.begin();

    double max = (*i).second; // Максимальный элемент (Значение первого элемента)
    int key = (*i).first;

    while (i != m.end()) {
        if (max < (*i).second) {
            max = (*i).second;
            key = (*i).first;
        }

        i++; // Итератор
    }

    cout << "max key: " << key << " : " << max;

    return key;
}

// Поиск значения максимального элемента
double max_el(TMap m) {
    double max = 0;

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

    double min = (*i).second; // Максимальный элемент (Значение первого элемента)
    int key = (*i).first;

    while (i != m.end()) {
        if (min > (*i).second) {
            min = (*i).second;
            key = (*i).first;
        }

        i++; // Итератор
    }

    return key;
}


int main() {
    setlocale(LC_ALL, "rus");

    TMap m1, m2;
    double max;
    int n;

    cout << "Введите размер контейнера:" << endl;
    cout << "> ";
    cin >> n;

    m1 = make_map(n);

    cout << "Сформированый контейнер:" << endl;
    cout << "> | ";
    print_map(m1);

    // Поиск максимального элемента
    max = max_el(m1);

    cout << "Максимальный элемент найден" << endl;
    cout << "> " << max << endl;

    m2 = m1;

    add_multibeg(m2, max);

    cout << "Максимальный элемент добавлен в позицию 0" << endl;
    cout << "> | ";
    print_map(m2);

    add_begin(m1, max);

    cout << "Максимальный элемент добавлен в начало перезаписью контейнера" << endl;
    cout << "> | ";
    print_map(m1);

    return 0;
}