// fgetc() and fputc()

#include <stdio.h>

int main() {
  FILE *ptr;
  ptr=fopen("file5.txt","r");
  char ch = fgetc(ptr);
  printf("The cahracter is : %c\n",ch);
  fclose(ptr);

  return 0;
}