#include "BoolVector.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#define UC unsigned char
#define UI unsigned int

//Функции которые используются в других функциях
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
void convertLineToBoolVector()
{

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
	m_arrayMemorySize = (m_amountOfBytes - 1) / 8 + 1;
	m_array = new UC[m_arrayMemorySize];
	for (int i = 0; i < m_arrayMemorySize; i++)
		m_array[i] = 0;
}

BoolVector::BoolVector(int amount)
{
	if (amount < 0)
	{
		std::cerr << "Warning: Negative size value found in BoolVector(): Inversion applied.\n";
		amount *= -1;
	}  m_amountOfBytes = amount;

	m_arrayMemorySize = (m_amountOfBytes - 1) / 8 + 1;
	m_array = new UC[m_arrayMemorySize];
	for (int i = 0; i < m_arrayMemorySize; i++)
		m_array[i] = '0';
}

BoolVector::BoolVector(const BoolVector& vec)
{
	m_amountOfBytes = vec.m_amountOfBytes;
	m_arrayMemorySize = vec.m_arrayMemorySize;
	m_array = new UC[m_arrayMemorySize];
	for (int i = 0; i < m_arrayMemorySize; i++)
		m_array[i] = vec.m_array[i];
}

BoolVector::~BoolVector()
{
	delete[] m_array;
}

/////////////////////////////////////////////////////////////////////////

UC& BoolVector::operator[] (const int index) const
{
	assert(index >= 0 && index < m_amountOfBytes);
	return m_array[index];
}

BoolVector& BoolVector::operator=(BoolVector const vec)
{
	if(m_amountOfBytes!=0) delete[] m_array;
	m_amountOfBytes = vec.m_amountOfBytes;

	m_array = new UC[m_amountOfBytes];
	for (int i = 0; i < m_amountOfBytes; i++)
		m_array[i] = vec.m_array[i];
}
BoolVector BoolVector::operator&(BoolVector const vec) const
{
	BoolVector tmp(max(m_arrayMemorySize, vec.m_arrayMemorySize));
	for (int i = 0; i < min(m_arrayMemorySize, vec.m_arrayMemorySize); i++)
		tmp.m_array[i] = m_array[i] & vec.m_array[i];
	//здесь дозаполнять не требуется тк.к умножение на 0 даёт 0
	return tmp;
}
BoolVector BoolVector::operator|(BoolVector const vec) const
{
	BoolVector tmp(max(m_arrayMemorySize, vec.m_arrayMemorySize));

	for (int i = 0; i < min(m_amountOfBytes, vec.m_amountOfBytes); i++)
		tmp[i] = m_array[i] | vec.m_array[i];
	if (m_arrayMemorySize > vec.m_arrayMemorySize)
		for (int i = vec.m_arrayMemorySize; i < m_arrayMemorySize; i++)
			tmp[i] |= m_array[i];
	else 
		for (int i = m_arrayMemorySize; i < vec.m_arrayMemorySize; i++)
			tmp[i] |= vec.m_array[i];

	return tmp;
}
//переделать
BoolVector BoolVector::operator^(BoolVector const vec) const
{
	BoolVector tmp(max(m_amountOfBytes, vec.m_amountOfBytes));
	for (int i = 0; i < min(m_amountOfBytes, vec.m_amountOfBytes); i++)
		if (m_array[i] == '1' && vec.m_array[i] == '0' || m_array[i] == '0' && vec.m_array[i] == '1')
			tmp.m_array[i] = '1';

	if (m_amountOfBytes > vec.m_amountOfBytes)	//дозаполняем, принимая словно там у "короткого" везде нули
		for (int i = min(m_amountOfBytes, vec.m_amountOfBytes); i < tmp.m_amountOfBytes; i++)
			if (m_array[i] == '1') tmp.m_array[i] = '1';
	else if (m_amountOfBytes < vec.m_amountOfBytes)
		for (int i = min(m_amountOfBytes, vec.m_amountOfBytes); i < tmp.m_amountOfBytes; i++)
			if (vec.m_array[i] == '1') tmp.m_array[i] = '1';

	return tmp;
}
BoolVector BoolVector::operator~() const
{
	BoolVector tmp(m_amountOfBytes);
	for (int i = 0; i < tmp.m_arrayMemorySize; i++)
		tmp.m_array[i] = ~m_array[i];
	return tmp;
}

/////////////////////////////////////////////////////////////////////////

void BoolVector::swap(BoolVector &vec) //так же можно?? не пересоздавая и копируя лишний раз массивы?
{
	UC* tmp; int tmpSize = 0;

	tmp		   = vec.m_array;
	vec.m_array  = m_array;
	m_array	   = tmp;

	tmpSize	   = vec.m_amountOfBytes;
	vec.m_amountOfBytes = m_amountOfBytes;
	m_amountOfBytes	   = tmpSize;
}
void BoolVector::set(UI const index, bool value)
{
	if (index > m_amountOfBytes) std::cerr << "ERROR: Invalid index value in BoolVector::set() - Value exeeds BoolVector Size.\n";
	else if (value > 1) std::cerr << "ERROR: value in in BoolVector::set() must be 0 or 1!\n";
	else {
		UI mask = 1;
		int segment = m_arrayMemorySize - index / 8;
		int move = index % 8;
		//0000_0000 0000_0001
		//0			1
		mask<<= move;
		if (value == 0) {
			mask = ~mask;
			m_array[segment] & mask;
		}
		else m_array[segment] | mask;
	}
}


void BoolVector::output()
{
	for (int i = 0; i < m_amountOfBytes; i++)
		std::cout << m_array[i]<<' ';
}

void BoolVector::invertByIndex(UI const index)
{
	if (index > m_amountOfBytes) std::cerr << "ERROR: Invalid index value in BoolVector::invert() - Value exeeds BoolVector Size.\n";
	else
	{
		if(m_array[index] == '1') m_array[index] = '0';
		else					  m_array[index] = '1';
	}
}
void BoolVector::invert()
{
	for (int i = 0; i < m_amountOfBytes; i++)
	{
		if (m_array[i] == '0') m_array[i] = '1';
		else				   m_array[i] = '0';
	}
}

int BoolVector::getLen() const
{
	return m_amountOfBytes;
}

int BoolVector::getWeight() const
{
	int count = 0;
	for (int i = 0; i < m_arrayMemorySize; i++)
	{
		UI mask = 1;
		for (int j = 0; j < 8; j++)
			if (mask & m_array[i] == 0) { 
				count++; 
				mask <<= 1;
			}
	}
	return count;
}

std::ostream& operator<<(std::ostream& stream, const BoolVector& vec)
{
	for (int i = 0; i < vec.getLen() - 1; ++i)
		stream << vec[i];
	stream << vec[vec.getLen() - 1] << " ";
	return stream;
}

//В таком случае ты не можешь ввести вектор любой длинны
//еще надо как-то обработать чтобы человек не ввёл не те символы и числа 
/*std::istream& operator>>(std::istream& stream, BoolVector& vec)
{
	for (int i = 0; i < vec.getSize(); ++i) {
		stream >> vec[i];
	}
	return stream;
}
*/
std::istream& operator>>(std::istream& stream, BoolVector& vec)
{
	UI mask = 1;
	mask <<= 7;
	if (vec.getLen() % 8 != 0) mask >>= vec.getLen() % 8;
	char tmp;
	int segment = 0;
	for (int i = 0; i < vec.getLen(); ++i) {
		stream >> tmp;
		if (mask == 1) {
			segment++;
			mask = 128;
		}
		if (tmp == '0') mask >>= 1;
		else vec[segment] | mask;
	}
	return stream;
}