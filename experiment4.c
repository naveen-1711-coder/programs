// printing the bytes of integer

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int price = 1986095202,counter;
	int size = 8;
	printf("%u\n",&price);
	char* s_price = (char*)&price; 

	for (counter = 0; counter < size; counter++)
	{
		printf("%c  - %d\n", s_price[counter], s_price[counter]);
	}
}