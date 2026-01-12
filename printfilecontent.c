//printing the contents of a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char* filename = "countevenandodd.c";
	int size = 100;
	char character;
	FILE* fptext;
	printf("Printing the contents of the file \n\n");

	fptext = fopen(filename, "r"); 

	while((character = fgetc(fptext)) != EOF)
	{
		putchar(character);
	}

	 printf("using fwrite\n\n\n");
	fseek(fptext, 0, SEEK_END);
	size = ftell(fptext);
	fseek(fptext, 0, SEEK_SET);
	int counter=0;
	char filecontent;
	
// int counter;
	while(fread(&filecontent, 1, 1, fptext) == 1)
	{
	if(filecontent == 'a')
	{
	 counter++;
	}
	}printf("%d",counter);
	fclose(fptext);


}