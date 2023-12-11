#include <iostream>
#include <stdio.h>
#include "BoolVector.h"
using std::cout;
using std::cin;
int main()
{
	BoolVector first;
	first.output();
	cout << '\n';
	BoolVector second(23);
	second.output();
	cout << '\n';
	second.input();
	second.output();
	cout << '\n';
	BoolVector third = second;
	third.output();
	cout <<'\n';

	first.invert();
	first.output();
	cout << '\n';
	first.invertByIndex(3);
	first.output();
	cout << '\n';
	return 0;
}