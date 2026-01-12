//reading characters and printing numeric values for it

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int size = 8;
    char text[size];
    printf("Enter four characters : ");
    fgets(text, sizeof(text), stdin);
    // int counter,value;
    int value = *(int*)text;
    // char* character = (char*)&value;

    // for (counter = 0; counter < size; counter++)
    // {
    // 	character[counter] = text[counter];
    // }

    printf("value of given text is %d ", value);
    
}