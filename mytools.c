// functions that used commonly in different programs

#include <stdio.h>
#include <string.h>

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

void clear_input_buffer()
{
  while(getchar() != '\n')
  {

  }
}

void seek_back(FILE* fp_accounts, int record_size)
{
  fseek(fp_accounts, -record_size, SEEK_CUR); 
}