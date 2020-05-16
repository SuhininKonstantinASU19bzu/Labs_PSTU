#include <iostream>
#include "Time.h"

using namespace std;

// Перегрузка операции присваивания
Time& Time::operator =(const Time& t) {
	// Проверка на самоприсваивание
	if (&t == this) return *this;

	min = t.min;
	sec = t.sec;

	return *this;
}

// Перегрузка префиксной операции инкремент
Time& Time::operator ++() {
	int temp = min * 60 + sec;

	temp++;

	min = temp / 60;
	sec = temp % 60;

	return *this;
}

// Перегрузка постфиксной операции инкремент
Time Time::operator ++(int) {
	int temp = min * 60 + sec;

	temp++;

	Time t(min, sec);

	min = temp / 60;
	sec = temp % 60;

	return t;
}

// Перегрузка бинарной операции сложения
Time Time::operator +(const Time& t) {
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;

	Time p;

	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;

	return p;
}

// Перегрузка бинарной операции сравнения
bool Time::operator ==(const Time& t) {
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;

	if (temp1 == temp2) return true;

	return false;
}

// Перегрузка глобальной функции-операции ввода
istream& operator >>(istream& in, Time& t) {
	cout << "Введите минуты: ";
	in >> t.min;
	cout << "Введите секунды: ";
	in >> t.sec;

	return in;
}

// Перегрузка глобальной функции-операции вывода
ostream& operator <<(ostream& out, const Time& t) {
	return (out << t.min << " : " << t.sec);
}