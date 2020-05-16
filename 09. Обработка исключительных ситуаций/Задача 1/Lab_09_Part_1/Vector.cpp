#include "Vector.h"

// Конструктор без параметров
Vector::Vector() {
	size = 0;
	beg = 0;
}

// Конструктор с параметрами
Vector::Vector(int s) {
	if (s > MAX_SIZE) throw 11; // Если размер больше максимального, генерируется исключение.

	size = s;
	beg = new int[s];

	for (int i = 0; i < size; i++) beg[i] = 0;
}

// Конструктор с параметрами
Vector::Vector(int s, int* mas) {
	if (s > MAX_SIZE) throw 21; // Если размер больше максимального, генерируется исключение. 

	size = s;
	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = mas[i];
}

// Конструктор копирования
Vector::Vector(const Vector& v) {
	size = v.size;
	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}

// Деструктор
Vector::~Vector() {
	if (beg != 0) delete[] beg;
}

// Оператор присваивания
const Vector& Vector::operator =(const Vector& v) {
	if (this == &v) return *this;
	if (beg != 0) delete[] beg;

	size = v.size;
	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = v.beg[i];

	return *this;
}

// Оператор доступа по индексу
int Vector::operator [](int i) {
	if (i < 0) throw 57; // Если индекс отрицательный, то генерируется исключение
	if (i >= size) throw 58; // Если индекс больше размера вектора, то генерируется исключение

	return beg[i];
}

// Оператор получения длины вектора
int Vector::operator ()() {
	return size;
}

// Оператор добавления элемента в вектор
Vector Vector::Add(int d) {
	if (size + 1 == MAX_SIZE) throw 70; // Если при добавлении элемента размер вектора станет больше максимального, генерируется исключение

	Vector temp(size + 1, beg);

	temp.beg[size] = d;

	return temp;
}

// Операция добавления константы
Vector Vector::operator +(const int k) {
	Vector temp(size);

	for (int i = 0; i < size; i++) temp.beg[i] = beg[i] + k;

	return temp;
}

// Оператор удаления n элементов
Vector Vector::operator -(int n) {
	if (size == 0) throw 90; // Если вектор пустой то генерируется исключение
	if (size == 1) { // Если в векторе один элемент
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}

	if (n > size) throw 98;

	for (int z = 0; z < n; z++) {

		Vector temp(size, beg);

		delete[] beg;

		size--;

		beg = new int[size];

		for (int i = 0; i < size; i++) beg[i] = temp.beg[i];

	}

	return *this;
}

// Оператор удаления элемента
Vector Vector::operator --() {
	if (size == 0) throw 119; // Если вектор пустой то генерируется исключение
	if (size == 1) { // Если в векторе один элемент
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}

	Vector temp(size, beg);

	delete[] beg;

	size--;

	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = temp.beg[i];

	return *this;
}

// Глобальная функция ввода
istream& operator >>(istream& in, Vector& v) {
	for (int i = 0; i < v.size; i++) {
		cout << "> ";
		in >> v.beg[i];
	}

	return in;
}

// Глобальная функция вывода
ostream& operator <<(ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "Вектор пуст" << endl;
	}
	else {
		for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
		out << endl;
	}

	return out;
}