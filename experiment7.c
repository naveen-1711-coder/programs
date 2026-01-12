// converting a record into double dimension array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int field_count = 3, field_value_length = 15, counter;
	char record[] = "0987654321     naveen         098765         ";
	// char **field_values;
	// field_values = (char**)malloc(field_count * sizeof(char*));
	char field_values[field_count][field_value_length];
	for (counter = 0; counter < field_count; counter++)
	{
		// field_values[counter] = (char*)malloc(field_value_length * sizeof(char));
		strcpy(field_values[counter], &record[counter * field_value_length]);
		field_values[counter][field_value_length - 1] = '\0';

	}
	// memcpy(field_values, record, sizeof(field_values));
	// field_values = (char**)record;

	for (counter = 0; counter < field_count; counter++)
	{
		printf("%s\n", field_values[counter]);
	}
}