#include "Student.h"

// Конструктор без параметров
Student::Student() :Person() {
	rating = 0;
}

// Конструктор с параметрами
Student::Student(string N, int A, float R) : Person(N, A) {
	rating = R;
}

// Конструктор копирования
Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	rating = S.rating;
}

// Деструктор
Student::~Student() {

}

// Селекторы
float Student::get_rating() {
	return rating;
}

// Модификаторы
void Student::set_rating(float R) {
	rating = R;
}

// Перегрузка операции присваивания
Student& Student::operator =(const Student& s) {
	// Проверка на самоприсваивание
	if (&s == this) return *this;

	name = s.name;
	age = s.age;
	rating = s.rating;

	return *this;
}

// Функция просмотра атрибутов класса с помощью указателя
void Student::Show() {
	cout << endl << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Рейтинг: " << rating << endl;
}

// Функция ввода значений атрибутов
void Student::Input() {
	cout << endl << "Введите имя: ";
	cin >> name;
	cout << endl << "Введите возраст: ";
	cin >> age;
	cout << endl << "Введите рейтинг: ";
	cin >> rating;
}