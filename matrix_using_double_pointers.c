// program to create and print a 2D matrix using double pointers.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int rows_count = 0, columns_count = 0;
	int **matrix;

	printf("Enter the number of rows you want for matrix: ");
	scanf("%d", &rows_count);
	printf("Enter the number of columns you want for matrix: ");
	scanf("%d", &columns_count);

	matrix = (int**)malloc(rows_count * sizeof(int*));
	int rows_counter, columns_counter;

	for (rows_counter = 0; rows_counter < rows_count; rows_counter++)
	{
		matrix[rows_counter] = (int*)malloc(columns_count * sizeof(int));

		for (columns_counter = 0; columns_counter < columns_count; columns_counter++)
		{
			printf("Enter the number of row %d column %d: ", rows_counter + 1, columns_counter + 1);
			scanf("%d", &matrix[rows_counter][columns_counter]);
		}
	}

	printf("\n2D Matrix:\n\n");

	for (rows_counter = 0; rows_counter < rows_count; rows_counter++)
	{
		for (columns_counter = 0; columns_counter < columns_count; columns_counter++)
		{
			printf("%d ", matrix[rows_counter][columns_counter]);
		}
		printf("\n");
	}

	for (rows_counter = 0; rows_counter < rows_count; rows_counter)
	{
		free(&matrix[rows_counter]);
	}
	free(matrix);
}