#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc); // ������� ��� ������

	if (!stream) return -1; // ������ �������� �����

	Time t;
	int n;

	cout << "������� ���������� �������: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t; // ���� ��������� �������
		stream << t << endl; // ������ � �������� �����
	}

	stream.close(); // �������� ��������� ������

	return n; // ������� ���������� ��������� ��������
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in); // ������� ��� ������

	if (!stream) return -1; // ������ �������� �����

	Time t;
	int i = 0;

	while (stream >> t) {
		cout << t << endl;
		i++;
	}

	stream.close();

	return i; // ������� ���������� ���������� �������� 
}

int del_file(const char* f_name, int k) {
	fstream temp("temp", ios::out); // ������� ��� ������ ��������� ����
	fstream stream(f_name, ios::in); // ������� ���� ��� ������

	if (!stream) return -1; // ������ �������� �����

	Time t;
	int i = 0;

	while (stream >> t) {
		i++;
		if (i != k) temp << t; // ���� ����� ������� �� ����� k �� ����� ��� �� ��������� ����
	}

	stream.close();
	temp.close();

	remove(f_name); // �������� ������� �����
	rename("temp", f_name); // �������������� ���������� ����� � ��������

	return i; // ���������� ����������� ���������
}

int add_file(const char* f_name, int k, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	Time t;
	int i = 0;
	int l = 0;

	while (stream >> t) {
		i++;

		if (i == k)	{
			temp << tt;
			l++;
		}

		temp << t;
	}

	stream.close();
	temp.close();

	remove(f_name);
	rename("temp", f_name);

	return l;
}

int add_end(const char* f_name, Time tt) {
	fstream stream(f_name, ios::app);

	if (!stream) return -1;

	stream << tt;

	return 1;
}

int change_file(const char* f_name, int k, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	Time t;
	int i = 0;
	int l = 0;
	char x;

	while (stream >> t) {
		i++;

		if (i == k) {
			temp << tt;
			l++;
		}
		else temp << t;
	}

	stream.close();
	temp.close();

	remove(f_name);
	rename("temp", f_name);

	return l;
}

int del_compare(const char* f_name) {
	fstream temp("temp", ios::out); // ������� ��� ������ ��������� ����
	fstream stream(f_name, ios::in); // ������� ���� ��� ������

	if (!stream) return -1; // ������ �������� �����

	Time t1, t2;
	int i = 0;

	cout << "������� �������� ��������� ���������:" <<endl;
	cin >> t2;

	while (stream >> t1) {
		i++;

		if (!(t1 == t2)) temp << t1;
	}

	stream.close();
	temp.close();

	remove(f_name); // �������� ������� �����
	rename("temp", f_name); // �������������� ���������� ����� � ��������

	return i; // ���������� ����������� ���������
}

int add_time(const char* f_name, const Time& t) {
	fstream temp("temp", ios::out); // ������� ��� ������ ��������� ����
	fstream stream(f_name, ios::in); // ������� ���� ��� ������

	if (!stream) return -1; // ������ �������� �����

	Time t1, t2, t3;
	int i = 0;

	cout << "������� �������� �������� ��� ���������� ���������:" << endl;
	cin >> t2;

	while (stream >> t1) {
		i++;

		if (t1 == t2) {
			t1 = t1 + t;
			temp << t1;
		}
		else temp << t1;
	}

	stream.close();
	temp.close();

	remove(f_name); // �������� ������� �����
	rename("temp", f_name); // �������������� ���������� ����� � ��������

	return i; // ���������� ����������� ���������
}

int add_after(const char* f_name, int k) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	int i = 0;
	int l = 0;

	Time t1, t2;
	int n;

	while (stream >> t1) {
		i++;

		if (i == k) {
			cout << "������� ���������� �������: ";
			cin >> n;

			temp << t1;

			for (int iter = 0; iter < n; iter++) {
				cin >> t2; // ���� ��������� �������
				temp << t2; // ������ � �������� �����
				l++;
			}
		}
		else temp << t1;
	}

	stream.close();
	temp.close();

	remove(f_name);
	rename("temp", f_name);

	return l;
}