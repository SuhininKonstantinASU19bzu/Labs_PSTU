#pragma once
#include <iostream>
#include <map>

using namespace std;

template <class T>
class Vector {
private:
	int size;
	multimap <int, T> map; // ��������� ��� �������� ��������� �������

public:
	// ������������
	Vector(); // ��� ����������
	Vector(int n); // � �����������

	// �����������
	~Vector();

	// ������
	void Print();
	T average();
	void add_all(T el);
	void add_pos(T el, int pos);
	void add_end(T el);
	void add_begin(T el);
	void add_multibeg(T el);
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

		map.insert(make_pair(i, a));
	}

	size = map.size();
}

// ����������
template <class T>
Vector<T>::~Vector() {

}

// ����� �������
template <class T>
void Vector<T>::Print() {
	typename multimap<int,T>::iterator it;

	for (it = map.begin(); it != map.end(); it++) {
		cout << (*it).first << " | " << (*it).second << " | ";
	}

	cout << endl;
}

// �������� �������� �� ������� pos
template <class T>
void Vector<T>::del_pos(int pos) {
	map.erase(pos);
}

// ���������� �������� el � ������� pos
template <class T>
void Vector<T>::add_pos(T el, int pos) {
	map.emplace(pos, el);
}

// ���������� �������� � �����
template <class T>
void Vector<T>::add_end(T el) {
	typename multimap<int, T>::iterator it;

	it = map.end();

	--it;

	map.insert(make_pair((*it).first + 1, el));
}

// ���������� �������� el � ������
template <class T>
void Vector<T>::add_begin(T el) {
	multimap<int,T> temp;
	typename multimap<int, T>::iterator it;
	typename multimap<int, T>::iterator tt;

	temp.emplace(0, el);

	for (it = map.begin(); it != map.end(); it++) {
		tt = temp.end();

		--tt;

		temp.insert(make_pair((*tt).first + 1, (*it).second));
	}

	map = temp;
}

template <class T>
void Vector<T>::add_multibeg(T el) {
	map.emplace(0, el);
}

// ���������� el �� ���� ���������
template <class T>
void Vector<T>::add_all(T el) {
	typename multimap<int, T>::iterator it;

	for (it = map.begin(); it != map.end(); it++) {
		(*it).second = (*it).second + el;
	}
}

// ���������� �������� ���������������
template <class T>
T Vector<T>::average() {
	typename multimap<int, T>::iterator it;
	T a;
	int n = map.size();

	for (it = map.begin(); it != map.end(); it++) {
		a = a + (*it).second;
	}

	return a / n;
}

// ����� ������������� ��������
template <class T>
int Vector<T>::max() {
	typename multimap<int, T>::iterator it;
	T max;
	int key;

	for (it = map.begin(); it != map.end(); it++) {
		if (max < (*it).second) {
			max = (*it).second;
			key = (*it).first;
		}
	}

	return key;
}

// ����� ������������ ��������
template <class T>
int Vector<T>::min() {
	typename multimap<int, T>::iterator it = map.begin();
	T min = (*it).second; // �������� ������� ��������
	int key;

	for (it = map.begin(); it != map.end(); it++) {
		if (min > (*it).second) {
			min = (*it).second;
			key = (*it).first;
		}
	}

	return key;
}