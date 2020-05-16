#include "Vector.h"

// Конструктор без параметров
Vector::Vector() {
	beg = 0;
	size = 0;
	cur = 0;
}

// Конструктор с параметрами
Vector::Vector(int V) {
	beg = new Object * [V];
	cur = 0;
	size = V;
}

// Деструктор
Vector::~Vector() {
	if (beg != 0) delete[] beg;
	beg = 0;
}

// Добавление объекта на который указывает указатель p в Vector
void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

// Глобальные функции вывода
ostream& operator <<(ostream& out, const Vector& v) {
	if (v.size == 0) out << "Массив пуст" << endl;

	Object** p = v.beg; // Указатель на указатель типа Object

	for (int i = 0; i < v.cur; i++) {
		(*p)->Show(); // Вызов метода Show() (Позднее связывание)
		p++; // Передвигаем указатель на следующий объект
	}

	return out;
}