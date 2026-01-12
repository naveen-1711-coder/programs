//read print bigger one among given two numbers

#include<stdio.h>

void main()
{
    int first_number,second_number;
    printf("printing the bigger one among the given two numbers\n");
    printf("Enter the first number :\n");
    scanf("%d",&first_number);
    printf("Enter the second number :\n");
    scanf("%d",&second_number);
    if(first_number<second_number)
    {
        first_number=first_number+second_number;
        second_number=first_number-second_number;
        first_number=first_number-second_number;
    }
    printf("%d is bigger than %d",first_number,second_number);

}