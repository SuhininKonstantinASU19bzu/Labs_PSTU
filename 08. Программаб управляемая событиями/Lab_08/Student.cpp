#include "Student.h"

// ����������� ��� ����������
Student::Student() :Person() {
	rating = 0;
}

// ����������� � �����������
Student::Student(string N, int A, float R) : Person(N, A) {
	rating = R;
}

// ����������� �����������
Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	rating = S.rating;
}

// ����������
Student::~Student() {

}

// ���������
float Student::get_rating() {
	return rating;
}

// ������������
void Student::set_rating(float R) {
	rating = R;
}

// ���������� �������� ������������
Student& Student::operator =(const Student& s) {
	// �������� �� ����������������
	if (&s == this) return *this;

	name = s.name;
	age = s.age;
	rating = s.rating;

	return *this;
}

// ������� ��������� ��������� ������ � ������� ���������
void Student::Show() {
	cout << endl << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "�������: " << rating << endl;
}

// ������� ����� �������� ���������
void Student::Input() {
	cout << endl << "������� ���: ";
	cin >> name;
	cout << endl << "������� �������: ";
	cin >> age;
	cout << endl << "������� �������: ";
	cin >> rating;
}