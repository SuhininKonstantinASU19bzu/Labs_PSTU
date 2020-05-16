#include <iostream>
#include "ipart.h"

using namespace std;

// Реализация метода для инициализации полей структуры
void ipart::Init(unsigned F, unsigned S) {
	first = F;

	if (S != 0) {
		second = S;
	}

	else {
		cout << endl << "!!! ОШИБКА Инициализации: знаменатель равен 0 !!!" << endl;
		exit(1);
	}
}

// Реализация метода для чтения значений полей структуры
void ipart::Read() {
	cout << endl << "введите значение first: ";
	cin >> first;
	cout << endl << "введите значение second: ";
	cin >> second;
}

// Реализация метода для вывода значений полей структуры
void ipart::Show() {
	cout << endl << "введенное вами значение first равно: " << first;
	cout << endl << "введенное вами значение second равно: " << second;
	cout << endl << endl;
}

// Реализация метода выделения целой части дроби
int ipart::Resolve() {
	int r;

	if (second != 0) {
		r = first / second;
	}

	else {
		cout << endl << "!!! ОШИБКА : знаменатель равен 0 !!!" << endl;
		exit (2);
	}

	return r;
}