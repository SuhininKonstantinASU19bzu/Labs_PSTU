#pragma once
#include <iostream>

using namespace std;

class Pair {
	// ��������
protected:
	int first;
	int second;

public:
	// ������������
	Pair(); // ��� ����������
	Pair(int, int); // � �����������
	Pair(const Pair&); // �����������

	// ����������
	virtual ~Pair();

	// ���������
	int get_first();
	int get_second();

	// ������������
	void set_first(int);
	void set_second(int);

	// ���������� �������� ������������
	Pair& operator =(const Pair&);

	// �������� ���������
	bool operator >(const Pair&);

	// ���������� ���������-������� �����-������
	friend istream& operator >>(istream& in, Pair& p);
	friend ostream& operator <<(ostream& out, const Pair& p);
};


