// First_lesson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Fraction.h"




void not_main()
{


	Fraction a, b, c;
	a.numerator = 1;
	a.denomenator = 3;
	b.numerator = 2;
	b.denomenator = 5;

	c = a.getSum(b);
	c.print(); printf("\n");
	c = a.getDiff(b);
	c.print(); printf("\n");
	c = a.getMult(b);
	c.print(); printf("\n");
	c = a.getDiv(b);
	c.print(); printf("\n");
	_getch();
}



