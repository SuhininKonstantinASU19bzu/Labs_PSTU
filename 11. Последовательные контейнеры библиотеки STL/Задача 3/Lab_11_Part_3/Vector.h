#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vector {
private:
	int size;
	vector <T> v; // ��������� ��� �������� ��������� �������

public:
	// ������������
	Vector(); // ��� ����������
	Vector(int n); // ������������

	// �����������
	~Vector();

	// ������
	void Print();
	T average();
	void add_all(T el);
	void add_pos(T el, int pos);
	void add_begin(T el);
	void del_pos(int pos);
	int min();
	int max();
};

// ����������� �������
// ����������� ��� ����������
template <class T>
Vector<T>::Vector() {
	size = 0;
}

// ����������� � �����������
template <class T>
Vector<T>::Vector(int n) {
	T a;

	for (int i = 0; i < n; i++) {
		cin >> a;

		v.push_back(a);
	}

	size = v.size();
}

// ����������
template <class T>
Vector<T>::~Vector() {

}

// ����� �������
template <class T>
void Vector<T>::Print() {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " | ";

	cout << endl;
}

// �������� �������� �� ������� pos
template <class T>
void Vector<T>::del_pos(int pos) {
	v.erase(v.begin() + pos);
}

// ���������� �������� el � ������� pos
template <class T>
void Vector<T>::add_pos(T el, int pos) {
	v.insert(v.begin() + pos - 1, el);
}

// ���������� �������� el � ������ �������
template <class T>
void Vector<T>::add_begin(T el) {
	v.insert(v.begin(), el);
}

//
template <class T>
void Vector<T>::add_all(T el) {
	for (int i = 0; i < v.size(); i++) v[i] = v[i] + el;
}

// ���������� �������� ���������������
template <class T>
T Vector<T>::average() {
	T a = v[0];
	int n = v.size();

	for (int i = 1; i < v.size(); i++) a = a + v[i];

	return a / n;
}

// ����� ������������� ��������
template <class T>
int Vector<T>::max() {
	T m = v[0]; // ������������ �������
	int n = 0; // ����� ������������� ��������

	for (int i = 0; i < v.size(); i++) {
		if (m < v[i]) {
			m = v[i]; // �������� ������������ �������
			n = i; // �������� ����� ������������� ��������
		}
	}

	return n;
}

// ����� ������������ ��������
template <class T>
int Vector<T>::min() {
	T m = v[0]; // ����������� �������
	int n = 0; // ����� ������������ ��������

	for (int i = 0; i < v.size(); i++) {
		if (m > v[i]) {
			m = v[i]; // �������� ����������� �������
			n = i; // �������� ����� ������������ ��������
		}
	}

	return n;
}