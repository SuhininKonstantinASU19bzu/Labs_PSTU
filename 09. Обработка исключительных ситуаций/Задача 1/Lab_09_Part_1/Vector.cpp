#include "Vector.h"

// ����������� ��� ����������
Vector::Vector() {
	size = 0;
	beg = 0;
}

// ����������� � �����������
Vector::Vector(int s) {
	if (s > MAX_SIZE) throw 11; // ���� ������ ������ �������������, ������������ ����������.

	size = s;
	beg = new int[s];

	for (int i = 0; i < size; i++) beg[i] = 0;
}

// ����������� � �����������
Vector::Vector(int s, int* mas) {
	if (s > MAX_SIZE) throw 21; // ���� ������ ������ �������������, ������������ ����������. 

	size = s;
	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = mas[i];
}

// ����������� �����������
Vector::Vector(const Vector& v) {
	size = v.size;
	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}

// ����������
Vector::~Vector() {
	if (beg != 0) delete[] beg;
}

// �������� ������������
const Vector& Vector::operator =(const Vector& v) {
	if (this == &v) return *this;
	if (beg != 0) delete[] beg;

	size = v.size;
	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = v.beg[i];

	return *this;
}

// �������� ������� �� �������
int Vector::operator [](int i) {
	if (i < 0) throw 57; // ���� ������ �������������, �� ������������ ����������
	if (i >= size) throw 58; // ���� ������ ������ ������� �������, �� ������������ ����������

	return beg[i];
}

// �������� ��������� ����� �������
int Vector::operator ()() {
	return size;
}

// �������� ���������� �������� � ������
Vector Vector::Add(int d) {
	if (size + 1 == MAX_SIZE) throw 70; // ���� ��� ���������� �������� ������ ������� ������ ������ �������������, ������������ ����������

	Vector temp(size + 1, beg);

	temp.beg[size] = d;

	return temp;
}

// �������� ���������� ���������
Vector Vector::operator +(const int k) {
	Vector temp(size);

	for (int i = 0; i < size; i++) temp.beg[i] = beg[i] + k;

	return temp;
}

// �������� �������� n ���������
Vector Vector::operator -(int n) {
	if (size == 0) throw 90; // ���� ������ ������ �� ������������ ����������
	if (size == 1) { // ���� � ������� ���� �������
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}

	if (n > size) throw 98;

	for (int z = 0; z < n; z++) {

		Vector temp(size, beg);

		delete[] beg;

		size--;

		beg = new int[size];

		for (int i = 0; i < size; i++) beg[i] = temp.beg[i];

	}

	return *this;
}

// �������� �������� ��������
Vector Vector::operator --() {
	if (size == 0) throw 119; // ���� ������ ������ �� ������������ ����������
	if (size == 1) { // ���� � ������� ���� �������
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}

	Vector temp(size, beg);

	delete[] beg;

	size--;

	beg = new int[size];

	for (int i = 0; i < size; i++) beg[i] = temp.beg[i];

	return *this;
}

// ���������� ������� �����
istream& operator >>(istream& in, Vector& v) {
	for (int i = 0; i < v.size; i++) {
		cout << "> ";
		in >> v.beg[i];
	}

	return in;
}

// ���������� ������� ������
ostream& operator <<(ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "������ ����" << endl;
	}
	else {
		for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
		out << endl;
	}

	return out;
}