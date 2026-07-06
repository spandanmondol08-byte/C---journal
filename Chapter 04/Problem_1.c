/* Write a program to print ‘n’ natural numbers in reverse order. */

#include <stdio.h>

int main()
{
  int n;
  printf("Enter the no. of natural numbers you want in reverse: ");
  scanf("%d", &n);
  for (int i = n; i > 0; i = i - 1)
  {
    printf("%d\n", i);
  }

  return 0;
}