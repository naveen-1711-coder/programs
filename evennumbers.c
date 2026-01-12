//print first n even numbers 

#include<stdio.h>

void main()
{
int count,number=2;
printf("Enter how many even numbers you want to print :\n");
scanf("%d",&count);

printf("The first %d even numbers are ;\n",count);
while(number<=count*2)
{
    printf("%d\n",number);
    number+=2;
}
}