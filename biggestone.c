//print biggest number among given numbers without asking count

#include<stdio.h>

void main()
{
    int number,biggest_number,choice,counter=1;
    printf("printing the biggest among n given numbers\n");
    do{
        printf("Enter a number :\n");
        scanf("%d",&number);
        if(counter==1||biggest_number<number)
        {
            biggest_number=number;
        }
        counter++;
        printf("Do you want to continue? Enter 1 for yes,0 for no :\n");
        scanf("%d",&choice);
    }while(choice==1);
    printf("The biggest number among the given %d numbers is %d",counter-1,biggest_number);
    
}