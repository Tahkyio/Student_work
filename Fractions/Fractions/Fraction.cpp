#include <stdio.h>
#include <iostream>
#include "Fraction.h"
///////////////////////////////////////////////////////////////////////
//Constructor/Deconstructor

Fraction::Fraction()
{
	numerator = 1;
	denomenator = 1;
}

//Fraction::Fraction(int numerator, int denomenator) {}						//Узнать про список инициализации.
///////////////////////////////////////////////////////////////////////
//Calculations
Fraction Fraction::getSum(const Fraction b)
{
	Fraction c;
	if (denomenator = b.denomenator)
	{
		c.numerator = numerator + b.numerator;
		c.denomenator = denomenator;
		return c;
	}
	c.numerator = numerator*b.denomenator + b.numerator*denomenator;
	c.denomenator = denomenator*b.denomenator;
	return c;
}

Fraction Fraction::getDiff(const Fraction b)
{
	Fraction c;
	if (denomenator = b.denomenator)
	{
		c.numerator = numerator - b.numerator;
		c.denomenator = denomenator;
		return c;
	}
	c.numerator = numerator * b.denomenator - b.numerator*denomenator;
	c.denomenator = denomenator * b.denomenator;
	return c;

}
Fraction Fraction::getMult(const Fraction b)
{
	Fraction c;
	if (denomenator == 0 || b.denomenator == 0) {
		std::cerr << "getMult() resulted with 0 in denomenator - the result was replaced with 1/1";
		return(Fraction(1, 1));
	}
	c.numerator = numerator * b.numerator;
	c.denomenator = denomenator * b.denomenator;
	return c;

}
Fraction Fraction::getDiv(const Fraction b)
{
	Fraction c;
	if (denomenator == 0 || b.numerator == 0) {
		std::cerr << "getDiv() resulted with 0 in denomenator - the result was replaced with 1/1";
		return(Fraction(1, 1));
	}
	c.numerator = numerator * b.denomenator;
	c.denomenator = denomenator * b.numerator;
	return c;

}
////////////////////////////////////////////////////////////////////////
void Fraction::print()
{
	printf("%d/%d", numerator, denomenator);
}