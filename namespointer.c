//to read and print n names using pointer to pointer

#include <stdio.h>
#include <stdlib.h>

int main() {
    int number_of_names,counter;
    printf("Enter the number of names: ");
    scanf("%d", &number_of_names);
    char **names = (char **)malloc(number_of_names * sizeof(char*));
    for (counter = 0; counter < number_of_names; counter++) 
    {
        names[counter] = (char *)malloc(100 * sizeof(char));
        printf("Enter name %d: ", counter + 1);
        scanf(" %s", names[counter]); 
    }
    printf("\nEntered names are:\n");
    for (counter = 0; counter < number_of_names; counter++) {
        printf("%s\n", names[counter]);
    }
    for(counter = 0; counter < number_of_names; counter++) {
        free(names[counter]);
    }
    free(names); 

    return 0;
}
