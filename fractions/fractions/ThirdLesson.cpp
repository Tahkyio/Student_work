#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Fraction.h"

using std::cout;


int main()
{
	Fraction a(1,2), b(3,5),c(20,33);
	cout << "a = "; a.print();
	cout << "\na+=b: ";
	a += b;
	a.print();

	cout << "\na-=b: ";
	a -= b;
	a.print();
	cout << "\na.reduce(): ";
	a.reduce();
	a.print();
	cout << "\n\nc= ";
	c.print();
	cout << "\n\na= ";
	a.print();
	cout << "\nc/=a: ";
	c /= a;
	c.print();
	cout << "\nc*=a: ";
	c *= a;
	c.print();
	cout << "\n";
}
