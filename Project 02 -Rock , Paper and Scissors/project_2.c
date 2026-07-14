#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
  printf("--------------------------------------------------------ROCK, PAPER AND SCISSORS---------------------------------------------------------\n\n\n");
  printf("Game Description : Type 'Rock','Paper' or 'Scissor' to play  ENJOY!! and BEST OF LUCK!! \n\n\n");
  while (1)
  {
    char ch;
    printf("Press y to play and n to EXIT!! game : ");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
      srand(time(0));
      int computer = rand() % 3;
      char strh[10];
      printf("Enter 'Rock','Paper' or 'Scissor' : ");
      scanf(" %s", strh);
      char strc[10];
      if (computer == 0)
      {
        strcpy(strc, "Rock");
      }
      else if (computer == 1)
      {
        strcpy(strc, "Paper");
      }
      else
      {
        strcpy(strc, "Scissors");
      }
      printf("The Computer choose : %s\n", strc);
      int player;

      if (strcmp(strh, "Rock") == 0)
      {
        player = 0;
      }
      else if (strcmp(strh, "Paper") == 0)
      {
        player = 1;
      }
      else if (strcmp(strh, "Scissor") == 0)
      {
        player = 2;
      }
      else
      {
        printf("Wrong Choice\n");
        player = 3;
      }

      if (player == 0 && computer == 0)
      {
        printf("Its a Draw!\n");
      }
      else if (player == 0 && computer == 1)
      {
        printf("You Lose!\n");
      }
      else if (player == 0 && computer == 2)
      {
        printf("You Win!\n");
      }
      else if (player == 1 && computer == 0)
      {
        printf("You Win!\n");
      }
      else if (player == 1 && computer == 1)
      {
        printf("Its a Draw!\n");
      }
      else if (player == 1 && computer == 2)
      {
        printf("You Lose!\n");
      }
      else if (player == 2 && computer == 0)
      {
        printf("You Lose!\n");
      }
      else if (player == 2 && computer == 1)
      {
        printf("You Win!\n");
      }
      else if (player == 2 && computer == 2)
      {
        printf("Its a Draw!\n");
      }
      else
      {
        printf("Something went wrong!\n");
      }
    }
    else if (ch == 'n')
    {
      printf("EXITING!!!\n");
      break;
    }
    else
    {
      printf("Invalid Input!!!\n");
    }
  }
  return 0;
}