#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vector {
private:
	int size;
	vector <T> v; // Контейнер для хранения элементов вектора

public:
	// Конструкторы
	Vector(); // Без параметров
	Vector(int n); // Спараметрами

	// Деструкторы
	~Vector();

	// Методы
	void Print();
	T average();
	void add_all(T el);
	void add_pos(T el, int pos);
	void add_begin(T el);
	void del_pos(int pos);
	int min();
	int max();
};

// Определение функций
// Конструктор без параметров
template <class T>
Vector<T>::Vector() {
	size = 0;
}

// Конструктор с параметрами
template <class T>
Vector<T>::Vector(int n) {
	T a;

	for (int i = 0; i < n; i++) {
		cin >> a;

		v.push_back(a);
	}

	size = v.size();
}

// Деструктор
template <class T>
Vector<T>::~Vector() {

}

// Вывод вектора
template <class T>
void Vector<T>::Print() {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " | ";

	cout << endl;
}

// Удаление элемента из позиции pos
template <class T>
void Vector<T>::del_pos(int pos) {
	v.erase(v.begin() + pos);
}

// Добавление элемента el в позицию pos
template <class T>
void Vector<T>::add_pos(T el, int pos) {
	v.insert(v.begin() + pos - 1, el);
}

// Добавление элемента el в начало вектора
template <class T>
void Vector<T>::add_begin(T el) {
	v.insert(v.begin(), el);
}

//
template <class T>
void Vector<T>::add_all(T el) {
	for (int i = 0; i < v.size(); i++) v[i] = v[i] + el;
}

// Вычисление среднего арифметического
template <class T>
T Vector<T>::average() {
	T a = v[0];
	int n = v.size();

	for (int i = 1; i < v.size(); i++) a = a + v[i];

	return a / n;
}

// Поиск максимального элемента
template <class T>
int Vector<T>::max() {
	T m = v[0]; // Максимальный элемент
	int n = 0; // Номер максимального элемента

	for (int i = 0; i < v.size(); i++) {
		if (m < v[i]) {
			m = v[i]; // Найденый максимальный элемент
			n = i; // Найденый номер максимального элемента
		}
	}

	return n;
}

// Поиск минимального элемента
template <class T>
int Vector<T>::min() {
	T m = v[0]; // Минимальный элемент
	int n = 0; // Номер минимального элемента

	for (int i = 0; i < v.size(); i++) {
		if (m > v[i]) {
			m = v[i]; // Найденый минимальный элемент
			n = i; // Найденый номер минимального элемента
		}
	}

	return n;
}