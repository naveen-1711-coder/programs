//print p to teh power of Q

#include<stdio.h>

void main()
{
    int number,count,result;
    printf("printing p to the power of Q\n");
    printf("Enter the number for p :\n");
    scanf("%d",&number);
    printf("Enter the number for Q :\n");
    scanf("%d",&count);
    result=pow(number,count);

    printf("%d to the power of %d is %d",number,count,result);
}