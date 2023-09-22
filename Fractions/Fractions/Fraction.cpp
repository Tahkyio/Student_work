#include <stdio.h>
#include <iostream>
#include "Fraction.h"
///////////////////////////////////////////////////////////////////////
//Constructor/Deconstructor
Fraction::Fraction()
{
	m_numerator = 1;
	m_denomenator = 1;
}

Fraction::Fraction(const int m_numerator,const int m_denomenator)
{
	this->m_numerator = m_numerator;
	if (m_denomenator == 0) std::cerr << "ERROR: Fraction::Fraction denomenator value can't be 0. Result replaced with 'numerator/1'\n";
	else {
		this->m_denomenator = m_denomenator;
	}
}						//Узнать про список инициализации.
///////////////////////////////////////////////////////////////////////
//Calculations
Fraction Fraction::getSum(const Fraction b) const
{
	Fraction c;
	if (m_denomenator == b.m_denomenator)
	{
		c.m_numerator = m_numerator + b.m_numerator;
		c.m_denomenator = m_denomenator;
		return c;
	}
	c.m_numerator = m_numerator*b.m_denomenator + b.m_numerator*m_denomenator;
	c.m_denomenator = m_denomenator*b.m_denomenator;
	return c;
}

Fraction Fraction::getDiff(const Fraction b) const
{
	Fraction c;
	if (m_denomenator == b.m_denomenator)
	{
		c.m_numerator = m_numerator - b.m_numerator;
		c.m_denomenator = m_denomenator;
		return c;
	}
	c.m_numerator = m_numerator * b.m_denomenator - b.m_numerator*m_denomenator;
	c.m_denomenator = m_denomenator * b.m_denomenator;
	return c;

}
Fraction Fraction::getMult(const Fraction b) const
{
	Fraction c;
	if (m_denomenator == 0 || b.m_denomenator == 0) {
		std::cerr << "ERROR: Fraction::getMult() resulted with 0 in denomenator - the result was replaced with 1/1 \n";
		return(Fraction(1, 1));
	}
	c.m_numerator = m_numerator * b.m_numerator;
	c.m_denomenator = m_denomenator * b.m_denomenator;
	return c;

}
Fraction Fraction::getDiv(const Fraction b) const
{
	Fraction c;
	if (m_denomenator == 0 || b.m_numerator == 0) {
		std::cerr << "ERROR: Fraction::getDiv() resulted with 0 in denomenator - the result was replaced with 1/1 \n";
		return(Fraction(1, 1));
	}
	c.m_numerator = m_numerator * b.m_denomenator;
	c.m_denomenator = m_denomenator * b.m_numerator;
	return c;

}
////////////////////////////////////////////////////////////////////////
void Fraction::print() const
{
	printf("%d/%d", m_numerator, m_denomenator);
}

int Fraction::getNumerator() const
{
	return m_numerator;
}

int Fraction::getDenomenator() const 
{
	return m_denomenator;
}
void Fraction::setNumerator(int value)
{
	m_numerator = value;
}
void Fraction::setDenomenator(int value)
{
	m_denomenator = value;
}
