#include "BoolVector.h"
#include "BoolMatrix.h"
#include <assert.h>
#define UC unsigned char 
#define UI unsigned int 

//У каждой строки должен быть же свой адрес??? вот так оно же будет работать??
//Или деконструктор сразу tmp удалит и удалится и строка?
BoolMatrix::BoolMatrix()
{
	m_array = new BoolVector[m_lines];
		for (int i = 0; i < m_lines; i++)
		{
			BoolVector tmp(m_columns);
			m_array[i] = tmp;
		}
}

BoolMatrix::BoolMatrix(int lines, int columns)
{
	if (lines < 0)
	{
		std::cerr << "Warning: Negative lines value found in BoolMatrix(): Inversion applied.\n";
		lines *= -1;
	}  m_lines = lines;

	if (columns < 0)
	{
		std::cerr << "Warnig: Negative columns value found in BoolMatrix(): Inversion applied.\n";
		columns *= -1;
	}  m_columns = columns;

	m_array = new BoolVector[m_lines];
	for (int i = 0; i < m_lines; i++)
	{
		BoolVector tmp(m_columns);
		m_array[i] = tmp;
	}
}

BoolMatrix::~BoolMatrix()
{
	delete[] m_array;
}
////////////////////////////////////////////////

BoolVector& BoolMatrix::operator[](const int index) const
{
	assert(index >= 0 && index < m_lines);
	return m_array[index];
}

////////////////////////////////////////////////

void BoolMatrix::output()
{
	for (int i = 0; i < m_lines; i++)
	{
		m_array[i].output();
		printf_s("\n");
	}
}