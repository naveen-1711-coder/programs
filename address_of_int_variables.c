//print addresses of 2 int variables

#include <stdio.h>

void main()
{
	int number_1 = 10, number_2 = 20;
	printf("Address of number_1 is %u\n", &number_1);
	printf("Address of number_2 is %u\n", &number_2);
	scanf("%d", &number_1);
}