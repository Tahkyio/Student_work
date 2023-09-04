#include <stdio.h>
#include <iostream>
#include "Fraction.h"


Fraction Fraction::Sum(const Fraction b)
{
	Fraction c;
	c.numerator = numerator*b.denomenator + b.numerator*denomenator;
	c.denomenator = denomenator*b.denomenator;
	return c;
}

void Fraction::print_F()
{
	printf("%d/%d", numerator, denomenator);
}