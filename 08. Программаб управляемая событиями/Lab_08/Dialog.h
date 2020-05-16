#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog :
	public Vector {

	// ��������
protected:
	int EndState;

public:
	// ������������
	Dialog(); // ��� ����������

	// �����������
	virtual ~Dialog();

	// ������
	int Valid(); // �������� �������� EndState
	void EndExec(); // ��������� ������� "����� ������"
	virtual void GetEvent(TEvent& event); // ��������� �������
	virtual void HandleEvent(TEvent& event); // ����������
	virtual void ClearEvent(TEvent& event); // ������� �������
	virtual int Execute(); // ������� ���� ��������� �������
};