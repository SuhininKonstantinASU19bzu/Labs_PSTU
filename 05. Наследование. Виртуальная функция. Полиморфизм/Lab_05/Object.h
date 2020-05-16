#pragma once

class Object {
public:
	// Конструкторы
	Object(); // Без параметров

	// Деструкторы
	~Object();

	// Методы
	virtual void Show() = 0; // Чисто виртуальная функция
};