#pragma once
#include "Event.h"

class Object {
public:
	// Конструкторы
	Object(); // Без параметров

	// Деструкторы
	virtual ~Object();

	// Методы
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
};