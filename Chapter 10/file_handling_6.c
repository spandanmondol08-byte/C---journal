// Reading file character by character

#include <stdio.h>

int main() {
  FILE *ptr;
  ptr=fopen("file5.txt","r");
  while(1)
  {
    char ch=fgetc(ptr);
    if (ch==EOF)
    {
      break;
      fclose(ptr);
    }
    else
    {
      printf("%c",ch);
    }

  }
 
  return 0;
}