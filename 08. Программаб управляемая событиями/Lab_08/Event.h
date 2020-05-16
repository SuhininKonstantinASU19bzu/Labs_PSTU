#pragma once

const int evNothing = 0; // Пустое событие
const int evMessage = 100; // Не пустое событие
const int cmAdd = 1; // Добавление объекта в группу
const int cmDel = 2; // Удаление объекта из группы
const int cmGet = 3; // Вывод атрибутов всех объектов
const int cmShow = 4; // Вывод всей группы
const int cmGett = 5; // Test
const int cmMake = 6; // Создание группы
const int cmQuit = 101; // Выход

// Класс событие
struct TEvent {
	int what; // Тип события
	union {
		int command; // Код комманды
		struct {
			int message;
			int a; // Параметр комманды
		};
	};
};