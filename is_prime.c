//function to check the number is prime or not

#include <math.h>

int isprime(int number)
{
    if (number == 2)
    {
        return 1;
    }

    if (number <= 1 || number % 2 == 0)
    {
        return 0;
    }
     
    int counter;
    int square_root_of_number = sqrt(number);

    for (counter = 3; counter <= square_root_of_number; counter += 2)
    {
        if (number % counter == 0)
        {
            return 0;
        }
    }
    
    return 1;
}