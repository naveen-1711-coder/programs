//print sum of n even numbers

#include<stdio.h>
#include<conio.h>

void main()
{
    int count,number=2,total=0;
    int marks;
    printf("Enter how many even numbers you want to sum :\n");
    scanf("%d",&count);
    printf("%d", marks);
    while(number<=count*2)
    {
        total+=number;
        number+=2;
    }
    printf("The sum of %d even numbers is %d ",count,total);
}