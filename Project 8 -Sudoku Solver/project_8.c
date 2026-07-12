#include <stdio.h>

int puzzle[9][9] = {
    {3, 0, 0, 0, 2, 0, 0, 7, 0},
    {9, 0, 0, 5, 0, 0, 0, 1, 4},
    {0, 1, 6, 3, 7, 0, 0, 0, 8},
    {2, 0, 0, 8, 0, 0, 0, 0, 1},
    {5, 0, 0, 0, 4, 1, 8, 0, 0},
    {0, 8, 9, 0, 0, 0, 0, 5, 0},
    {0, 0, 5, 0, 1, 0, 2, 8, 0},
    {0, 4, 0, 0, 0, 6, 0, 9, 3},
    {7, 3, 1, 0, 8, 2, 0, 0, 0}};

void print_puzzle(int puzzle[9][9])
{
  printf("\n\n");
  for (int i = 0; i < 9; i++)
  {
    if (i % 3 == 0)
    {
      printf("+---------+---------+---------+\n");
    }
    for (int j = 0; j < 9; j++)
    {
      if (j % 3 == 0)
      {
        if (puzzle[i][j] == 0)
        {
          printf("|");
          printf("   ");
        }
        else
        {
          printf("|");
          printf(" %d ", puzzle[i][j]);
        }
      }
      else
      {
        if (puzzle[i][j] == 0)
        {
          printf("   ");
        }
        else
        {
          printf(" %d ", puzzle[i][j]);
        }
      }
    }
    printf("|");
    printf("\n");
  }
  printf("+---------+---------+---------+\n");
}

int valid_move(int puzzle[9][9],int row,int column,int value)
{
  // Row check
  for (int i = 0 ; i<9;i++)
  {
    if (puzzle[row][i] == value)
    {
      return 0;
    }
  }
  // Column check
  for (int i = 0 ; i<9;i++)
  {
    if (puzzle[i][column] == value)
    {
      return 0;
    }
  }
  // Box check 
  int r = row - row%3;
  int c = column - column%3;
  for (int i =0 ; i <3 ; i++)
  {
    for (int j = 0 ; j < 3 ; j++)
    {
      if (puzzle[r+i][c+j]==value)
      {
        return 0;
      }
      
    }
  }
 return 1;
}

// MAIN

int main()
{
  print_puzzle(puzzle);
  while (1)
  {
    for ( int i = 0 ; i < 9 ; i++)
    {
      for ( int j =0 ; j < 9 ; j++)
      {
        int val =0;
        if (valid_move(puzzle,i,j,val)==0)
        {
          val++;
        }
        else
        {
          puzzle[i][j]==val;
        }
      }
    }
  }
  
  return 0;
}