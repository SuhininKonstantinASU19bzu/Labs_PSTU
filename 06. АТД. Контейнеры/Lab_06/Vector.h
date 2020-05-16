#pragma once
#include <iostream>

using namespace std;

class Iterator {
	friend class Vector; // Дружественный класс

	// Аргументы
private:
	int* elem; // Указатель на элемент типа int

public:
	// Конструкторы
	Iterator() { elem = 0; } // Без параметров
	Iterator(const Iterator& it) { elem = it.elem; } // Копирования

	// Перегруженные операции
	// Сравнения
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; }

	// Инкремент
	void operator ++() { ++elem; }

	// Декремент
	void operator --() { --elem; }

	// Разименования
	int& operator *() const { return *elem; }
};

class Vector {
	// Аргументы
private:
	int size; // Размер вектора
	int* data; // Указатель на динамический массив значений вектора
	Iterator beg; // Указатель на первый элемент вектора
	Iterator end; // Указатель на элемент вектора следующий за последним

public:
	// Конструкторы
	Vector(); // Без параметров
	Vector(int s, int k = 0); // С параметрами (Выделяет память под s элементов и заполняет их значением k)
	Vector(const Vector& v); // Копирования

	// Деструкторы
	~Vector();

	// Указатели
	Iterator first() { return beg; } // Возвращает указатель на первый элемент
	Iterator last() { return end; } // Возвращает указатель на элемен следующий за последним

	// Оператор присваивания
	Vector& operator =(const Vector& v);

	// Операция доступа по индексу
	int& operator [](int index);

	// Операция добавления константы
	Vector operator +(const int k);

	// Операция возвращения длины вектора
	int operator ()();

	// Перегруженые операции ввода-вывода
	friend istream& operator >>(istream& in, Vector& v);
	friend ostream& operator <<(ostream& out, const Vector& v);
};