#include <stdio.h>

int main()
{
  FILE *ptr;
  ptr = fopen("file4.txt", "a");
  int num = 750435236;
  fprintf(ptr, "%d", num);
  fclose(ptr);
  printf("Done!!");

  return 0;
}