#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Vector {
	// Атрибуты
private:
	int size; // Размер
	int cur; // Текущая позиция
	Object** beg; // Указатель на первый элемент вектора

public:
	// Конструкторы
	Vector(); // Без параметров
	Vector(int); // С параметрами

	// Деструкторы
	~Vector();

	// Методы
	void Add(Object*); // Добавление элемента в вектор

	// Глобальные операции ввода-вывода
	friend ostream& operator <<(ostream& out, const Vector& v);
};

