#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Vector {
	// Атрибуты
protected:
	int size; // Текущий размер
	int* beg; // Указатель на начало динамического массива

public:
	// Конструкторы
	Vector(); // Без параметров
	Vector(int s); // С параметрами
	Vector(int s, int* mas); // С параметрами
	Vector(const Vector& v); // Копирования

	// Деструкторы
	~Vector();

	// Методы
	Vector Add(int d);

	// Операторы
	const Vector& operator =(const Vector& v);
	int operator[](int i);
	int operator ()();
	Vector operator +(int a);
	Vector operator -(int n);
	Vector operator --();


	// Глобальные функции ввода-вывода
	friend istream& operator >>(istream& in, Vector& v);
	friend ostream& operator <<(ostream& out, const Vector& v);
};