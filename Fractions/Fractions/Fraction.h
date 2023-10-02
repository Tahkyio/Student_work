#pragma once


class Fraction
{
public:
	Fraction();
	Fraction(const int numerator,const int denomenator);
	~Fraction()=default;
	
	Fraction reduce();
	Fraction getSum (const Fraction b) const;
	Fraction getDiff(const Fraction b) const;
	Fraction getMult(const Fraction b) const;
	Fraction getDiv (const Fraction b) const;

	Fraction& operator +=(const Fraction&);
	Fraction& operator -=(const Fraction&);
	Fraction& operator *=(const Fraction&);
	Fraction& operator /=(const Fraction&);
	bool operator ==(const Fraction&) const; 
	bool operator !=(const Fraction&) const;
	bool operator  >(const Fraction&) const;
	bool operator  <(const Fraction&) const;
	bool operator >=(const Fraction&) const;
	bool operator <=(const Fraction&) const;


	void print() const;
	int  getNumerator()const;
	int  getDenomenator()const;
	void setNumerator(int value);
	void setDenomenator(int value);

private:
	int m_numerator=1;
	int m_denomenator=1;

};

