#pragma once
#include <string>

using namespace std;

class Student {
	// Атрибуты
	string fullname;
	string group;
	float averagemark;

public:
	Student(); // Конструктор без параметров
	Student(string, string, float); // Конструктор с параметрами
	Student(const Student&); // Конструктор копирования
	~Student(); // Деструктор

	// Селекторы
	string get_fullname();
	string get_group();
	float get_averagemark();

	// Модификаторы
	void set_fullname(string);
	void set_group(string);
	void set_averagemark(float);

	// Просмотр атрибутов
	void Show();
};
