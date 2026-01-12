// print 1 to n number using single variable

#include <stdio.h>

void print_numbers(int);

void main()
{
	int number;

	printf("Enter how many numbers you want to print: ");
	scanf("%d", &number);

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