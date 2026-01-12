//print the given name for given n number of times using commandline arguments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argCount, char *argList[])
{
	int counter, count;
	count = atoi(argList[2]);

	for (counter = 0; counter < count; counter++)
	{
		printf("%s\n", argList[1]);
	}
 
 int name_count = strlen(argList[1]);

	for (counter = 0; counter < name_count; counter++)
	{
		printf("%c\n",argList[1][counter]);
	}

	
	return 0;
}