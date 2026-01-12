//a menu shown to the user showing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "hi.c"

FILE *fptext;
char* filename = "userfile.txt";
int size = 100;

int add_name();
int read_file();
int delete_names();

int main()
{
	int choice;
    
	do
	{
	printf("1.Save a name \n2.Show all names\n3.clear all names in file\n4.EXIT\n\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
	case 1 :
		add_name();
		break;

	case 2 :
		read_file();
		break;

	case 3 :
		delete_names();
		break;

	case 4 :
		exit(0);

	default :
		printf("You entered wrong choice ");
		break;

	}
	}while(1);

	return 0;
}

int add_name()
{
	char name[size];

	printf("Enter a name : ");
	// getchar();
	fflush(stdin);
	fgets(name, size, stdin);
	printf("\n");

	fptext = fopen(filename, "a");
	fputs(name, fptext);
	fclose(fptext);

	return 0;
}

int read_file()
{
	char character;
	printf("\n");
	
	fptext = fopen(filename, "r");
	char* line = malloc(size);

    while (fgets(line, size, fptext) != NULL) 
    {
        printf("%s", line);
    }
	fclose(fptext);
    printf("\n");
    return 0;
    
}

int delete_names()
{
 
 fptext = fopen(filename, "w");
 fclose(fptext);
 return 0;

}