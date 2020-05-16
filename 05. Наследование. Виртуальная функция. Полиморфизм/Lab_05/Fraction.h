#pragma once
#include "Pair.h"

// Класс Fraction наследуется от класса Pair
class Fraction :
	public Pair {

	// Атрибуты (Наследуются от базового класса Pair)
//private:
	// Атрибут;

public:
	// Конструкторы
	Fraction(); // Без параметров
	Fraction(int, int); // С параметрами
	Fraction(const Fraction&); // Копирования

	// Деструктор
	~Fraction();

	// Селекторы (Наследуются от базового класса Pair)
	//int get_first();
	//int get_second();

	// Модификаторы (Наследуются от базового класса Pair)
	//void set_first(int);
	//void set_second(int);

	// Операция присваивания
	Fraction& operator =(const Fraction&);

	// Операции сравнения
	bool operator ==(const Fraction&);
	bool operator !=(const Fraction&);
	bool operator >=(const Fraction&);
	bool operator <=(const Fraction&);
	bool operator >(const Fraction&);
	bool operator <(const Fraction&);

	// Метод выделения целой части дроби (Тестовый!!!)
	int Resolve();

	void Compare() {}; // Заготовка для функции сравнения

	void Show(); // Функция просмотра атрибутов класса с помощью указателя

	// Операции ввода-вывода
	friend istream& operator >>(istream& in, Fraction& f);
	friend ostream& operator <<(ostream& out, const Fraction& f);
};