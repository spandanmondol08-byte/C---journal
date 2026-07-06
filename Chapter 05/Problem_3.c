// Write a function to convert Celsius temperature into Fahrenheit.

#include <stdio.h>

float temp_con(float c)
{
  float f = (c * 9 / 5) + 32;
  return f;
}

int main()
{
  float c;
  printf("Enter the celsius temperature : ");
  scanf("%f", &c);
  float x = temp_con(c);
  printf("The farenhite temperature is : %.2f", x);

  return 0;
}