//print multiplication of three numbers

#include<stdio.h>

void main()
{ 
    int first_number,second_number,third_number,result;
    printf("Enter the first number : \n");
    scanf("%d",&first_number);
    printf("Enter the second number : \n");
    scanf("%d",&second_number);
    printf("Enter the third number : \n");
    scanf("%d",&third_number);
    result=first_number*second_number*third_number;
    printf("the product of %d,%d and %d is %d",first_number,second_number,third_number,result);

}
