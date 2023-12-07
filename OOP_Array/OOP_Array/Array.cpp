#include "Array.h"
#include <iostream>
#include <assert.h>

int const &Array::operator[](const int index) //сделать второй оператор, что только читает, но не меняет значений
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}
int const& Array::operator[](const int index) const 
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

Array Array::operator=(const Array arr) //a = b = c
//сделать "подрезание" массива, что больше
{
	if (m_size == 0)
	{
		m_size = arr.m_size;
		m_array = new int[m_size];
		for (int i = 0; i < m_size; i++)
			m_array[i] = arr.m_array[i];
	}
	else
	{
		int* tmp;
		tmp = new int[arr.m_size];
		for (int i = 0; i < arr.m_size; i++)
		{
			tmp[i] = arr.m_array[i];
		}
		delete[] m_array;
		m_array = tmp;
		m_size = arr.m_size;

	}
	return arr;
}

///////////////////////////////////////////////////////////////////////
Array::Array()
{
	m_size = 15;
	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}
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
int Array::getSize(const Array)
{
	return m_size;
}

void Array::swap(Array arr)
//нужно прямо элементы перекидывать, или можно так?
{
	int* tmp=arr.m_array;

	arr.m_array = m_array;
	m_array = tmp;
}

void Array::sort()		//сортировка вставкой
{
	int i, flag, j;
	for (i = 1; i < m_size; i++) {
		flag = m_array[i];
		j = i - 1;
		while (j >= 0 && m_array[j] > flag) {
			m_array[j + 1] = m_array[j];
			j = j - 1;
		}
		m_array[j + 1] = flag;
	}
}

void Array::fillRand(int const min, int const max)
{
	for (int i = 0; i < m_size; i++)
		m_array[i] = rand()%(max-min+1)+min;
}

int Array::find(int const value, int const st, int const fin)
{
	for (int i = st; i < fin; i++)
		if (m_array[i] == value)
			return i;
	return -1;
} 

bool Array::replace(const int index, const int value)
{
	if (index >= m_size)
		return false;
	m_array[index] = value;
	return true;
}
bool Array::removeByIndex(const int index) //pop
{
	if (index >= m_size)
		return false;
	for (int i = index; i < m_size-1; i++)
		m_array[i] = m_array[i+1];
	m_size--;
	return true;
}
bool Array::removeByValue(const int value)
{
	bool indexNotFound=true;
	for (int i = 0; i < m_size; i++)
		if (m_array[i] == value)
		{
			for (int j = i; j < m_size - 1; j++)
				m_array[j] = m_array[j + 1];
			m_size--;
			indexNotFound = false;
			return true;
		}
	if(indexNotFound)
		return false;
	else return true;
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

