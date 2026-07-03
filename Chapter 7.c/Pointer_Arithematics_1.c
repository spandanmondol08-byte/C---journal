#include <stdio.h>

int main()
{
  int a = 5;
  int *ptr = &a;
  printf("The address is : %u\n", ptr);
  ptr++; // +4 as integer architecture
  printf("The new address is : %u\n", ptr);

  return 0;
}