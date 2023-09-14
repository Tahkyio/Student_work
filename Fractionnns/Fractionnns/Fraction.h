#pragma once


class Fraction
{public:
	Fraction();
	Fraction(int numerator, int denomenator);
	~Fraction()=default;
	
	int numerator;
	int denomenator;

	Fraction getSum(const Fraction b);
	Fraction getDiff(const Fraction b);
	Fraction getMult(const Fraction b);
	Fraction getDiv(const Fraction b);
	void print();
};

