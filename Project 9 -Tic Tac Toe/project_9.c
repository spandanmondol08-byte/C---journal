#include <stdio.h>

char board[3][3] = {
    {'X', ' ', ' '},
    {' ', 'X', ' '},
    {' ', ' ', 'X'}};
int ps = 0, cs = 0, ds = 0;

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
    scanf("%d", &ch);

    if (ch == 1)
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

void print_board(char board[3][3])
{
  printf("Score - Player X: %d, Computer: %d, Draw: %d\n\n", ps, cs, ds);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (j % 3 == 0)
      {
        printf(" %c ", board[i][j]);
      }
      else
      {
        printf(" | ");
        printf(" %c ", board[i][j]);
      }
    }
    if (i == 0 || i == 1)
    {
      printf("\n----+-----+----\n");
    }
  }
}

int check(char board[3][3], int row, int column)
{
  // Check row

  if (board[row][0] != ' ' &&
      board[row][0] == board[row][1] &&
      board[row][1] == board[row][2])
  {
    return 1;
  }

  // Check column

  if (board[0][column] != ' ' &&
      board[0][column] == board[1][column] &&
      board[1][column] == board[2][column])
  {
    return 1;
  }

  // Check main diagonal

  if (row == column)
  {
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
      return 1;
    }
  }

  // Check anti-diagonal
  
  if (row + column == 2)
  {
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  // select_dif();
  print_board(board);

  return 0;
}