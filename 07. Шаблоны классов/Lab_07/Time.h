#pragma once
#include <iostream>

using namespace std;

class Time {
	int min, sec;

public:
	// Конструкторы
	Time(); // Без параметров
	Time(int m, int s); // С параметрами
	Time(const Time& t); // Копирования

	// Деструкторы
	~Time();

	// Селекторы
	int get_min();
	int get_sec();

	// Модификаторы
	void set_min(int m);
	void set_sec(int s);

	// Перегруженные операции
	// Префиксные операции
	Time& operator =(const Time&);
	Time& operator ++();

	// Постфиксные операции
	Time operator ++(int);
	Time operator +(const Time&);
	Time operator +(const int);

	// Операция сравнения
	bool operator ==(const Time&); // bool& ???

	// Глобальные функции ввода-вывода
	friend istream& operator >>(istream& in, Time& t);
	friend ostream& operator <<(ostream& out, const Time& t);
};