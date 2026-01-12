//print biggest and smallest number among n given numbers

#include<stdio.h>

void main()
{
    int number,count,counter,biggest_number,smallest_number;
    printf("Enter how many number you want to check to print biggest and smallest number :\n");
    scanf("%d",&count);
    for(counter=1;counter<=count;counter++)
    {
        printf("Enter the number %d of %d :\n",counter,count);
        scanf("%d",&number);
        if(counter==1||biggest_number<number)
        {
            biggest_number=number;

        }
        if(counter==1||smallest_number>number)
        {
            smallest_number=number;

        }
    }
    printf("The biggest number among the given %d numbers is %d\n",count,biggest_number);
     printf("The smallest number among the given %d numbers is %d\n",count,smallest_number);
}