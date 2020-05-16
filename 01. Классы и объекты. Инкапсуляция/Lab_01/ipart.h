#pragma once

struct ipart {
	unsigned first;
	unsigned second;
	void Init(unsigned, unsigned); // Метод для инициализации полей
	void Read(); // Метод для чтения значений полей
	void Show(); // Метод для вывода значений полей
	int Resolve(); // Метод выделения целой части дроби
};