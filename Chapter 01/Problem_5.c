// Calculation of simple interest

#include <stdio.h>

int main()
{
  int p, r, t;
  printf("Enter principle amount: ");
  scanf("%d", &p);
  printf("Enter Rate of Interest: ");
  scanf("%d", &r);
  printf("Enter time in years: ");
  scanf("%d", &t);
  float si = (p * r * t) / 100;
  printf("The simple interest is: %f", si);

  return 0;
}