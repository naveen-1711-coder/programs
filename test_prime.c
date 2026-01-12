// test program to test prime function

#include <stdio.h>
#include "is_prime.c"
#define FAILED "%d is failed\n"

void test_number(int, int);

int failed_count = 0;

int main()
{
	test_number(-37, 0);
	test_number(0, 0);
	test_number(1777, 1);
	test_number(2, 1);
	test_number(3, 1);
	test_number(67, 1);
	test_number(999, 0);
	test_number(679, 0);

	if (failed_count == 0)
	{
		printf("All test cases are passed\n");
	}

	return 0;
}

void test_number(int number, int expected_value)
{
	if (isprime(number) != expected_value)
	{
		printf(FAILED, number);
		failed_count++;
	}
}