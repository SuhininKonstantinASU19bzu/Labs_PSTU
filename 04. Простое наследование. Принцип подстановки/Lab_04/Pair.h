#pragma once
#include <iostream>

using namespace std;

class Pair {
	// Атрибуты
protected:
	int first;
	int second;

public:
	// Конструкторы
	Pair(); // Без параметров
	Pair(int, int); // С параметрами
	Pair(const Pair&); // Копирования

	// Деструктор
	virtual ~Pair();

	// Селекторы
	int get_first();
	int get_second();

	// Модификаторы
	void set_first(int);
	void set_second(int);

	// Перегрузка операции присваивания
	Pair& operator =(const Pair&);

	// Операции сравнения
	bool operator >(const Pair&);

	// Глобальные операторы-функции ввода-вывода
	friend istream& operator >>(istream& in, Pair& p);
	friend ostream& operator <<(ostream& out, const Pair& p);
};


