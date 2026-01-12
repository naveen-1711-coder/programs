//print multiplication table of a given number

#include<stdio.h>

void main()
{
    int number,count,counter,result=1;
    printf("Enter the number for which you want to print its multiplication table : \n");
    scanf("%d",&number);
    printf("Enter how many multiples of %d you want to print : \n",number);
    scanf("%d",&count);
    printf("The multiplication table of given number %d is :\n",number);
    for(counter=1;counter<=count;counter++)
    {
        result=number*counter;
        printf("%dx%d=%d\n",number,counter,result);
    }
}