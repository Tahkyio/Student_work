#include <iostream>
#include <stdio.h>
#include "Array.h"

int main()
{	srand(time(NULL));

	Array arr(20,3);
	arr.print();
	Array brr = arr; 		
	brr.print();
	Array crr(20, 3);
	//проверка заполнения случайными числами
	brr.fillRand(0, 100);
	arr.fillRand(100, 1000);
	crr.fillRand(0, 100);
	brr.print();
	arr.print();
	crr.print();
	//проверка сортировки
	arr.sort();
	arr.print();
	//проверка функций remove
	arr.fillRand(0, 10);
	brr.fillRand(0, 10);
	arr.print();
	if(arr.removeByIndex(3))
		arr.print();
	brr.print();
	if (brr.removeByValue(3))
		brr.print();

	std::cout << "\narr="; arr.print();
	std::cout << "brr="; brr.print();
	brr = arr;
	std::cout << "brr="; brr.print();

	arr = brr = crr;

	std::cout << "\narr="; arr.print();
	std::cout << "brr="; brr.print();
	std::cout << "crr="; crr.print();
	return 0;
}