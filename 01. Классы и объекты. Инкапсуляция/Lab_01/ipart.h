#pragma once

struct ipart {
	unsigned first;
	unsigned second;
	void Init(unsigned, unsigned); // ����� ��� ������������� �����
	void Read(); // ����� ��� ������ �������� �����
	void Show(); // ����� ��� ������ �������� �����
	int Resolve(); // ����� ��������� ����� ����� �����
};