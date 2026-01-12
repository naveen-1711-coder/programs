//print counts of even and odd numbers among n given numbers

#include<stdio.h>

void main()
{
    int count,number,even_number_counter=0,odd_number_counter=0;
    printf("printing the count of even and odd numbers among n given numbers \n");
    printf("Enter the number for n :\n");
    scanf("%d",&count);

    for(int counter=1;counter<=count;counter++)
    {
        printf("Enter the number %d of %d :\n",counter,count);
        scanf("%d",&number);
        if(number%2==0)
        {
            even_number_counter++;

        }
        else{
            odd_number_counter++;
        }
    }
    printf("There are %d even numbers and %d odd numbers in the given %d numbers",even_number_counter,odd_number_counter,count);

}