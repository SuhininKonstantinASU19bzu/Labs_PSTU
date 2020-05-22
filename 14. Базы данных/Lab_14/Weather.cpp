#include "Weather.h"

using namespace std;

// Перегрузка операции присваивания
Weather& Weather::operator =(const Weather& t) {
	// Проверка на самоприсваивание
	if (&t == this) return *this;

	dayW = t.dayW;
	tempW = t.tempW;
	del = t.del;

	return *this;
}

// Перегрузка префиксной операции инкремент
Weather& Weather::operator ++() {
	tempW++;

	return *this;
}

// Перегрузка бинарной операции сложения
Weather Weather::operator +(const Weather& t) {
	Weather p;
	
	if (!t.del) p.tempW = tempW + t.tempW;
	else p.tempW = tempW;

	return p;
}

//
Weather Weather::operator +(const int& i) {
	Weather p;

	p.tempW = tempW + i;

	return p;
}

//
Weather Weather::operator /(const Weather& t) {
	Weather p;

	p.tempW = tempW / t.tempW;

	return p;
}

//
Weather Weather::operator /(const int& i) {
	Weather p;

	p.tempW = tempW / i;

	return p;
}

// Перегрузка бинарной операции сравнения
bool Weather::operator ==(const Weather& t) {
	if (tempW == t.tempW && !del && !t.del) return true;

	return false;
}

bool Weather::operator !=(const Weather& t) {
	if (tempW != t.tempW && !del && !t.del) return true;

	return false;
}

//
bool Weather::operator >(const Weather& t) {
	if (tempW > t.tempW && !del && !t.del) return true;

	return false;
}

bool Weather::operator >(const int& i) {
	if (tempW > i) return true;

	return false;
}

//
bool Weather::operator <(const Weather& t) {
	if (tempW < t.tempW && !del && !t.del) return true;

	return false;
}

bool Weather::operator <(const int& i) {
	if (tempW < i) return true;

	return false;
}

// Перегрузка глобальной функции-операции ввода
istream& operator >>(istream& in, Weather& t) {
	cout << "Введите дату: ";
	in >> t.dayW;
	cout << "Введите температуру: ";
	in >> t.tempW;

	return in;
}

// Перегрузка глобальной функции-операции вывода
ostream& operator <<(ostream& out, const Weather& t) {
	if (!t.del) out << "| " << t.dayW << setw(11) << " : " << setw(11) << t.tempW << " |" << endl;

	return out;
}

// Файловый ввод
fstream& operator >>(fstream& fin, Weather& t) {
	fin >> t.dayW;
	fin >> t.tempW;
	fin >> t.del;
	
	return fin;
}

// Файловый вывод
fstream& operator <<(std::fstream& fout, const Weather& t) {
	fout << t.dayW << endl;
	fout << t.tempW << endl;
	fout << t.del << endl;
	
	return fout;
}