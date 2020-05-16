#include <iostream>
#include <string>
#include <cstdio>
#include <locale>
#include "student.h"

using namespace std;

// Функция для возврата объекта как результата
Student make_student() {
    string f;
    string g;
    float a;

    cout << endl << "Введите ФИО: ";
    getline(cin, f);
    cout << endl << "Введите группу: ";
    getline(cin, g);
    cout << endl << "Введите средний балл: ";
    cin >> a;
    cout << endl;

    Student s(f, g, a);

    return s;
}

// Функция для передачи объекта как параметра
void print_student(Student s) {
    s.Show();
}

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    // Конструктор без параметров
    Student s1;
    s1.Show();

    // Конструктор с параметрами
    Student s2("Иванов Сергей Петрович", "ST-HL", 45);
    s2.Show();

    // Конструктор копирования
    Student s3 = s2;
    s3.Show();

    // Внесение изменений посредством модификатора тоже является конструктором копирования
    s3.set_fullname("Michail Viktor");
    s3.set_group("UBCS");
    s3.set_averagemark(75);

    // Конструктор копирования ???
    print_student(s3);

    // Конструктор с параметрами -> Конструктор копирования
    s1 = make_student();
    s1.Show();

    // Вывод с использованием селекторов
    string FN;
    string GP;
    float AM;

    FN = s2.get_fullname();
    GP = s2.get_group();
    AM = s2.get_averagemark();

    cout << "ФИО: " << FN << endl;
    cout << "Группа: " << GP << endl;
    cout << "Средний балл: " << AM << endl << endl;

    return 0;
}