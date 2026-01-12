//print 1 to n using one varibale with command line arguments

#include <stdio.h>

void print_numbers(int);

void main(int argcount, char* argList[])
{
	int number;
	number = atoi(argList[1]);

	print_numbers(number);
}

void print_numbers(int number)
{
	if (number == 0)
	{
		return;
	}

	print_numbers(number - 1);
	printf("%d\n", number);
}