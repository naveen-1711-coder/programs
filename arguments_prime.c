//print whether the given numbers is prime or not 

#include <stdio.h>
#include <stdlib.h>

int isprime(int);

int main(int argCount, char *argList[])
{
    printf("Checking prime numbers:\n\n");
    int counter;
    

    printf("\nPrime numbers are: ");

    for (counter = 1; counter < argCount; counter++) 
    {
        int number = atoi(argList[counter]);
        if (isprime(number))
            printf("%d ", number);
    }

    printf("\nNon-prime numbers are: ");

    for (counter = 1; counter < argCount; counter++) 
    {
        int number = atoi(argList[counter]);
        if (!isprime(number))
            printf("%d ", number);
    }

    printf("\n");
    return 0;
}

