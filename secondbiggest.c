//print second biggest number among n given numbers

#include<stdio.h>

void main()
{
    int count,counter,biggest_number,second_biggest_number,number;
    printf("printing the second biggest number among n given numbers \n");
    printf("Enter the number for n:\n");
    scanf("%d",&count);
    for(counter=1;counter<=count;counter++);
    {
        printf("Enter the number %d of %d :\n",counter,count);
        if(counter==1)
        {
            biggest_number=number;
            second_biggest_number=number;
        }
        if(number>biggest_number)
        {
            second_biggest_number=biggest_number;
            biggest_number=number;
        }
        if((number<biggest_number&&number>second_biggest_number)||(counter==2&&number<biggest_number))
        {
            second_biggest_number=number;
        }
    }
    printf("The second biggest number among the given %d numbers is %d",count,second_biggest_number);
}