#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog :
	public Vector {

	// Атрибуты
protected:
	int EndState;

public:
	// Конструкторы
	Dialog(); // Без параметров

	// Деструкторы
	virtual ~Dialog();

	// Методы
	int Valid(); // Проверка атрибута EndState
	void EndExec(); // Обработка события "Конец работы"
	virtual void GetEvent(TEvent& event); // Получение события
	virtual void HandleEvent(TEvent& event); // Обработчик
	virtual void ClearEvent(TEvent& event); // Очистка событий
	virtual int Execute(); // Главный цикл обработки событий
};