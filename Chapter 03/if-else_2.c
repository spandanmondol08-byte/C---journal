#include <stdio.h>

int main()
{
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  if (age >= 18)
  {
    printf("ADULT");
  }
  else
  {
    printf("NOT ADULT");
  }

  return 0;
}