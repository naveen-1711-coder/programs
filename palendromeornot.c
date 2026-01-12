//print whether the given number is palendrome or not

#include <stdio.h>

void main()
{
int number,reverseofnumber=0,remainder;
printf("Enter the number to check whether it is palendrome or not :\n");
scanf("%d",&number);
int temporary_number=number;
while (temporary_number!=0)
{
	remainder= temporary_number%10;
	reverseofnumber=remainder*10+reverseofnumber;
	temporary_number=temporary/10;	
}
printf("%d is",number);
if(number==reverseofnumber)
{
	printf(" ");
}
else
{
  printf(" not ");

}
printf("a palendrome number");
}