//print average of given numbers without asking count

#include<stdio.h>

void main()
{
    int number, result = 0, choice, counter = 1;
    printf("printing the average of n given numbers\n");
    do{
        printf("Enter a number :\n");
        scanf("%d", &number);
        result += number;
        counter++;
        printf("Do you want to continue? Enter 1 for yes,0 for no :\n");
        scanf("%d", &choice);
    }while(choice == 1);
    float average;
    average = result / (counter-1);
    printf("The average of the given numbers is %f",average);
}