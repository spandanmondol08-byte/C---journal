#include <stdio.h>

void select_dif()
{
  while (1)
  {
    printf("\n\n               TIC TAC TOE                \n\n");
    printf("Select difficulty level\n");
    printf("1. Normal Mode (Standard)\n");
    printf("2. God Mode (Impossible to win)\n");
    printf("3. EXIT!!!\n\n");
    int ch;
    printf("Enter your choice : ");
    scanf("%d",&ch);

    if(ch == 1)
    {

    } 
    else if (ch == 2)
    {

    }
    else if (ch == 3)
    {
      printf("EXITING !!!");
      break;
    }
    else
    {
      printf("Invalid Input!!!");
    }
  }
}

void print_board()
{
  printf("Score - Player X: %d, Computer: %d, Draw: %d");

}

int main() {
  select_dif();

  return 0;
}