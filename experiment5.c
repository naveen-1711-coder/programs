//reading characters and printing numeric values for it

#include <stdio.h>
#include <stdlib.h>

void main()
{
    char text[5];
    int value = 20;
    itoa(value, text, 10);
    printf("%s", text);    
}