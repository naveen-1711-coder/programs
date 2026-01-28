#include <stdio.h>
#include <stdlib.h>
#include "print_execution_time.h"
#include "mytools.c"

double experiment_function();
int is_duplicate_exist(int numbers[], int number_counter);

int main() 
{
    int number_count;

    printf("Enter number of elements: ");
    scanf("%d", &number_count);

    int numbers[number_count];
    int number_counter;

    for (number_counter = 0; number_counter < number_count; number_counter++) 
    {
    	if (number_counter == 498)
    	{
    		numbers[number_counter] = 499;
    	}
    	else
    	{
        numbers[number_counter] = number_counter;
        }
    }

    int has_duplicate;
    double dummy;
    double time_taken;

    PRINT_EXECUTION_TIME(has_duplicate = is_duplicate_exist(numbers, number_count));

    PRINT_EXECUTION_TIME(dummy = experiment_function());

    double (*function_pointer)() = experiment_function;

    time_taken = get_execution_time(function_pointer);

    if (has_duplicate)
    {
        printf("Duplicate found\n");
    }
    else
    {
        printf("No duplicates\n");
    }
    printf("%f", dummy);

    printf("Execution time is %f\n", time_taken);

    return 0;
}

double experiment_function()
{
	double dummy = 0, i;
	for (i = 0; i < 10000000; i++) 
	{
        dummy = i;
    }
    return dummy;
}

int is_duplicate_exist(int numbers[], int number_count) 
{
    int found[1001] = {0};
    int number_counter;

    for (number_counter = 0; number_counter < number_count; number_counter++) 
    {
        if (found[numbers[number_counter]] == 1)
        {
            return 1;
        }
        found[numbers[number_counter]] = 1;
    }
    return 0;
}