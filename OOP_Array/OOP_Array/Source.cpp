#include <iostream>
#include <stdio.h>
#include "Array.h"

int main()
{
	Array arr(20,3);
	arr.print();
	Array brr = arr; 		
	brr.print();
	return 0;
}