#include "BoolVector.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#define UC unsigned char
#define UI unsigned int

int max(int a, int b)
{
	if(b>=a) return b;
	return a;
}
int min(int a, int b)
{
	if (b <= a) return b;
	return a;
}
void copyUcArray(UC* from, UC* to, int len)
{
	for (int i = 0; i < len; i++)
	{
		to[i] = from[i];
	}
}
/////////////////////////////////////////////////////////////////////////
BoolVector::BoolVector()
{
	m_size = 8;
	m_array = new UC[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = '0';
}

BoolVector::BoolVector(int size)
{
	if (size < 0)
	{
		std::cerr << "ERROR: Negative size value found: Inversion applied.\n";
		size *= -1;
	}  m_size = size;

	m_array = new UC[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = '0';
}

BoolVector::BoolVector(const BoolVector& vec)
{
	m_size = vec.m_size;

	m_array = new UC[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = vec.m_array[i];
}

BoolVector::~BoolVector()
{
	delete[] m_array;
}

/////////////////////////////////////////////////////////////////////////

UC& BoolVector::operator[] (const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

BoolVector BoolVector::operator=(BoolVector const vec)
{
	if(m_size!=0) delete[] m_array;
	m_size = vec.m_size;

	m_array = new UC[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = vec.m_array[i];
	return vec;
}
BoolVector BoolVector::operator&(BoolVector const vec) const
{
	BoolVector tmp(max(m_size, vec.m_size));
	for (int i = 0; i < min(m_size, vec.m_size); i++)
		if (m_array[i] == '1' && vec.m_array[i] == '1')
			 tmp.m_array[i] = '1';
	//здесь дозаполнять не требуется тк.к умножение на 0 даёт 0
	return tmp;
}
BoolVector BoolVector::operator|(BoolVector const vec) const
{
	BoolVector tmp(max(m_size, vec.m_size));

	for (int i = 0; i < min(m_size, vec.m_size); i++)
		if (m_array[i] == '1' || vec.m_array[i] == '1')
			tmp.m_array[i] = '1';

	if (m_size>vec.m_size)	//дозаполняем, принимая словно там у "короткого" везде нули
		for (int i = min(m_size, vec.m_size); i < tmp.m_size; i++)
			if (m_array[i] == '1') tmp.m_array[i] = '1';
	else if (m_size < vec.m_size)
		for (int i = min(m_size, vec.m_size); i < tmp.m_size; i++)
			if (vec.m_array[i] == '1') tmp.m_array[i] = '1';

	return tmp;
}
BoolVector BoolVector::operator^(BoolVector const vec) const
{
	BoolVector tmp(max(m_size, vec.m_size));
	for (int i = 0; i < min(m_size, vec.m_size); i++)
		if (m_array[i] == '1' && vec.m_array[i] == '0' || m_array[i] == '0' && vec.m_array[i] == '1')
			tmp.m_array[i] = '1';

	if (m_size > vec.m_size)	//дозаполняем, принимая словно там у "короткого" везде нули
		for (int i = min(m_size, vec.m_size); i < tmp.m_size; i++)
			if (m_array[i] == '1') tmp.m_array[i] = '1';
	else if (m_size < vec.m_size)
		for (int i = min(m_size, vec.m_size); i < tmp.m_size; i++)
			if (vec.m_array[i] == '1') tmp.m_array[i] = '1';

	return tmp;
}
BoolVector BoolVector::operator~() const
{
	BoolVector tmp(m_size);
	for (int i = 0; i < tmp.m_size; i++)
		if (m_array[i] == '0') tmp.m_array[i] = '1';
	return tmp;
}

/////////////////////////////////////////////////////////////////////////

void BoolVector::swap(BoolVector vec) //так же можно?? не пересоздавая и копируя лишний раз массивы?
{
	UC* tmp; int tmpSize = 0;

	tmp		   = vec.m_array;
	vec.m_array  = m_array;
	m_array	   = tmp;

	tmpSize	   = vec.m_size;
	vec.m_size = m_size;
	m_size	   = tmpSize;

}
void BoolVector::set(UI const index, UI const value)
{
	if (index > m_size) std::cerr << "ERROR: Invalid index value in BoolVector::set() - Value exeeds BoolVector Size.\n";
	else if (value > 1) std::cerr << "ERROR: value in in BoolVector::set() must be 0 or 1!\n";
	else {
		if (value) m_array[index] = '1';
		else	   m_array[index] = '0';
	}
}
//Скорее всего я перемудрила с этой функцией и можно намного проще
//возможно стоит просто сделать функцию-проверку есть ли что-то кроме 0 и 1
void BoolVector::input()
{
	std::string tmpLine; 
	std::cin >> tmpLine;
	bool correctInput = true;
	BoolVector tmp(tmpLine.size());
	//Если мы берем вектор в котором что-то записано, я не хочу потерять это значени
	//при обнаружении символа, отличного от 1 и 0. Поэтому создаю временную переменную
	for (int i = 0; i < tmp.m_size; i++)
	{
		if (tmpLine[i] == ' ')
		{
			tmp.m_size = i;
			break;
		}
		else if (tmpLine[i] == '1' || tmpLine[i] == '0')
			tmp.m_array[i] = tmpLine[i];
		else {
			std::cerr << "ERROR: Incorrect BoolVector value recieved in BoolVector::input()!\n";
			correctInput = false;
			break;
		}
	}
	if (correctInput)
	{
		if (m_size != 0)
			delete[]m_array;
		m_size = tmp.m_size;
		m_array = new UC[m_size];
		copyUcArray(tmp.m_array, m_array, m_size);
	}
}

void BoolVector::output()
{
	for (int i = 0; i < m_size; i++)
		std::cout << m_array[i];
}

void BoolVector::invertByIndex(UI const index)
{
	if (index > m_size) std::cerr << "ERROR: Invalid index value in BoolVector::invert() - Value exeeds BoolVector Size.\n";
	else
	{
		if(m_array[index] == '1') m_array[index] = '0';
		else					  m_array[index] = '1';
	}
}
void BoolVector::invert()
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] == '0') m_array[i] = '1';
		else				   m_array[i] = '0';
	}
}

int BoolVector::getSize() const
{
	return m_size;
}