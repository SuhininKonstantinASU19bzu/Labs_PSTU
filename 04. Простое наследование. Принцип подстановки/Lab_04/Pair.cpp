#include "Pair.h"

// Конструктор без параметров
Pair::Pair() {
	first = 0;
	second = 0;
}

// Конструктор с параметрами
Pair::Pair(int F, int S) {
	first = F;
	second = S;
}

// Конструктор копирования
Pair::Pair(const Pair& pair) {
	first = pair.first;
	second = pair.second;
}

// Деструктор
Pair::~Pair() {

}

// Селекторы
int Pair::get_first() {
	return first;
}

int Pair::get_second() {
	return second;
}

// Модификаторы
void Pair::set_first(int F) {
	first = F;
}

void Pair::set_second(int S) {
	second = S;
}

// Перегрузка операции присваивания
Pair& Pair::operator =(const Pair& p) {
	// Проверка на самоприсваивание
	if (&p == this) return *this;
	first = p.first;
	second = p.second;

	return *this;
}

// Операции сравнения

bool Pair::operator >(const Pair& p) {
	int temp1 = first;
	int temp2 = second;
	int temp3 = p.first;
	int temp4 = p.second;

	if ((temp1 > temp3) || ((temp1 == temp3) && (temp2 > temp4))) return true;

	return false;
}

// Глобальные функции ввода
istream& operator >>(istream& in, Pair& p) {
	cout << endl << "Введите первое число: ";
	in >> p.first;
	cout << endl << "Введите второе число: ";
	in >> p.second;

	return in;
}

// Глобальные функции вывода
ostream& operator <<(ostream& out, const Pair& p) {
	out << endl << "Пара: (" << p.first << "," << p.second << ")" << endl;

	return out;
}