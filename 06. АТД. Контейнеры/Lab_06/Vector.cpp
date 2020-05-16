#include "Vector.h"

// ����������� ��� ����������
Vector::Vector() {

}

// ����������� � �����������
Vector::Vector(int s, int k) {
	size = s;
	data = new int[size];

	for (int i = 0; i < size; i++) data[i] = k;

	beg.elem = &data[0];
	end.elem = &data[size];
}

// ����������� �����������
Vector::Vector(const Vector& v) {
	size = v.size;
	data = new int[size];

	for (int i = 0; i < size; i++) data[i] = v.data[i];

	beg = v.beg;
	end = v.end;
}

// ����������
Vector::~Vector() {
	delete[] data;
	data = 0;
}

// �������� ������������
Vector& Vector::operator =(const Vector& v) {
	// �������� �� ����������������
	if (this == &v) return *this;

	size = v.size;

	// ������� ������ ��� ������� ������
	if (data != 0) delete[] data;

	data = new int[size];

	for (int i = 0; i < size; i++) data[i] = v.data[i];

	beg = v.beg;
	end = v.end;

	return *this;
}

// �������� ������� �� �������
int& Vector::operator [](int index) {
	if (index < size) return data[index];
	else cout << endl << "������! index > size";
}

// �������� ���������� ���������
Vector Vector::operator +(const int k) {
	Vector temp(size);

	for (int i = 0; i < size; ++i) temp.data[i] = data[i] + k;

	return temp;
}

// �������� ��������� ����� �������
int Vector::operator ()() {
	return size;
}

// ���������� �������� �����-�����
istream& operator >>(istream& in, Vector& v) {
	for (int i = 0; i < v.size; ++i) in >> v.data[i];

	return in;
}

ostream& operator <<(ostream& out, const Vector& v) {
	for (int i = 0; i < v.size; ++i) out << v.data[i] << " ";

	return out;
}