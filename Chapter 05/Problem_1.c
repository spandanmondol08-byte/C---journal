// Use the library function to calculate the area of a square with side a.

#include <stdio.h>
#include <math.h>

int main()
{
  int a;
  printf("Enter the lenght of a side of square : ");
  scanf("%d", &a);
  printf("The area of the square is : %f", pow(a, 2));

  return 0;
}