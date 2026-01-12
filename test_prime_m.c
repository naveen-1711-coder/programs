// test program to test prime function

#include <stdio.h>
#include "is_prime.c"
#define FAILED "%d is failed\n"

int main()
{
	int test_numbers[] = {0, 1, 2, 999, 1777, 1899, -78}, count;
	int expected_values[] = {0, 0, 1, 0, 1, 0, 0}, failed_count = 0, counter;

	count = sizeof(test_numbers) / sizeof(test_numbers[0]);

	for (counter = 0; counter < count; counter++)
	{
		if (isprime(test_numbers[counter]) != expected_values[counter])
		{
			printf(FAILED, test_numbers[counter]);
			failed_count++;
		}
	}

	if (failed_count == 0)
	{
		printf("All test cases are passed\n");
	}
}
	