#include <iostream>
#include "Time.h"

using namespace std;

// ������������
Time::Time() {
	min = 0;
	sec = 0;
}

Time::Time(int m, int s) {
	min = m;
	sec = s;
}

Time::Time(const Time& t) {
	min = t.min;
	sec = t.sec;
}

// �����������
Time::~Time() {

}

// ���������
int Time::get_min() {
	return min;
}

int Time::get_sec() {
	return sec;
}

// ������������
void Time::set_min(int m) {
	min = m;
}

void Time::set_sec(int s) {
	sec = s;
}

// ���������� �������� ������������
Time& Time::operator =(const Time& t) {
	// �������� �� ����������������
	if (&t == this) return *this;

	min = t.min;
	sec = t.sec;

	return *this;
}

// ���������� ���������� �������� ���������
Time& Time::operator ++() {
	int temp = min * 60 + sec;

	temp++;

	min = temp / 60;
	sec = temp % 60;

	return *this;
}

// ���������� ����������� �������� ���������
Time Time::operator ++(int) {
	int temp = min * 60 + sec;

	temp++;

	Time t(min, sec);

	min = temp / 60;
	sec = temp % 60;

	return t;
}

// ���������� �������� �������� ��������
Time Time::operator +(const Time& t) {
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;

	Time p;

	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;

	return p;
}

// ����������� ��������� �� �������
Time Time::operator +(const int k) {
	int temp1 = min * 60 + sec;
	int temp2 = k * 60 + k;

	Time p;

	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;

	return p;
}

// ���������� �������� �������� ���������
bool Time::operator ==(const Time& t) {
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;

	if (temp1 == temp2) return true;

	return false;
}

// ���������� ���������� �������-�������� �����
istream& operator >>(istream& in, Time& t) {
	cout << "������� ������: ";
	in >> t.min;
	cout << "������� �������: ";
	in >> t.sec;

	return in;
}

// ���������� ���������� �������-�������� ������
ostream& operator <<(ostream& out, const Time& t) {
	return (out << t.min << " : " << t.sec);
}