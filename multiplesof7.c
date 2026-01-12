//print n multiples of 7

#include<stdio.h>

void main()
{
    int count,result=0,counter=1;
    printf("Enter how many multiples of 7 you want to sum :\n");
        scanf("%d",&count);
        while(counter<=count)
    {
        result+=counter*7;
        counter++;
    }
        printf("The sum of %d multiples of 7 is %d",count,result);
}