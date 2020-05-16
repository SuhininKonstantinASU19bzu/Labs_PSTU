#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Person :
	public Object {

	// Атрибуты
protected:
	string name;
	int age;

public:
	// Конструкторы
	Person(); // Без параметров
	Person(string, int); // С параметрами
	Person(const Person&); // Копирования

	// Деструкторы
	~Person();

	// Методы
	// Селекторы
	string get_name();
	int get_age();

	// Модификаторы
	void set_name(string);
	void set_age(int);

	// Перегрузка операции присваивания
	Person& operator =(const Person&);

	// Функция просмотра атрибутов класса с помощью указателя
	void Show();

	// Функция ввода значений атрибутов
	void Input();

	// Сова на глобусе !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void HandleEvent(const TEvent& e);
};

