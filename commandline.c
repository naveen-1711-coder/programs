//print all commandline arguments

#include <stdio.h>
#include <string.h>

int main(int argcount, char* argList[])
{
   int counter;

   for (counter = 1; counter <= argcount; counter++)
   {
   	printf("%s\n", argList[counter]);
   }
   char name[] = "harshitha";
   printf("%d",strlen(name));
   return 0;
}