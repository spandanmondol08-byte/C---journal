//Celcius to farenheit conversion

#include <stdio.h>

int main() {
  int c;
  printf("Enter the celcius temperature: ");
  scanf("%d",&c);
  int f= (c*9/5)+32;
  printf("The temperature in farenheit is: %d", f);

  return 0;
}