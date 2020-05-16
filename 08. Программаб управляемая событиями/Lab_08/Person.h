#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Person :
	public Object {

	// ��������
protected:
	string name;
	int age;

public:
	// ������������
	Person(); // ��� ����������
	Person(string, int); // � �����������
	Person(const Person&); // �����������

	// �����������
	~Person();

	// ������
	// ���������
	string get_name();
	int get_age();

	// ������������
	void set_name(string);
	void set_age(int);

	// ���������� �������� ������������
	Person& operator =(const Person&);

	// ������� ��������� ��������� ������ � ������� ���������
	void Show();

	// ������� ����� �������� ���������
	void Input();

	// ���� �� ������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void HandleEvent(const TEvent& e);
};

