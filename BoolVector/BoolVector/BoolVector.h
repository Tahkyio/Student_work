#pragma once
#define UC unsigned char 
#define UI unsigned int 

class BoolVector
{
public:
	BoolVector();
	BoolVector(int size);
	~BoolVector() = default;

	void swap(BoolVector vec);
	void set(UI const index, UI const value);
	void invertByIndex(UI const index);
	void invert();
	int getSize() const;

private:
	int m_size = 0;
	UC* m_arr = nullptr;
};

