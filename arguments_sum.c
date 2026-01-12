//print the sum of all arguments

#include <stdio.h>
#include <stdlib.h>

int main(int argCount, char* argList[])
{
	int counter;

 	printf("Printing the sum of given %d arguments is ", argcount - 1);
 
 	int sum = 0;

 	for (counter = 1; counter < argCount; counter++)
 	{	
 		sum += atoi(argList[counter]);
 	}
	printf("%d",sum);
	return 0;
}