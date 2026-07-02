// Write a program using function to find average of three numbers.

#include <stdio.h>

float avg(float a, float b, float c)
{
  float x = (a + b + c) / 3;
  return x;
}

int main()
{
  while (1)
  {
    float a, b, c;
    printf("Enter the first number : ");
    scanf("%f", &a);
    printf("Enter the second number : ");
    scanf("%f", &b);
    printf("Enter the third number : ");
    scanf("%f", &c);
    float y = avg(a, b, c);
    printf("There average : %f\n", y);
  }

  return 0;
}