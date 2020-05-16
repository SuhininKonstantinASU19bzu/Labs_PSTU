#include <iostream>
#include "ipart.h"

using namespace std;

// ���������� ������ ��� ������������� ����� ���������
void ipart::Init(unsigned F, unsigned S) {
	first = F;

	if (S != 0) {
		second = S;
	}

	else {
		cout << endl << "!!! ������ �������������: ����������� ����� 0 !!!" << endl;
		exit(1);
	}
}

// ���������� ������ ��� ������ �������� ����� ���������
void ipart::Read() {
	cout << endl << "������� �������� first: ";
	cin >> first;
	cout << endl << "������� �������� second: ";
	cin >> second;
}

// ���������� ������ ��� ������ �������� ����� ���������
void ipart::Show() {
	cout << endl << "��������� ���� �������� first �����: " << first;
	cout << endl << "��������� ���� �������� second �����: " << second;
	cout << endl << endl;
}

// ���������� ������ ��������� ����� ����� �����
int ipart::Resolve() {
	int r;

	if (second != 0) {
		r = first / second;
	}

	else {
		cout << endl << "!!! ������ : ����������� ����� 0 !!!" << endl;
		exit (2);
	}

	return r;
}