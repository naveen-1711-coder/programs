//print the table book

#include<stdio.h>

void main()
{
    int number,count,multiple,result;
    printf("printing table book\n");
    printf("Enter how many tables you want to print\n");
    scanf("%d",&count);
    printf("Enter how many multiples you want to print :\n");
    scanf("%d",&multiple);
    printf("      TABLE BOOK\n");
    for(number=1;number<=count;number++)
    {
        for(result=1;result<=multiple;result++)
        {
            printf("%d x %d = %d\n",number,result,number*result);

        }
    }
}