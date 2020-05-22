#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <locale>

using namespace std;
const int TABLE_SIZE = 200;

class HashTableEntry {
public:
    string key;
    string group;
    int rating;

    HashTableEntry(string key, string group, int rating) {
        this->key = key;
        this->group = group;
        this->rating = rating;
    }
};

class HashMapTable {
private:
    HashTableEntry** t;

public:
    HashMapTable();

    int hash_func(string key);

    // Длбавление элемента
    void add(string key, string group, int rating);

    // Создание и заполнение таблицы
    void generate_filled_table(int size);

    // Поиск по ключу
    void search_key(string key);

    // Поиск по индексу
    void search_index(int index);

    // Редактирование элемента по индексу
    void edit_index(int index);

    // Редактирование элемента по ключу
    void edit_key(string key);

    // Удаление по индексу
    void del_index(int index);

    // Удаление по ключу
    void del_key(string key);

    // Деструктор
    ~HashMapTable();

    void show_table();

    // Подсчет колличества коллизий
    int collision_count();
};

HashMapTable::HashMapTable() {
    t = new HashTableEntry * [TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        t[i] = NULL;
    }
}

int HashMapTable::hash_func(string key) {
    int asciiSum = 0;

    for (int i = 0, p = 1; i < key.size(); i++, p++) {
        asciiSum += key[i] * p;
    }

    return asciiSum % TABLE_SIZE;
}

// Длбавление элемента
void HashMapTable::add(string key, string group, int rating) {
    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) delete t[index];

    t[index] = new HashTableEntry(key, group, rating);
}

// Создание и заполнение таблицы
void HashMapTable::generate_filled_table(int size) {
    if (size > TABLE_SIZE) {
        cout << "Превышен максимальный размер" << endl;

        return;
    }

    if (size < 0) {
        cout << "Размер задан не корректно";

        return;
    }

    vector<string> names = {
        "Oliver", "Jack", "Harry",
        "Jacob", "Charlie", "Thomas",
        "George", "Oscar", "James",
        "William"
    };

    vector<string> surnames = {
        "Smith", "Jones", "Taylor",
        "Davies", "Evans", "Johnson",
        "Roberts", "Robinson", "Thompson",
        "Green"
    };

    vector<string> patronymics = {
        "Adamson", "Barson", "Hobson",
        "Wilson", "Fennel", "Coleson",
        "Jackson", "Iveson", "Tennyson",
        "Garrison"
    };

    vector<string> groups = {
        "Alpha", "Betta", "Hamma",
        "Sigma", "Delta", "Omega",
        "Epsilon", "Lambda", "Omicron"
    };

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        string key = {
            names[rand() % names.size()] + ' '
            + surnames[rand() % surnames.size()] + ' '
            + patronymics[rand() % patronymics.size()]
        };
        string group = { groups[rand() % groups.size()] };
        int rating = rand() % 100;

        add(key, group, rating);
    }
}


// Поиск по ключу
void HashMapTable::search_key(string key) {
    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) {
        cout << "ФИО: " << t[index]->key << endl;
        cout << "Группа: " << t[index]->group << endl;
        cout << "Рейтинг: " << t[index]->rating << endl;
    }
    else {
        cout << "Нет такого элемента" << endl;
    }
}

// Поиск по индексу
void HashMapTable::search_index(int index) {
    if (t[index] != NULL) {
        cout << "ФИО: " << t[index]->key << endl;
        cout << "Группа: " << t[index]->group << endl;
        cout << "Рейтинг: " << t[index]->rating << endl;
    }
    else {
        cout << "Нет такого элемента" << endl;
    }
}

// Редактирование элемента по индексу
void HashMapTable::edit_index(int index) {
    string group;
    int rating;

    if (t[index] != NULL) {
        cout << "Введите новый элемент" << endl;
        cout << "Группа >";

        cin >> group;

        cout << "Рейтинг >";

        cin >> rating;

        t[index]->group = group;
        t[index]->rating = rating;
    }
    else {
        cout << "Нет элемента с указаным индексом" << endl;
    }
}

// Редактирование элемента по ключу
void HashMapTable::edit_key(string key) {
    string new_key;
    string group;
    int rating;

    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) {
        cout << "Введите новый элемент" << endl;

        cout << "Группа >";

        cin >> group;

        cout << "Рейтинг >";

        cin >> rating;

        t[index]->group = group;
        t[index]->rating = rating;
    }
    else {
        cout << "Нет элемента с указаным ключем" << endl;
    }
}

// Удаление по индексу
void HashMapTable::del_index(int index) {
    if (t[index] != NULL) {
        delete t[index];

        t[index] = NULL;

        cout << "Элемент удален" << endl;
    }
    else {
        cout << "Нет элемента с указаным индексом" << endl;
    }
}

// Удаление по ключу
void HashMapTable::del_key(string key) {
    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) {
        delete t[index];

        t[index] = NULL;

        cout << "Элемент удален" << endl;
    }
    else {
        cout << "Нет элемента с указаным ключем" << endl;
    }
}

// Деструктор
HashMapTable::~HashMapTable() {

}

void HashMapTable::show_table() {
    cout << endl << setw(0) << "Индекс";
    cout << setw(15) << "ФИО";
    cout << setw(23) << "Группа";
    cout << setw(13) << "Рейтинг" << endl;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (t[i] != NULL) {
            int index = hash_func(t[i]->key);

            cout << setw(4) << index << setw(30);
            cout << t[i]->key << setw(10);
            cout << t[i]->group << setw(10);
            cout << t[i]->rating << endl;
        }
    }
}

// Подсчет колличества коллизий
int HashMapTable::collision_count() {
    int count = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {

        if (t[i] != NULL) {

            int index = hash_func(t[i]->key);

            if (i != index) {
                count++;
            }
        }
    }

    return count;
}