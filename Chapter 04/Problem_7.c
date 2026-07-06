// Write a program to calculate the factorial of a given number using a While loop.

#include <stdio.h>

int main()
{
  printf("-------------------------------Program to calculate the factorial--------------------------\n");
  int n;
  printf("Enter the Number : ");
  scanf("%d", &n);
  int f = 1;
  int i = 1;
  while (i < n + 1)
  {
    f = f * i;
    i = i + 1;
  }

  printf("The Factoriol of the number is: %d\n", f);

  return 0;
}