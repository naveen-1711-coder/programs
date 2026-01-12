//print n multpiples of k

#include<stdio.h>

void main()
{
    int number,count,counter,result=0;
    printf("printing n miltiples of k\n");
    printf("Enter the number for k :\n");
    scanf("%d",&number);
    printf("Enter the number for n:\n");
    scanf("%d",&count);
   printf("The %d multiples of %d are \n",count,number);
   for(counter=1;counter<=count;counter++)
   {
    result=number*counter;
    printf("%d\n",result);
   } 
}