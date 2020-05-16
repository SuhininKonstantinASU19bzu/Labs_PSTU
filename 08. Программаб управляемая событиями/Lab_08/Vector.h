#pragma once
#include <iostream>
#include <string>
#include "Object.h"
#include "Person.h"
#include "Student.h"

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
	void Make(int);
	void Add(Object*); // Добавление элемента в вектор по указателю
	void Add(); // Добавление элемента в вектор
	void Get(int); // Получение элемента
	void Show(); // Вывод элементов
	void Del(); // Удаление элементов
	
	// Операция возвращения длины вектора
	int operator ()();

	//
	void HandleEvent(const TEvent& e);
};

