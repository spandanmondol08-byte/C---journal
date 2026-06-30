#include <stdio.h>

int main()
{
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);

  if (age > 55)
  {
    printf("SENIOR CITIZEN");
  }
  else if (age >= 18)
  {
    printf("ADULT");
  }
  else
  {
    printf("NOT AN ADULT");
  }

  return 0;
}