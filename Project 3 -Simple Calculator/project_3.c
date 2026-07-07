#include <stdio.h>
#include <math.h>

int main()
{
  printf("---------------------------------------------\n");
  printf("             SIMPLE CALCULATOR             \n");
  printf("---------------------------------------------\n");

  while (1)
  {
    int ch;
    printf("1) Add\n");
    printf("2) Substract\n");
    printf("3) Multiply\n");
    printf("4) Divide\n");
    printf("5) Modulus\n");
    printf("6) Power\n");
    printf("7) EXIT!!!!\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int a, b;
      printf("Enter the first number : ");
      scanf("%d", &a);
      printf("Enter the second number : ");
      scanf("%d", &b);
      printf("The sum of the two numbers : %d\n", a + b);
    }
    else if (ch == 2)
    {
      int a, b;
      printf("Enter the first number : ");
      scanf("%d", &a);
      printf("Enter the second number : ");
      scanf("%d", &b);
      printf("The difference of the two numbers : %d\n", a - b);
    }
      
    else if (ch == 3)
    {
      int a, b;
      printf("Enter the first number : ");
      scanf("%d", &a);
      printf("Enter the second number : ");
      scanf("%d", &b);
      printf("The product of the two numbers : %d\n", a * b);
    }
    else if (ch == 4)
    {
      int a, b;
      printf("Enter the first number : ");
      scanf("%d", &a);
      printf("Enter the second number : ");
      scanf("%d", &b);
      printf("The quotient of the two numbers : %d\n", a / b);
    }
    else if (ch == 5)
    {
      int a, b;
      printf("Enter the first number : ");
      scanf("%d", &a);
      printf("Enter the second number : ");
      scanf("%d", &b);
      printf("The remainder of the two numbers : %d\n", a % b);
    }
    else if (ch == 6)
    {
      int a, b;
      printf("Enter the base number : ");
      scanf("%d", &a);
      printf("Enter the power : ");
      scanf("%d", &b);
      printf("%d to the power %d : %.2f\n", a, b, pow(a, b));
    }
    else if (ch == 7)
    {
      printf("EXITING CODE !!!\n");
      break;
    }
    else
    {
      printf("Wrong Input\n");
    }
  }

  return 0;
}