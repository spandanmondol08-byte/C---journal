// Write a program to calculate the factorial of a given number using a for loop.

#include <stdio.h>

int main()
{
  printf("-------------------------------Program to calculate the factorial--------------------------\n");
  int n;
  printf("Enter the Number : ");
  scanf("%d", &n);
  int f = 1;
  for (int i = 1; i < n + 1; i = i + 1)
  {
    f = f * i;
  }
  printf("The Factoriol of the number is: %d\n", f);

  return 0;
}