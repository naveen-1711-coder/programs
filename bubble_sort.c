// program on bubblesort using pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int numbers_count, numbers_counter, iteration_counter, counter;
	printf("Enter how many numbers you want to sort: ");
	scanf("%d", &numbers_count);

	int *number_list = (int*)malloc(numbers_count * sizeof(int));

	for (numbers_counter = 0; numbers_counter < numbers_count; numbers_counter++)
	{
		printf("Enter the number %d of %d: ", numbers_counter + 1, numbers_count);
		scanf("%d", &number_list[numbers_counter]);
	}

	int temp_value;

	for (iteration_counter = 0; iteration_counter < numbers_count - 1; iteration_counter++)
	{
		for (counter = 0; counter < numbers_count - iteration_counter - 1; counter++)
		{
			if (number_list[counter] > number_list[counter + 1])
			{
				temp_value = number_list[counter + 1];
				number_list[counter + 1] = number_list[counter];
				number_list[counter] = temp_value;
			}
		}
	}

	printf("\nAfter Sorting\n\n");

	for (numbers_counter = 0; numbers_counter < numbers_count; numbers_counter++)
	{
		printf("%d ", number_list[numbers_counter]);
	}
	free(number_list);
}