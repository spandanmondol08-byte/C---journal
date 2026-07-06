// Income tax calculation program

#include <stdio.h>

int main()
{
  int income;
  printf("Enter your income: ");
  scanf("%d", &income);
  if (income >= 250000 && income <= 500000)
  {
    printf("Your tax is 5%% of your income: %d\n", income * 5 / 100);
  }
  else if (income > 500000 && income <= 1000000)
  {
    printf("Your tax is 20%% of your income: %d\n", income * 20 / 100);
  }
  else if (income > 1000000)
  {
    printf("Your tax is 30%% of your income: %d\n", income * 30 / 100);
  }
  else
  {
    printf("You are not required to pay any tax.\n");
  }

  return 0;
}