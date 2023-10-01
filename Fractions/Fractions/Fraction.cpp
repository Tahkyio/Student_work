#include <stdio.h>
#include <iostream>
#include "Fraction.h"

inline int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}
inline int min(int a, int b)
{
	if (a <= b) return a;
	else return b;
}
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
	else this->m_denomenator = m_denomenator;
	
}						//Узнать про список инициализации.
///////////////////////////////////////////////////////////////////////
//Calculations
Fraction Fraction::reduce()
{
	if (m_denomenator == 0)
	{
		std::cerr << "Error: Fraction::reduce() discovered 0 in denomenator. Result replaced with 'numerator/1'\n";
		m_denomenator = 1;
		return *this;
	}
	if(m_numerator == 0)
	{
		return *this;
	}
	if (m_denomenator % m_numerator == 0)
	{
		m_denomenator /= m_numerator;
		m_numerator   /= m_numerator;
		return *this;
	}
	else if(m_numerator % m_denomenator == 0)
	{
		m_numerator   /= m_denomenator;
		m_denomenator /= m_denomenator;
		return *this;
	}
	for (int i = min(m_denomenator, m_numerator); i > 1; i--)
	{
		if (m_denomenator % i == 0 && m_numerator % i == 0)
		{
			m_denomenator /= i;
			m_numerator   /= i;
			return *this;
		}
	}
	return *this;
}


Fraction Fraction::getSum(const Fraction b) const
{
	Fraction c;
	if (m_denomenator == b.m_denomenator)
	{
		c.m_numerator = m_numerator + b.m_numerator;
		c.m_denomenator = m_denomenator;
		return c;
	}
	c.m_numerator   = m_numerator*b.m_denomenator + b.m_numerator*m_denomenator;
	c.m_denomenator = m_denomenator*b.m_denomenator;
	return c;
}

Fraction Fraction::getDiff(const Fraction b) const
{
	Fraction c;
	if (m_denomenator == b.m_denomenator)
	{
		c.m_numerator   = m_numerator - b.m_numerator;
		c.m_denomenator = m_denomenator;
		return c;
	}
	c.m_numerator   = m_numerator * b.m_denomenator - b.m_numerator*m_denomenator;
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
	c.m_numerator   = m_numerator * b.m_numerator;
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
	c.m_numerator   = m_numerator * b.m_denomenator;
	c.m_denomenator = m_denomenator * b.m_numerator;
	return c;

}
////////////////////////////////////////////////////////////////////////
// Перегрузка операций
Fraction& Fraction::operator +=(const Fraction& fract)
{
	if (m_denomenator == fract.m_denomenator)
	{
		m_numerator = m_numerator + fract.m_numerator;
		return *this;
	}
	m_numerator   = m_numerator * fract.m_denomenator + fract.m_numerator * m_denomenator;
	m_denomenator = m_denomenator * fract.m_denomenator;
	return *this;
}
Fraction& Fraction::operator -=(const Fraction& fract)
{
	if (m_denomenator == fract.m_denomenator)
	{
		m_numerator = m_numerator - fract.m_numerator;
		return *this;
	}
	m_numerator   = m_numerator * fract.m_denomenator - fract.m_numerator * m_denomenator;
	m_denomenator = m_denomenator * fract.m_denomenator;
	return *this;
}

Fraction& Fraction::operator *=(const Fraction& fract)
{
	if (m_denomenator == 0 || fract.m_denomenator == 0) {
		std::cerr << "ERROR: Fraction::operator *= found 0 in denomenator - multiplication wasn't applied. \n";
		return *this;
	}
	m_numerator   = m_numerator * fract.m_numerator;
	m_denomenator = m_denomenator * fract.m_denomenator;
	return *this;
}
Fraction& Fraction::operator /=(const Fraction& fract)
{
	if (m_denomenator == 0 || fract.m_denomenator == 0) {
		std::cerr << "ERROR: Fraction::operator /= found 0 in denomenator - division wasn't applied. \n";
		return *this;
	}
	m_numerator   = m_numerator * fract.m_denomenator;
	m_denomenator = m_denomenator * fract.m_numerator;
	return *this;
}
///////////////////////////////////////////////////////////////////////
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
	if (value == 0)
	{
		std::cerr << "ERROR: Denomenator can't be set to 0 - it was set to 1 instead.";
		m_denomenator = 1;
	}
	m_denomenator = value;
}

