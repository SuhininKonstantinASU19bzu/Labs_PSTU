#pragma once
#include "Person.h"

// ����� Student ����������� �� ������ Person
class Student :
	public Person {

	// ��������
private:
	float rating; // �������

public:
	// ������������
	Student(); // ��� ����������
	Student(string, int, float); // � �����������
	Student(const Student&); // �����������

	// ����������
	~Student();

	// ���������
	float get_rating();

	// ������������
	void set_rating(float);

	// �������� ������������
	Student& operator =(const Student&);

	// ������� ��������� ��������� ������ � ������� ���������
	void Show();

	// ������� ����� �������� ���������
	void Input();
};