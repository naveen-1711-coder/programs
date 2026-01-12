#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[100];
    int ch;

    fp = fopen("user_text.txt", "a");
    if (!fp)
        return 1;

    printf("Enter text (type END to stop):\n");

    while (1)
    {
        fgets(buffer, sizeof(buffer), stdin);

        if (buffer[0] == 'E' &&
            buffer[1] == 'N' &&
            buffer[2] == 'D')
            break;

        fputs(buffer, fp);
    }
    fclose(fp);

    fp = fopen("user_text.txt", "r");
    printf("\nTEXT MODE (r):\n");
    while ((ch = fgetc(fp)) != EOF)
        printf("%d ", ch);
    fclose(fp);

    printf("\n\n");

    fp = fopen("user_text.txt", "rb");
    printf("BINARY MODE (rb):\n");
    while ((ch = fgetc(fp)) != EOF)
        printf("%d ", ch);
    fclose(fp);

    return 0;
}
