#include <stdio.h>

int main()
{
  char str[7];
  printf("Enter the string : ");
  scanf("%s", str); // & is not required
  printf("The String is : %s", str);

  return 0;
}