// fgetc() and fputc()

#include <stdio.h>

int main() {
  FILE *ptr;
  ptr=fopen("file5.txt","a");
  char ch = fputc('Y',ptr);
  printf("Done!!");
  fclose(ptr);

  return 0;
}