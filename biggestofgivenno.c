//print biggest number among given numbers

#include<stdio.h>

void main()
{
    int count,number, counter,biggest_number;
    printf("Enter how many numbers you want to check to print biggest number :\n");
    scanf("%d",&count);
    for(counter=1;counter<=count;counter++)
    {
        printf("Enter the number %d of %d :\n",counter,count);
        scanf("%d",&number);
        if(counter==1||number>biggest_number)
        {
            biggest_number=number;
        }
    }
    printf("The bigest number among the given %d numbers is %d",count,biggest_number);

}
