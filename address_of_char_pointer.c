// to print the address of char pointer

#include <stdio.h>
#include <stdlib.h>

void main()
{
	char *ptrcity1 = "vizag";
	char *ptrcity2 = "vizag";
	int choice;

	printf("Address of city1 %s is %u\n", ptrcity1, ptrcity1);
	printf("Address of city2 %s is %u\n", ptrcity2, ptrcity2);
	scanf("%d", &choice);
}