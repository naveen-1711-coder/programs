//allocate the storage to char array

#include <stdio.h>

int main()
{
	int length = 500, counter;
	char string[length];
	for (counter = 0; counter < length; counter++)
	{
		printf("%c - %d\n", string[counter], string[counter]);
	}
}