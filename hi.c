// read and print name using fgets and remove the newline and to print underline to the given text

#include <stdio.h>
#include <string.h>

 void removenewline(char*);
void underline(char*);

int main()
{
  char name[30];
  printf("Enter a name : ");
  fgets(name,sizeof(name),stdin);
    removenewline(name);
    underline(name);
   return 0;
}

void removenewline (char* text)
{
  char* lastletter = &text[strlen(text) - 1];
  if (*lastletter == '\n')
  {
    *lastletter = '\0';
  }
}

void underline(char* text)
{
 int length = printf("%s", text) - 1;
  int counter;
  for ( counter = 0; counter < length; counter++)
  {
    if(text[counter] == ' ')
    {
        printf(" ");
    }
    else
    {
      printf("-");
    }
  }
}