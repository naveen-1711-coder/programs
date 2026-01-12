//to print the series : 1,4,27.........upto n terms

#include<stdio.h>
#include<math.h>

void main()
{
    int count,counter,result;
    printf("printinf the series : 1,4,27.....upto n terms\n");
    printf("Enter how many terms you want to print\n");
    scanf("%d",&count);
    for(counter=1;counter<=count;counter++)
    {
        result=pow(counter,counter);
        printf("%d",result);
        if(counter<count)
        {
            printf(",");

        }
        else
        {
            printf(".");
        }
    }
}