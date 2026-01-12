//practising file functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size = 100;
    char text[100];
    FILE *fptext;

    
    printf("Enter text: ");
    fgets(text, size, stdin);

    fptext = fopen("text.txt", "a");

    fputc('A', fptext);
    fputs(text, fptext);             
    fclose(fptext);

    fptext = fopen("text.txt", "r");

    char ch;
    printf("\nFile content (character by character):\n");
    while ((ch = fgetc(fptext)) != EOF)
    {
        putchar(ch);
    }
    fclose(fptext);

    
    fptext = fopen("text.txt", "r");

    char line[100];
    printf("\n\nFile content (line by line):\n");
    while (fgets(line, size, fptext))
    {
        printf("%s", line);
    }
    fclose(fptext);

    return 0;
}
