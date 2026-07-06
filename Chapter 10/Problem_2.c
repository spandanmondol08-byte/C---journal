// Write a program to read three integers from a file.

#include <stdio.h>

int main()
{
  FILE *ptr;
  ptr = fopen("fp1.txt", "r");
  int num;
  for (int i = 0; i < 3; i++)
  {
    fscanf(ptr, "%d", &num);
    printf("The integer is : %d\n", num);
  }
  fclose(ptr);
  return 0;
}