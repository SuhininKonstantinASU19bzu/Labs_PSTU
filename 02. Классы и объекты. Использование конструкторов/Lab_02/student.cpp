#include <string>
#include <iostream>
#include "student.h"

using namespace std;

// Конструктор без параметров
Student::Student() {
	fullname = "";
	group = "";
	averagemark = 0;

	cout << "Конструктор без параметров для объекта: " << this << endl;
}

// Конструктор с параметрами
Student::Student(string F, string G, float A) {
	fullname = F;
	group = G;
	averagemark = A;

	cout << "Конструктор с параметрами для объекта: " << this << endl;
}

// Конструктор копирования
Student::Student(const Student& T) {
	fullname = T.fullname;
	group = T.group;
	averagemark = T.averagemark;

	cout << "Конструктор копирования для объекта: " << this << endl;
}

// Деструктор
Student::~Student() {
	cout << "Деструктор для объекта: " << this << endl;
}

// Селекторы
string Student::get_fullname() {
	return fullname;
}

string Student::get_group() {
	return group;
}

float Student::get_averagemark() {
	return averagemark;
}

// Модификаторы
void Student::set_fullname(string F) {
	fullname = F;
}

void Student::set_group(string G) {
	group = G;
}

void Student::set_averagemark(float A) {
	averagemark = A;
}

// Метод просмотра атрибутов
void Student::Show() {
	cout << endl << "ФИО: " << fullname << endl;
	cout << "Группа: " << group << endl;
	cout << "Средний балл: " << averagemark << endl << endl;
}