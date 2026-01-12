//read print n names using array of pointers

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int number_of_names,counter,length=30;
    printf("Enter the number of names: ");
    scanf("%d", &number_of_names);
    char *names[number_of_names];
    for(counter = 0; counter < number_of_names; counter++) 
    {
        names[counter] = (char *)malloc(length * sizeof(char));
        printf("Enter name %d: ", counter + 1);
        scanf(" %s", names[counter]);
    }
    printf("\nEntered %d names are:\n", number_of_names);
    for(counter = 0; counter < number_of_names; counter++) {
        printf("%s\n", names[counter]);
    }   
    for(counter = 0; counter < number_of_names; counter++)
    {
        free(names[counter]);
    }
    
}