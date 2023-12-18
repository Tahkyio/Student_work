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
	//с потоковыми это было бы намного проще выводить--
	second.output();
	cout << '\n';
	second.input();
	second.output();
	cout << '\n';
	BoolVector third = second;
	third.output();
	cout <<" Size:" << third.getSize() << '\n';

	first.invert();
	first.output();
	cout << '\n';
	first.invertByIndex(3);
	first.output();
	cout <<" Weight:"<< first.getWeight() << '\n';
	first.set(5, 0);
	cout << "Stream output! " << first << "\nStream input test: ";
	cin >> second;
	cout << second;
	return 0;
}