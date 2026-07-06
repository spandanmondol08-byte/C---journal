/*
Write a program containing a function which reverses the array passed to it.
*/
#include <stdio.h>

int main()
{
  int n;
  printf("Enter the length of array you want : ");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i = i + 1)
  {
    printf("Enter the element %d of array : ", i + 1);
    scanf("%d", &a[i]);
  }
  int b[n];
  for (int i = 0; i < n; i = i + 1)
  {
    b[i] = a[i];
  }
  for (int i = n - 1; i >= 0; i = i - 1)
  {
    a[i] = b[n-i-1];
  }

  for (int i = 0; i < n; i = i + 1)
  {
    printf("The element %d of array is : %d\n", i + 1, a[i]);
  }

  return 0;
}