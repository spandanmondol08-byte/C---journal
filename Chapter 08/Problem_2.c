// Write your own version of strlen function from <string.h>

#include <stdio.h>

int main()
{
  char str[30];
  printf("Enter the string : ");
  gets(str);
  int len = 0;
  for (int i = 0; str[i] != 0; i++)
  {
    len++;
  }
  printf("The lenght of the string is : %d", len);
  return 0;
}