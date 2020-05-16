#pragma once
#include "Person.h"

// Класс Student наследуется от класса Person
class Student :
	public Person {

	// Атрибуты
private:
	float rating; // Рейтинг

public:
	// Конструкторы
	Student(); // Без параметров
	Student(string, int, float); // С параметрами
	Student(const Student&); // Копирования

	// Деструктор
	~Student();

	// Селекторы
	float get_rating();

	// Модификаторы
	void set_rating(float);

	// Операция присваивания
	Student& operator =(const Student&);

	// Функция просмотра атрибутов класса с помощью указателя
	void Show();

	// Функция ввода значений атрибутов
	void Input();
};