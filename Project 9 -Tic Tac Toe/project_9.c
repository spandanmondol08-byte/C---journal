#include <stdio.h>

char board[3][3] = {
  {' ',' ',' '},
  {' ',' ',' '},
  {' ',' ',' '}
}

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

void print_board(board[3][3])
{
  printf("Score - Player X: %d, Computer: %d, Draw: %d");
  for (int i =0 ; i < 3 ; i++)
  {
    for (int j=0;j<3;j++)
    {
      if (j%3==0)
      {
        printf("%c",board[i][j]);
      }
      else
      {
        printf("|");
        printf("%c",board[i][j]);
      }
    }
  }
}

int main() {
  select_dif();
  print_board(board);
  
  return 0;
}