#include <string>
#include <iostream>
#include "student.h"

using namespace std;

// ����������� ��� ����������
Student::Student() {
	fullname = "";
	group = "";
	averagemark = 0;

	cout << "����������� ��� ���������� ��� �������: " << this << endl;
}

// ����������� � �����������
Student::Student(string F, string G, float A) {
	fullname = F;
	group = G;
	averagemark = A;

	cout << "����������� � ����������� ��� �������: " << this << endl;
}

// ����������� �����������
Student::Student(const Student& T) {
	fullname = T.fullname;
	group = T.group;
	averagemark = T.averagemark;

	cout << "����������� ����������� ��� �������: " << this << endl;
}

// ����������
Student::~Student() {
	cout << "���������� ��� �������: " << this << endl;
}

// ���������
string Student::get_fullname() {
	return fullname;
}

string Student::get_group() {
	return group;
}

float Student::get_averagemark() {
	return averagemark;
}

// ������������
void Student::set_fullname(string F) {
	fullname = F;
}

void Student::set_group(string G) {
	group = G;
}

void Student::set_averagemark(float A) {
	averagemark = A;
}

// ����� ��������� ���������
void Student::Show() {
	cout << endl << "���: " << fullname << endl;
	cout << "������: " << group << endl;
	cout << "������� ����: " << averagemark << endl << endl;
}