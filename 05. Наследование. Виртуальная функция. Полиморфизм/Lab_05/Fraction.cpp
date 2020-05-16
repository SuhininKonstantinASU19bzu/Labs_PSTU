#include "Fraction.h"

// Конструктор без параметров
Fraction::Fraction() :Pair() {
	// Атрибут = 0;
}

// Конструктор с параметрами
Fraction::Fraction(int F, int S) : Pair(F, S) {
	// Атрибут = А;
}

// Конструктор копирования
Fraction::Fraction(const Fraction& F) {
	first = F.first;
	second = F.second;
}

// Деструктор
Fraction::~Fraction() {

}

// Перегрузка операции присваивания
Fraction& Fraction::operator =(const Fraction& f) {
	// Проверка на самоприсваивание
	if (&f == this) return *this;
	first = f.first;
	second = f.second;

	return *this;
}

// Операции сравнения
bool Fraction::operator ==(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne == firstTwo) && (secondOne == secondTwo)) return true;

	return false;
}

bool Fraction::operator !=(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne != firstTwo) || (secondOne != secondTwo)) return true;

	return false;
}

bool Fraction::operator >=(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if (((firstOne > firstTwo) || ((firstOne == firstTwo) && (secondOne > secondTwo))) || ((firstOne == firstTwo) && (secondOne == secondTwo))) return true;

	return false;
}

bool Fraction::operator <=(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if (((firstOne < firstTwo) || ((firstOne == firstTwo) && (secondOne < secondTwo))) || ((firstOne == firstTwo) && (secondOne == secondTwo))) return true;

	return false;
}

bool Fraction::operator >(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne > firstTwo) || ((firstOne == firstTwo) && (secondOne > secondTwo))) return true;

	return false;
}

bool Fraction::operator <(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne < firstTwo) || ((firstOne == firstTwo) && (secondOne < secondTwo))) return true;

	return false;
}

// Выделение целой части дроби !!!!
int Fraction::Resolve() {
	int r;

	if (second != 0) {
		r = first / second;
	}

	else {
		cout << endl << "!!! ОШИБКА : знаменатель равен 0 !!!" << endl;
		exit(111);
	}

	return r;
}

// Функция просмотра атрибутов класса с помощью указателя
void Fraction::Show() {
	cout << endl << "Дробь: " << first << "," << second << endl;
}

// Глобальные функции ввода
istream& operator >>(istream& in, Fraction& f) {
	cout << endl << "Введите целую часть: ";
	in >> f.first;
	cout << endl << "Введите дробную часть: ";
	in >> f.second;
	if (f.second < 0) {
		cout << "error";
		exit(130);
	}
	return in;
}

// Глобальные функции вывода
ostream& operator <<(ostream& out, const Fraction& f) {
	out << endl << "Дробь: " << f.first << "," << f.second << endl;

	return out;
}