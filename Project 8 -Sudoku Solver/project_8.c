#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct task_progress_bar
{
  char id[10];
  int step;
  int progress;
} pbar;

int puzzle[9][9];
pbar task = {"Solving", 5, 0};
void progress_Bar(pbar task)
{  
  while (1)
  {
    const int bar_lenght = 50;
    system("cls");
    int bar_com_per = (bar_lenght * task.progress) / 100;
    printf("%s : [", task.id);
    for (int j = 0; j < bar_lenght; j++)
    {
      if (j < bar_com_per)
     {
       printf("=");
      }
      else
      {
        printf(" ");
      }
    }
  if (task.progress==100)
  {
    printf("] %d%%  DONE\n", task.progress);
    return ;
  }
  printf("] %d%%\n", task.progress);
  sleep(1);
  task.progress=task.progress+5;
  }
}



void input_puzzle(int puzzle[9][9])
{
  printf("Enter the Sudoku puzzle (9x9).\n");
  printf("Use 0 for empty cells.\n\n");

  for (int i = 0; i < 9; i++)
  {
    printf("Enter row %d (9 numbers separated by spaces): ", i + 1);

    for (int j = 0; j < 9; j++)
    {
      scanf("%d", &puzzle[i][j]);

      while (puzzle[i][j] < 0 || puzzle[i][j] > 9)
      {
        printf("Invalid input! Enter a number between 0 and 9: ");
        scanf("%d", &puzzle[i][j]);
      }
    }
  }
}

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

int valid_move(int puzzle[9][9], int row, int column, int value)
{
  // Row check
  for (int i = 0; i < 9; i++)
  {
    if (puzzle[row][i] == value)
    {
      return 0;
    }
  }
  // Column check
  for (int i = 0; i < 9; i++)
  {
    if (puzzle[i][column] == value)
    {
      return 0;
    }
  }
  // Box check
  int r = row - row % 3;
  int c = column - column % 3;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (puzzle[r + i][c + j] == value)
      {
        return 0;
      }
    }
  }
  return 1;
}

int solver(int puzzle[9][9], int row, int column)
{
  if (column == 9 & row == 8)
  {
    return 1;
  }
  if (column == 9)
  {
    row++;
    column = 0;
  }
  if (puzzle[row][column] > 0)
  {
    return solver(puzzle, row, column + 1);
  }

  for (int i = 1; i <= 9; i++)
  {
    if (valid_move(puzzle, row, column, i))
    {
      puzzle[row][column] = i;
      if (solver(puzzle, row, column + 1))
      {
        return 1;
      }
      puzzle[row][column] = 0;
    }
  }
  return 0;
}

// MAIN

int main()
{
  printf("\n\n              Welcome to Sudoku Solver            \n\n");
  input_puzzle(puzzle);
  printf("Original Sudoku : ");
  print_puzzle(puzzle);
  printf("Please Check your entered unsolved Sudoku\n");
  int i;
  printf("Enter any digit to start solving : ");
  scanf("%d",&i);
  progress_Bar(task);
  if (solver(puzzle, 0, 0))
  {
    printf("\nSolved Sudoku : ");
    print_puzzle(puzzle);
  }
  else
  {
    printf("The Sudoku is not solvable !!!!\n");
  }
  return 0;
}