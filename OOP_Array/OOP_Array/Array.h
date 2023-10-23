#pragma once
class Array
{
public:
	Array(const int size = 15, const int value = 0);	 //Конструктор по умолчанию 
	Array(const Array&);								 //Конструктор копирования
	~Array();											 //Деконструктор

	void swap(Array);
	int find(int);
	int getSize(const Array);

	void print()const;
	int const& operator[](const int index);

private:
	int* m_array = nullptr;
	int m_size = 0;
};

