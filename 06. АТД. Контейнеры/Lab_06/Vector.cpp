#include "Vector.h"

// Конструктор без параметров
Vector::Vector() {

}

// Конструктор с параметрами
Vector::Vector(int s, int k) {
	size = s;
	data = new int[size];

	for (int i = 0; i < size; i++) data[i] = k;

	beg.elem = &data[0];
	end.elem = &data[size];
}

// Конструктор копирования
Vector::Vector(const Vector& v) {
	size = v.size;
	data = new int[size];

	for (int i = 0; i < size; i++) data[i] = v.data[i];

	beg = v.beg;
	end = v.end;
}

// Деструктор
Vector::~Vector() {
	delete[] data;
	data = 0;
}

// Операция присваивания
Vector& Vector::operator =(const Vector& v) {
	// Провекра на самоприсваивание
	if (this == &v) return *this;

	size = v.size;

	// Очистка памяти при наличии данных
	if (data != 0) delete[] data;

	data = new int[size];

	for (int i = 0; i < size; i++) data[i] = v.data[i];

	beg = v.beg;
	end = v.end;

	return *this;
}

// Операция доступа по индексу
int& Vector::operator [](int index) {
	if (index < size) return data[index];
	else cout << endl << "Ошибка! index > size";
}

// Операция добавления константы
Vector Vector::operator +(const int k) {
	Vector temp(size);

	for (int i = 0; i < size; ++i) temp.data[i] = data[i] + k;

	return temp;
}

// Операция получения длины вектора
int Vector::operator ()() {
	return size;
}

// Глобальные операции ввода-выода
istream& operator >>(istream& in, Vector& v) {
	for (int i = 0; i < v.size; ++i) in >> v.data[i];

	return in;
}

ostream& operator <<(ostream& out, const Vector& v) {
	for (int i = 0; i < v.size; ++i) out << v.data[i] << " ";

	return out;
}