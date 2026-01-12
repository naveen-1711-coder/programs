//print n to the powerof n

#include<stdio.h>
#include<math.h>

void main()
{
    int number,result;
    printf("printing n to the power of n\n");
    printf("Enter the number for n:\n");
    scanf("%d",&number);
    result=pow(number,number);
    printf("%dto the power of %d is %d",number,number,result);
}