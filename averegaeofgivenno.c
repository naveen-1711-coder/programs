//print average of given numbers

#include<stdio.h>

void main()
{
    int count,counter,number,result=0;
    float average;
    printf("Enter how many numbers you want to average :\n");
    scanf("%d",&count);
    for(counter=1;counter<=count;counter++)
    {
        printf("Enter the number %d of %d :\n");
        scanf("%d",&number);
        result+=number;

    }
    average=result/count;
    printf("The average of given %d numbers is %f",count,average);
    
}