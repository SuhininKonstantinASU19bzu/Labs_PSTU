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

// Make (Создание группы заданного размера)
void Vector::Make(int V) {
	if (V == 0) {
		cout << "Недостаточный размер для создания группы" << endl;
		return;
	}
	else if (V >= 1) {
		beg = new Object * [V];
		cur = 0;
		size = V;
		cout << "Создана группа размера: " << size << endl;
	}
	else return;
}

// Добавление объекта на который указывает указатель p в Vector
void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

// Добавление объекта в вектор
void Vector::Add() {
	Object* p;

	if (size == 0) {
		cout << "Нет группы для добавления элемента" << endl;
		return;
	}

	if (cur == size) {
		cout << "Группа заполнена" << endl;
		return;
	}

	cout << "1.Person" << endl;
	cout << "2.Student" << endl;
	cout << "> ";

	int y;

	cin >> y;

	if (y == 1) {
		Person* a = new Person;

		a->Input();

		p = a;

		if (cur < size) {
			beg[cur] = p; // Добавление в вектор
			cur++;
		}
	}
	else if (y == 2) {
		Student* b = new Student;

		b->Input();

		p = b;

		if (cur < size) {
			beg[cur] = p; // Добавление в вектор
			cur++;
		}
	}
	else return;
}

// Получение объекта
void Vector::Get(int G) {
	if (size == 0) {
		cout << "Нет группы для показа элемента" << endl;
		return;
	}

	if (cur == 0) {
		cout << "Группа пуста" << endl;
		return;
	}

	Object** p = beg; // Указатель на указатель типа Object

	int index = G - 1;

	if (index < 0) {
		cout << "Введен не допустимый индекс" << endl;
		return;
	}

	if (G > cur) {
		cout << "Введеное значение превышает допустимое" << endl;
		return;
	}

	for (int i = 0; i < cur; i++) {
		if (i == index) (*p)->Show(); // Вызов метода Show() (Позднее связывание)
		p++;
	}
}

// Просмотр вектора
void Vector::Show() {
	if (size == 0) {
		cout << "Нет группы для показа элементов" << endl;
		return;
	}

	if (cur == 0) {
		cout << "Группа пуста" << endl;
		return;
	}

	Object** p = beg; // Указатель на указатель типа Object

	for (int i = 0; i < cur; i++) {
		(*p)->Show(); // Вызов метода Show() (Позднее связывание)
		p++;
	}
}

// Удаление элементов из вектора без освобождения памяти!!
void Vector::Del() {
	if (size == 0) {
		cout << "Нет группы для удаления элемента" << endl;
		return;
	}

	if (cur == 0) {
		cout << "Группа пуста" << endl;
		return;
	}

	cur--;
}

// Операция получения размера заполненности группы
int Vector::operator ()() {
	return cur;
}

// Обработка события
void Vector::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		Object** p = beg;

		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}