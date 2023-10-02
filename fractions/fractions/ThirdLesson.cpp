#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Fraction.h"

using std::cout;


int main()
{
	Fraction a(1,2), b(3,5),c(20,33),o(0,10),m(1,5),bb(30,50),oo(0,11);
	/*ñout << "a = "; a.print();
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
	//o.reduce();
	o.print();
	cout << "\n";
	o.setDenomenator(0);
	o.print();
	cout << "\n";*/
	cout << "a > b?\n";
	if (a > b) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "a < b?\n";
	if (a < b) cout << "Yay\n";
	else cout << "Nay\n";


	cout << "a >= o?\n";
	if (a >= o) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "b <= bb?\n";
	if (a <=o ) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "b >= bb?\n";
	if (b >= bb) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "b <= bb?\n";
	if (b <= bb) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "b > bb?\n";
	if (b > bb) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "b < bb?\n";
	if (b < bb) cout << "Yay\n";
	else cout << "Nay\n";

	cout << "b == bb?\n";
	if (b == bb) cout << "Yay\n";
	else cout << "Nay\n";

}
