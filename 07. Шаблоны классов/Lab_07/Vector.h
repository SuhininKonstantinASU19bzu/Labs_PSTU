#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector {
private:
	int size;
	T* data;
public:
	// Конструкторы
	Vector(); // Без параметров
	Vector(int s, T k); // С параметрами (Выделяет память под s элементов и заполняет их значением k)
	Vector(const Vector<T>& v); // Копирования

	// Деструкторы
	~Vector();

	// Оператор присваивания
	Vector& operator =(const Vector<T>& v);

	// Операция доступа по индексу
	T& operator [](int index);

	// Операция добавления константы
	Vector operator +(const T k);

	// Операция возвращения длины вектора
	int operator ()();

	// Перегруженые операции ввода-вывода
	// <> - указывает на то, что функция является шаблоном
	friend istream& operator >> <>(istream& in, Vector<T>& v);
	friend ostream& operator << <>(ostream& out, const Vector<T>& v);
};

// Определение функций
// Конструктор без параметров
template <class T>
Vector<T>::Vector() {

}

// Конструктор с параметрами
template <class T>
Vector<T>::Vector(int s, T k) {
	size = s;
	data = new T[size];

	for (int i = 0; i < size; i++) data[i] = k;
}

// Конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& v) {
	size = v.size;
	data = new T[size];

	for (int i = 0; i < size; i++) data[i] = v.data[i];
}

// Деструктор
template <class T>
Vector<T>::~Vector() {
	delete[] data;
	data = 0;
}

// Операция присваивания
template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& v) {
	// Провекра на самоприсваивание
	if (this == &v) return *this;

	size = v.size;

	// Очистка памяти при наличии данных
	if (data != 0) delete[] data;

	data = new T[size];

	for (int i = 0; i < size; i++) data[i] = v.data[i];

	return *this;
}

// Операция доступа по индексу
template <class T>
T& Vector<T>::operator [](int index) {
	if (index < size) return data[index];
	else cout << endl << "Ошибка! index > size";
}

// Операция добавления константы того же типа что и вектор
template <class T>
Vector<T> Vector<T>::operator +(const T k) {
	Vector<T> temp(size,k);

	for (int i = 0; i < size; i++) temp.data[i] = data[i] + k;

	return temp;
}

// Операция получения длины вектора
template <class T>
int Vector<T>::operator ()() {
	return size;
}

// Глобальные операции ввода-выода
template <class T>
istream& operator >>(istream& in, Vector<T>& v) {
	for (int i = 0; i < v.size; i++) in >> v.data[i];

	return in;
}

template <class T>
ostream& operator <<(ostream& out, const Vector<T>& v) {
	for (int i = 0; i < v.size; i++) out << v.data[i] << " ";

	return out;
}