#include <stdio.h>

int main()
{
  FILE *ptr;
  ptr = fopen("file3.txt", "w");
  int num = 721306;
  fprintf(ptr, "%d", num);
  fclose(ptr);
  printf("Done!!");

  return 0;
}