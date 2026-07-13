#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ps = 0, cs = 0, ds = 0;

void print_board(char board[3][3],int ps,int cs ,int ds)
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


void play_game(char board[3][3],int ds,int ps,int cs)
{
  int row;
  int column;
  int turn = rand() % 10 + 1;
  while(1)
  {
    int c=0;
    if (turn%2==0)
    {
      printf("\n\nPlayer X's turn\n");
      
      while(1)
      {
        printf("Enter the row and column 1 to 3 (with a space) : ");
        scanf("%d %d",&row,&column);
        if ( row > 3 || column > 3 || row < 1 || column < 1 || board[row-1][column-1]!=' ')
        {
          printf("Invalid Input!!!\n");
        }
        else
        {
          break;
        }
      }
      board[row-1][column-1]='X';
      if(check(board, row - 1, column - 1))
      {
        printf("\nPlayer X Wins!\n");
        c=9;
        ps++;
        break;
      }
      system("cls");
      print_board(board,cs,ds,ps);
      turn=1;
    }
    else
    {
      while(1)
      {
        row=rand()%3;
        column=rand()%3;
        if (board[row][column]==' ')
        {
          break;
        }
      }
      board[row][column]='O';
      if (check(board, row, column))
      {
        printf("\nComputer Wins!\n");
        cs++;
        c=9;
        break;
      }
      system("cls");
      print_board(board,cs,ps,ds);
      turn=2;
    }
    for (int i =0 ; i < 3 ; i++)
    {
      for (int j=0 ; j<3; j++)
      {
        if (board[i][j]!=' ')
        {
          c++;
        }
      }
    } 
    if(c==9)
    {
      printf("\n\nDraw!!!\n\n");
      ds++;
      break;
    }
  }
}

int main()
{
  srand(time(NULL));
  while (1)
  {
    char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};
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
      while (1)
      {
        char board[3][3] = {
          {' ', ' ', ' '},
          {' ', ' ', ' '},
          {' ', ' ', ' '}
        };
        print_board(board, ds, ps, cs);
        play_game(board,ds,ps,cs);
        int x;
        printf("Enter 1 to play again or 2 to go back to main menu : ");
        scanf("%d",&x);
        if(x==2)
        {
          break;
        }
      }  
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
  
  return 0;
}