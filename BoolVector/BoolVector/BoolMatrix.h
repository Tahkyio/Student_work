#pragma once
#include "BoolVector.h"

class BoolMatrix
{
public:
	BoolMatrix();
	BoolMatrix(int n_lines, int n_columns);
	//����� ������� ���� ���������� �������??
	//���� �� ����� ������� ������ ��������, �� ��������� �� ���� �������??
	~BoolMatrix();

	BoolVector& operator[](const int) const;
	BoolMatrix operator=(BoolMatrix const);
	BoolMatrix operator&(BoolMatrix const)const;
	BoolMatrix operator|(BoolMatrix const)const;

	void input();
	void output();
	void swap();
	int getLines();
	int getColumns();
	int getWeight();
	BoolVector getConjunction();


private:

	int m_lines = 5;
	int m_columns = 5;
	BoolVector* m_array = nullptr;

};