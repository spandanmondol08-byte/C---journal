// int / int

#include <stdio.h>

int main()
{
  int a1 = 14;
  int b1 = 4;
  float c1 = a1 / b1;
  printf("The value of c1 is : %f\n", c1);

// int / float

  int a2 = 14;
  float b2 = 4.0;
  float c2 = a2 / b2;
  printf("The value of c2 is : %f\n", c2);

// float / float

  float a3 = 14.0;
  float b3 = 4.0;
  float c3 = a3 / b3;
  printf("The value of c3 is : %f\n", c3);

  return 0;
}