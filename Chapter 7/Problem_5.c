/*
Write a program containing functions which counts the number of positive
integers in an array.
*/
#include <stdio.h>

int main() {
  int count = 0;
  int n;
  printf("Enter the length of array you want : ");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i = i + 1)
  {
    printf("Enter the element %d of array : ", i + 1);
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i = i + 1)
  {
    if (a[i] > 0)
    {
      count++;
    }
  }
  printf("The number of positive integers in the array is : %d\n", count);
  return 0;

}