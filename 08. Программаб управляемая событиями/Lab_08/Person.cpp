#include "Person.h"

// Конструктор без параметров
Person::Person() {
	name = "";
	age = 0;
}

// Конструктор с параметрами
Person::Person(string N, int A) {
	name = N;
	age = A;
}

// Конструктор копирования
Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

// Деструктор
Person::~Person() {

}

// Селекторы
string Person::get_name() {
	return name;
}

int Person::get_age() {
	return age;
}

// Модификаторы
void Person::set_name(string N) {
	name = N;
}

void Person::set_age(int A) {
	age = A;
}

// Перегрузка операции присваивания
Person& Person::operator =(const Person& p) {
	// Проверка на самоприсваивание
	if (&p == this) return *this;

	name = p.name;
	age = p.age;

	return *this;
}

// Функция просмотра атрибутов класса с помощью указателя
void Person::Show() {
	cout << endl << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
}

// Функция ввода значений атрибутов
void Person::Input() {
	cout << endl << "Введите имя: ";
	cin >> name;
	cout << endl << "Введите возраст: ";
	cin >> age;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Person::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) { // Сообщение - событие
		switch (e.command) {
		case cmGet: cout << "Имя: " << get_name() << endl; break;
		}
	}
}