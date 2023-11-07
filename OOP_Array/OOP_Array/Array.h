#pragma once
class Array
{
public:
	Array();											//Конструктор по умолчанию 
	Array(const int size, const int value);				
	Array(const Array&);								 //Конструктор копирования
	~Array();											 //Деконструктор

	int const& operator[](const int index);
	int const& operator[](const int index) const;
	Array operator=(const Array);



	int getSize(const Array);
	void fillRand(int const, int const);
	int find(int const, int const,int const);
	bool replace(int const, const int);
	bool removeByIndex(const int);
	bool removeByValue(const int);
	void sort();
	void swap(Array);
	void print()const;
private:
	int* m_array = nullptr;
	int m_size = 0;
};

