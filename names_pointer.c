#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, counter;
    int length = 30;

    printf("Enter how many names you want to read and print:\n");
    scanf("%d", &count);

    char *names = malloc(count * length * sizeof(char));

    for (counter = 0; counter < count; counter++) {
        printf("Enter name %d of %d:\n", counter + 1, count);
        while(getchar()!='\n');
        scanf("%29[^\n]", names + counter * length);
    }

    for (counter = 0; counter < count; counter++) {
        printf("Name %d of %d: %s\n",counter + 1, count,names + counter * length);
    }

    free(names);
    return 0;
}
