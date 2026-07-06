/*
Create an array of 10 numbers. Verify using pointer arithmetic that (ptr+2) points
to the third element where ptr is a pointer pointing to the first element of the
array.
*/

#include <stdio.h>

int main()
{
  int a[10];
  for (int i = 0; i < 10; i = i + 1)
  {
    printf("Enter the %d value :", i + 1);
    scanf("%d", &a[i]);
  }
  int *ptr = a;
  printf("The third element is : %d\n", a[2]);
  printf("The third value using ptr+2 : %d", *(ptr + 2));

  return 0;
}