#include "Fraction.h"

// ����������� ��� ����������
Fraction::Fraction() :Pair() {
	// ������� = 0;
}

// ����������� � �����������
Fraction::Fraction(int F, int S) : Pair(F, S) {
	// ������� = �;
}

// ����������� �����������
Fraction::Fraction(const Fraction& F) {
	first = F.first;
	second = F.second;
}

// ����������
Fraction::~Fraction() {

}

// ���������� �������� ������������
Fraction& Fraction::operator =(const Fraction& f) {
	// �������� �� ����������������
	if (&f == this) return *this;
	first = f.first;
	second = f.second;

	return *this;
}

// �������� ���������
bool Fraction::operator ==(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne == firstTwo) && (secondOne == secondTwo)) return true;

	return false;
}

bool Fraction::operator !=(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne != firstTwo) || (secondOne != secondTwo)) return true;

	return false;
}

bool Fraction::operator >=(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if (((firstOne > firstTwo) || ((firstOne == firstTwo) && (secondOne > secondTwo))) || ((firstOne == firstTwo) && (secondOne == secondTwo))) return true;

	return false;
}

bool Fraction::operator <=(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if (((firstOne < firstTwo) || ((firstOne == firstTwo) && (secondOne < secondTwo))) || ((firstOne == firstTwo) && (secondOne == secondTwo))) return true;

	return false;
}

bool Fraction::operator >(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne > firstTwo) || ((firstOne == firstTwo) && (secondOne > secondTwo))) return true;

	return false;
}

bool Fraction::operator <(const Fraction& f) {
	int firstOne = first;
	int secondOne = second;
	int firstTwo = f.first;
	int secondTwo = f.second;

	if ((firstOne < firstTwo) || ((firstOne == firstTwo) && (secondOne < secondTwo))) return true;

	return false;
}

// ��������� ����� ����� ����� !!!!
int Fraction::Resolve() {
	int r;

	if (second != 0) {
		r = first / second;
	}

	else {
		cout << endl << "!!! ������ : ����������� ����� 0 !!!" << endl;
		exit(111);
	}

	return r;
}

// ������� ��������� ��������� ������ � ������� ���������
void Fraction::Show() {
	cout << endl << "�����: " << first << "," << second << endl;
}

// ���������� ������� �����
istream& operator >>(istream& in, Fraction& f) {
	cout << endl << "������� ����� �����: ";
	in >> f.first;
	cout << endl << "������� ������� �����: ";
	in >> f.second;
	if (f.second < 0) {
		cout << "error";
		exit(130);
	}
	return in;
}

// ���������� ������� ������
ostream& operator <<(ostream& out, const Fraction& f) {
	out << endl << "�����: " << f.first << "," << f.second << endl;

	return out;
}