#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Pair :
	public Object {
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

	// ������
	void Compare() {}; // ��������� ��� ������� ���������

	void Show(); // ������� ��������� ��������� ������ � ������� ���������

	// ���������� ���������-������� �����-������
	friend istream& operator >>(istream& in, Pair& p);
	friend ostream& operator <<(ostream& out, const Pair& p);
};