// reading names from a file and saving that names into a file in alphabatical order

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#include "mytools.c"

int get_names_count(char *);

void main()
{
	char* names_file = "names.txt";
	FILE* fp_names;
	int names_count = get_names_count(names_file);
	char **names = (char**)malloc(names_count * sizeof(char*));
	int names_counter, iteration_counter, counter;
	char *temp;

	fp_names = fopen(names_file, "r");

	for (names_counter = 0; names_counter < names_count; names_counter++)
	{
		names[names_counter] = (char*)malloc(SIZE);
		fgets(names[names_counter], SIZE, fp_names);
		removenewline(names[names_counter]);
	}
	fclose(fp_names);

	int iteration_count = names_count - 1;
	for (iteration_counter = 0; iteration_counter < iteration_count; iteration_counter++)
	{
		for (counter = 0; counter < iteration_count - iteration_counter; counter++)
		{
			if (strcmp(names[counter], names[counter + 1]) > 0)
			{
				temp = names[counter];
				names[counter] = names[counter + 1];
				names[counter + 1] = temp;
			}
		}
	}

	fp_names = fopen("sorted_names.txt", "a");

	for (names_counter = 0; names_counter < names_count; names_counter++)
	{
		fputs(names[names_counter], fp_names);

		if (names_counter < names_count - 1)
		{
			fputc('\n', fp_names);
		}
	}
	fclose(fp_names);
}

int get_names_count(char *filename)
{
    FILE *fp_names;
    int count = 0;
    char buffer[SIZE];

    fp_names = fopen(filename, "r");

    while (fgets(buffer, sizeof(buffer), fp_names) != NULL)
    {
        count++;
    }

    fclose(fp_names);
    return count;
}
