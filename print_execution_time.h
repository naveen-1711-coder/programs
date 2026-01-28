// program to get execution time of a function

#ifndef PRINT_EXECUTION_TIME_H
#define PRINT_EXECUTION_TIME_H

#include <stdio.h>
#include <time.h>

#define PRINT_EXECUTION_TIME(function_name)									\
{																			\
	clock_t start_time = clock();											\
	function_name;															\
	clock_t end_Time = clock();												\
	double execution_time = (double)(end_Time - start_time) / CLOCKS_PER_SEC;\
	printf("\nThe execution time is %f\n", execution_time);					\
}

#endif