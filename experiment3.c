// to test the pointers

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int length = 4,counter;
	int *ptr_int = (int*)malloc(length * sizeof(int));
	char *ptr_char = (char*)malloc(length * sizeof(char));
    
    for (counter = 0;counter < length; counter++)
    {   
    printf("%u\n",ptr_int + counter);
    }

    for (counter = 0;counter < length; counter++)
    {
    printf("%u\n",ptr_char + counter);
    }
    ptr_int+1;
    ptr_char+1;
    printf("%u\n",ptr_int);
    printf("%u\n",ptr_char);


}