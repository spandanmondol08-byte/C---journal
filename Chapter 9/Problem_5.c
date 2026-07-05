// Create an array of 5 complex numbers created in Problem 5 and display them
// with the help of a display function. The values must be taken as an input from
// the user.
#include <stdio.h>
void display(int c[5][2])
{
  for (int i = 0; i < 5; i++)
  {
    printf("The complex number %d is : %d + %d i", i + 1, c[i][0], c[i][1]);
  }
}
int main()
{
  int cn[5][2];
  for (int i = 0; i < 5; i++)
  {
    printf("Enter the real part of complex number %d : ", i + 1);
    scanf("%d", &cn[i][0]);
    printf("Enter the imaginary part of complex number %d : ", i + 1);
    scanf("%d", &cn[i][1]);
  }
  display(cn);

  return 0;
}