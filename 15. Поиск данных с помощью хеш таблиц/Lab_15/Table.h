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

    // ���������� ��������
    void add(string key, string group, int rating);

    // �������� � ���������� �������
    void generate_filled_table(int size);

    // ����� �� �����
    void search_key(string key);

    // ����� �� �������
    void search_index(int index);

    // �������������� �������� �� �������
    void edit_index(int index);

    // �������������� �������� �� �����
    void edit_key(string key);

    // �������� �� �������
    void del_index(int index);

    // �������� �� �����
    void del_key(string key);

    // ����������
    ~HashMapTable();

    void show_table();

    // ������� ����������� ��������
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

// ���������� ��������
void HashMapTable::add(string key, string group, int rating) {
    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) delete t[index];

    t[index] = new HashTableEntry(key, group, rating);
}

// �������� � ���������� �������
void HashMapTable::generate_filled_table(int size) {
    if (size > TABLE_SIZE) {
        cout << "�������� ������������ ������" << endl;

        return;
    }

    if (size < 0) {
        cout << "������ ����� �� ���������";

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


// ����� �� �����
void HashMapTable::search_key(string key) {
    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) {
        cout << "���: " << t[index]->key << endl;
        cout << "������: " << t[index]->group << endl;
        cout << "�������: " << t[index]->rating << endl;
    }
    else {
        cout << "��� ������ ��������" << endl;
    }
}

// ����� �� �������
void HashMapTable::search_index(int index) {
    if (t[index] != NULL) {
        cout << "���: " << t[index]->key << endl;
        cout << "������: " << t[index]->group << endl;
        cout << "�������: " << t[index]->rating << endl;
    }
    else {
        cout << "��� ������ ��������" << endl;
    }
}

// �������������� �������� �� �������
void HashMapTable::edit_index(int index) {
    string group;
    int rating;

    if (t[index] != NULL) {
        cout << "������� ����� �������" << endl;
        cout << "������ >";

        cin >> group;

        cout << "������� >";

        cin >> rating;

        t[index]->group = group;
        t[index]->rating = rating;
    }
    else {
        cout << "��� �������� � �������� ��������" << endl;
    }
}

// �������������� �������� �� �����
void HashMapTable::edit_key(string key) {
    string new_key;
    string group;
    int rating;

    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) {
        cout << "������� ����� �������" << endl;

        cout << "������ >";

        cin >> group;

        cout << "������� >";

        cin >> rating;

        t[index]->group = group;
        t[index]->rating = rating;
    }
    else {
        cout << "��� �������� � �������� ������" << endl;
    }
}

// �������� �� �������
void HashMapTable::del_index(int index) {
    if (t[index] != NULL) {
        delete t[index];

        t[index] = NULL;

        cout << "������� ������" << endl;
    }
    else {
        cout << "��� �������� � �������� ��������" << endl;
    }
}

// �������� �� �����
void HashMapTable::del_key(string key) {
    int index = hash_func(key);

    while (t[index] != NULL && t[index]->key != key) {
        index++;
    }

    if (t[index] != NULL) {
        delete t[index];

        t[index] = NULL;

        cout << "������� ������" << endl;
    }
    else {
        cout << "��� �������� � �������� ������" << endl;
    }
}

// ����������
HashMapTable::~HashMapTable() {

}

void HashMapTable::show_table() {
    cout << endl << setw(0) << "������";
    cout << setw(15) << "���";
    cout << setw(23) << "������";
    cout << setw(13) << "�������" << endl;

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

// ������� ����������� ��������
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