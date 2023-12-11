#pragma once
#define UC unsigned char 
#define UI unsigned int 

class BoolVector
{
public:
	BoolVector();
	BoolVector(int);
	BoolVector(const BoolVector&);
	~BoolVector();

	UC& operator[](const int) const;
	BoolVector operator=(BoolVector const);
	BoolVector operator&(BoolVector const)const;
	BoolVector operator|(BoolVector const)const;
	BoolVector operator^(BoolVector const)const;
	BoolVector operator~()const;


	void swap(BoolVector vec);
	void set(UI const, UI const);
	void input();
	void output();
	void invertByIndex(UI const);
	void invert();
	int getSize() const;

private:
	int m_size = 0;
	UC* m_array = nullptr;
};

