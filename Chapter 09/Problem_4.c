// Write a program with a structure representing a complex number

#include <stdio.h>
typedef struct complex
{
  int re;
  int im;
} cn;

int main()
{
  cn c1;
  c1.re = 4;
  c1.im = -3;

  printf("The complex number is : %d + %d i", c1.re, c1.im);
  return 0;
}