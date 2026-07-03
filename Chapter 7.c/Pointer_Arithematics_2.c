// Printing the array values using the pointer arithematics (ptr++)

#include <stdio.h>

int main()
{
  int marks[5] = {23, 34, 33, 43, 44};
  int *ptr = &marks[0];
  for (int i = 0; i < 5; i = i + 1)
  {
    printf("The value a index %d is : %d\n", i, *ptr);
    ptr = ptr + 1; // Pointer Arithematics
  }

  return 0;
}