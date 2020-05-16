#include "Person.h"

// ����������� ��� ����������
Person::Person() {
	name = "";
	age = 0;
}

// ����������� � �����������
Person::Person(string N, int A) {
	name = N;
	age = A;
}

// ����������� �����������
Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

// ����������
Person::~Person() {

}

// ���������
string Person::get_name() {
	return name;
}

int Person::get_age() {
	return age;
}

// ������������
void Person::set_name(string N) {
	name = N;
}

void Person::set_age(int A) {
	age = A;
}

// ���������� �������� ������������
Person& Person::operator =(const Person& p) {
	// �������� �� ����������������
	if (&p == this) return *this;

	name = p.name;
	age = p.age;

	return *this;
}

// ������� ��������� ��������� ������ � ������� ���������
void Person::Show() {
	cout << endl << "���: " << name << endl;
	cout << "�������: " << age << endl;
}

// ������� ����� �������� ���������
void Person::Input() {
	cout << endl << "������� ���: ";
	cin >> name;
	cout << endl << "������� �������: ";
	cin >> age;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Person::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) { // ��������� - �������
		switch (e.command) {
		case cmGet: cout << "���: " << get_name() << endl; break;
		}
	}
}