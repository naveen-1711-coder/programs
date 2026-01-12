#include <stdio.h>

int main() {
    FILE *fp;
    char str[100];
    char ch;

    /* -------- Writing to file -------- */
    fp = fopen("demo.txt", "w");   // open file in write mode

    fprintf(fp, "This line is written using fprintf.\n");
    fputs("This line is written using fputs.\n", fp);
    fputc('A', fp);   // write a single character
    fputc('\n', fp);

    fclose(fp);   // close file after writing

    /* -------- Reading from file -------- */
    fp = fopen("demo.txt", "r");   // open file in read mode

    printf("Reading using fscanf:\n");
    fscanf(fp, "%s", str);         // reads first word
    printf("%s\n\n", str);

    printf("Reading using fgetc (character by character):\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);   // close file after reading

    return 0;
}
