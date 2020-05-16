#pragma once
#include "Pair.h"

// ����� Fraction ����������� �� ������ Pair
class Fraction :
	public Pair {

	// �������� (����������� �� �������� ������ Pair)
//private:
	// �������;

public:
	// ������������
	Fraction(); // ��� ����������
	Fraction(int, int); // � �����������
	Fraction(const Fraction&); // �����������

	// ����������
	~Fraction();

	// ��������� (����������� �� �������� ������ Pair)
	//int get_first();
	//int get_second();

	// ������������ (����������� �� �������� ������ Pair)
	//void set_first(int);
	//void set_second(int);

	// �������� ������������
	Fraction& operator =(const Fraction&);

	// �������� ���������
	bool operator ==(const Fraction&);
	bool operator !=(const Fraction&);
	bool operator >=(const Fraction&);
	bool operator <=(const Fraction&);
	bool operator >(const Fraction&);
	bool operator <(const Fraction&);

	// ����� ��������� ����� ����� ����� (��������!!!)
	int Resolve();

	void Compare() {}; // ��������� ��� ������� ���������

	void Show(); // ������� ��������� ��������� ������ � ������� ���������

	// �������� �����-������
	friend istream& operator >>(istream& in, Fraction& f);
	friend ostream& operator <<(ostream& out, const Fraction& f);
};