#include "Weather.h"

using namespace std;

// ���������� �������� ������������
Weather& Weather::operator =(const Weather& t) {
	// �������� �� ����������������
	if (&t == this) return *this;

	dayW = t.dayW;
	tempW = t.tempW;
	del = t.del;

	return *this;
}

// ���������� ���������� �������� ���������
Weather& Weather::operator ++() {
	tempW++;

	return *this;
}

// ���������� �������� �������� ��������
Weather Weather::operator +(const Weather& t) {
	Weather p;
	
	if (!t.del) p.tempW = tempW + t.tempW;
	else p.tempW = tempW;

	return p;
}

//
Weather Weather::operator +(const int& i) {
	Weather p;

	p.tempW = tempW + i;

	return p;
}

//
Weather Weather::operator /(const Weather& t) {
	Weather p;

	p.tempW = tempW / t.tempW;

	return p;
}

//
Weather Weather::operator /(const int& i) {
	Weather p;

	p.tempW = tempW / i;

	return p;
}

// ���������� �������� �������� ���������
bool Weather::operator ==(const Weather& t) {
	if (tempW == t.tempW && !del && !t.del) return true;

	return false;
}

bool Weather::operator !=(const Weather& t) {
	if (tempW != t.tempW && !del && !t.del) return true;

	return false;
}

//
bool Weather::operator >(const Weather& t) {
	if (tempW > t.tempW && !del && !t.del) return true;

	return false;
}

bool Weather::operator >(const int& i) {
	if (tempW > i) return true;

	return false;
}

//
bool Weather::operator <(const Weather& t) {
	if (tempW < t.tempW && !del && !t.del) return true;

	return false;
}

bool Weather::operator <(const int& i) {
	if (tempW < i) return true;

	return false;
}

// ���������� ���������� �������-�������� �����
istream& operator >>(istream& in, Weather& t) {
	cout << "������� ����: ";
	in >> t.dayW;
	cout << "������� �����������: ";
	in >> t.tempW;

	return in;
}

// ���������� ���������� �������-�������� ������
ostream& operator <<(ostream& out, const Weather& t) {
	if (!t.del) out << "| " << t.dayW << setw(11) << " : " << setw(11) << t.tempW << " |" << endl;

	return out;
}

// �������� ����
fstream& operator >>(fstream& fin, Weather& t) {
	fin >> t.dayW;
	fin >> t.tempW;
	fin >> t.del;
	
	return fin;
}

// �������� �����
fstream& operator <<(std::fstream& fout, const Weather& t) {
	fout << t.dayW << endl;
	fout << t.tempW << endl;
	fout << t.del << endl;
	
	return fout;
}