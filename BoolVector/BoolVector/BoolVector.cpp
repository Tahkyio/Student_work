#include "BoolVector.h"
#include <stdio.h>
#include <iostream>
#define UC unsigned char
#define UI unsigned int

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
BoolVector::BoolVector()
{
	m_size = 8;
	m_arr = new UC[m_size];
	for (int i = 0; i < m_size; i++)
		m_arr[i] = '0';
}

BoolVector::BoolVector(int size)
{
	if (size < 0)
	{
		std::cerr << "ERROR: Negative size value found: Inversion applied.\n";
		size *= -1;
	}  m_size = size;

	m_arr = new UC[m_size];
	for (int i = 0; i < m_size; i++)
		m_arr[i] = '0';
}

BoolVector::~BoolVector()
{
	delete[] m_arr;
}
/////////////////////////////////////////////////////////////////////////
void BoolVector::swap(BoolVector vec) //так же можно?? не пересоздавая и копируя лишний раз массивы?
{
	UC* tmp; int tmpSize = 0;

	tmp		   = vec.m_arr;
	vec.m_arr  = m_arr;
	m_arr	   = tmp;

	tmpSize	   = vec.m_size;
	vec.m_size = m_size;
	m_size	   = tmpSize;

}
void BoolVector::set(UI const index, UI const value)
{
	if (index > m_size) std::cerr << "ERROR: Invalid index value in BoolVector::set() - Value exeeds BoolVector Size.\n";
	else if (value > 1) std::cerr << "ERROR: value in in BoolVector::set() must be 0 or 1!\n";
	else {
		if (value) m_arr[index] = '1';
		else	   m_arr[index] = '0';
	}
}
void BoolVector::invertByIndex(UI const index)
{
	if (index > m_size) std::cerr << "ERROR: Invalid index value in BoolVector::invert() - Value exeeds BoolVector Size.\n";
	else
	{
		if(m_arr[index] == '1') m_arr[index] = '0';
		else					m_arr[index] = '1';
	}
}
void BoolVector::invert()
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_arr[i] == '0') m_arr[i] = '1';
		else				 m_arr[i] = '0';
	}
}

int BoolVector::getSize() const
{
	return m_size;
}