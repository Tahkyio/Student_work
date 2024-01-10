#pragma once
#include <iostream>
#define UC unsigned char 
#define UI unsigned int 

class BoolVector
{
public:
	BoolVector();
	BoolVector(int amountOfBytes);
	BoolVector(const BoolVector&);
	~BoolVector();

	UC& operator[](const int) const;
	BoolVector &operator=(BoolVector const);
	BoolVector operator&(BoolVector const)const;
	BoolVector operator|(BoolVector const)const;
	BoolVector operator^(BoolVector const)const;
	BoolVector operator~()const;


	void swap(BoolVector &with);
	void set(UI const index, bool const value);
	void input();
	void output();
	void invertByIndex(UI const index);
	void invert();
	int getLen() const;
	int getWeight() const;

private:
	int m_amountOfBytes = 8;
	int m_arrayMemorySize = 0;
	UC* m_array = nullptr;
};

std::ostream& operator<<(std::ostream& stream, const BoolVector& vec);
std::istream& operator>>(std::istream& stream, BoolVector& vec);

