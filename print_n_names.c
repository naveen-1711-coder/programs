// read n names in function and print n names in main

#include <stdio.h>
#include <stdlib.h>
#include "mytools.c"

void** read_n_names()
{
	int size = 20;
	int *names_count = malloc(sizeof(int));
	printf("Enter how many names you want to read and print: ");
	scanf("%d", names_count);
	clear_input_buffer();
	char** names = malloc(*names_count * sizeof(char*));
	int counter;
	for (counter = 0; counter < *names_count; counter++)
	{
		names[counter] = malloc(size);
		printf("Enter name %d of %d: ", counter + 1, *names_count);
		scanf("%19[^\n]", names[counter]);
		clear_input_buffer();
	}
	printf("\n");
	void** address_list = malloc(2 * sizeof(void *));
	address_list[0] = names;
	address_list[1] = names_count;
	return address_list;
}

void main()
{
	void** address_list = read_n_names();
	int *names_count = (int*)address_list[1];
	char **names = (char**)address_list[0];
	int counter;
	for (counter = 0; counter < *names_count; counter++)
	{
		printf("The name of %d of %d is %s\n", counter + 1, *names_count, names[counter]);
	}

}