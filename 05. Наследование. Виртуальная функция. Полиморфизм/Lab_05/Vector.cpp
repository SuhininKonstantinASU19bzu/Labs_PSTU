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

// ���������� ������� �� ������� ��������� ��������� p � Vector
void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

// ���������� ������� ������
ostream& operator <<(ostream& out, const Vector& v) {
	if (v.size == 0) out << "������ ����" << endl;

	Object** p = v.beg; // ��������� �� ��������� ���� Object

	for (int i = 0; i < v.cur; i++) {
		(*p)->Show(); // ����� ������ Show() (������� ����������)
		p++; // ����������� ��������� �� ��������� ������
	}

	return out;
}