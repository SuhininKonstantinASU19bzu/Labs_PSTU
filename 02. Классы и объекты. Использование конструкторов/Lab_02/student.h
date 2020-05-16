#pragma once
#include <string>

using namespace std;

class Student {
	// ��������
	string fullname;
	string group;
	float averagemark;

public:
	Student(); // ����������� ��� ����������
	Student(string, string, float); // ����������� � �����������
	Student(const Student&); // ����������� �����������
	~Student(); // ����������

	// ���������
	string get_fullname();
	string get_group();
	float get_averagemark();

	// ������������
	void set_fullname(string);
	void set_group(string);
	void set_averagemark(float);

	// �������� ���������
	void Show();
};
