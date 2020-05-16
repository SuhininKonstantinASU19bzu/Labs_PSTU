#include "Vector.h"

// ����������� ��� ����������
Vector::Vector() {
	beg = 0;
	size = 0;
	cur = 0;
}

// ����������� � �����������
Vector::Vector(int V) {
	beg = new Object * [V];
	cur = 0;
	size = V;
}

// ����������
Vector::~Vector() {
	if (beg != 0) delete[] beg;
	beg = 0;
}

// Make (�������� ������ ��������� �������)
void Vector::Make(int V) {
	if (V == 0) {
		cout << "������������� ������ ��� �������� ������" << endl;
		return;
	}
	else if (V >= 1) {
		beg = new Object * [V];
		cur = 0;
		size = V;
		cout << "������� ������ �������: " << size << endl;
	}
	else return;
}

// ���������� ������� �� ������� ��������� ��������� p � Vector
void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

// ���������� ������� � ������
void Vector::Add() {
	Object* p;

	if (size == 0) {
		cout << "��� ������ ��� ���������� ��������" << endl;
		return;
	}

	if (cur == size) {
		cout << "������ ���������" << endl;
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
			beg[cur] = p; // ���������� � ������
			cur++;
		}
	}
	else if (y == 2) {
		Student* b = new Student;

		b->Input();

		p = b;

		if (cur < size) {
			beg[cur] = p; // ���������� � ������
			cur++;
		}
	}
	else return;
}

// ��������� �������
void Vector::Get(int G) {
	if (size == 0) {
		cout << "��� ������ ��� ������ ��������" << endl;
		return;
	}

	if (cur == 0) {
		cout << "������ �����" << endl;
		return;
	}

	Object** p = beg; // ��������� �� ��������� ���� Object

	int index = G - 1;

	if (index < 0) {
		cout << "������ �� ���������� ������" << endl;
		return;
	}

	if (G > cur) {
		cout << "�������� �������� ��������� ����������" << endl;
		return;
	}

	for (int i = 0; i < cur; i++) {
		if (i == index) (*p)->Show(); // ����� ������ Show() (������� ����������)
		p++;
	}
}

// �������� �������
void Vector::Show() {
	if (size == 0) {
		cout << "��� ������ ��� ������ ���������" << endl;
		return;
	}

	if (cur == 0) {
		cout << "������ �����" << endl;
		return;
	}

	Object** p = beg; // ��������� �� ��������� ���� Object

	for (int i = 0; i < cur; i++) {
		(*p)->Show(); // ����� ������ Show() (������� ����������)
		p++;
	}
}

// �������� ��������� �� ������� ��� ������������ ������!!
void Vector::Del() {
	if (size == 0) {
		cout << "��� ������ ��� �������� ��������" << endl;
		return;
	}

	if (cur == 0) {
		cout << "������ �����" << endl;
		return;
	}

	cur--;
}

// �������� ��������� ������� ������������� ������
int Vector::operator ()() {
	return cur;
}

// ��������� �������
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