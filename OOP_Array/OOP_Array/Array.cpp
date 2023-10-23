#include "Array.h"
#include <iostream>
#include <assert.h>

int const &Array::operator[](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

///////////////////////////////////////////////////////////////////////
Array::Array(const int size, const int value)
{
	if (size < 0)
	{
		std::cerr << "WARNING: negative size value found in Array::Array - inversion applied\n";
		m_size = -size;
	}
	else m_size = size;
	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = value;
	}
}

Array::Array(const Array& arr)
{
	m_size = arr.m_size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = arr.m_array[i];
}

Array::~Array()
{
	delete[] m_array;
}
/////////////////////////////////////////////////////////////
void Array::swap(Array arr)
//нужно пр€мо элементы перекидывать, или можно так?
{
	int* tmp=arr.m_array;

	arr.m_array = m_array;
	m_array = tmp;
}
int Array::find(int value)
{
	for (int i = 0; i < m_size; i++)
		if (m_array[i] == value)
			return i;
		
	return -1;
}
int Array::getSize(const Array arr)
{
	return arr.m_size;
}
////////////////////////////////////////////////////////////
void Array::print() const
{
	std::cout << '[';
	for (int i = 0; i < m_size - 1; ++i)
	{
		std::cout << m_array[i] << ", ";
	}
	std::cout << m_array[m_size - 1] << "]\n";
}