#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

int earnings = 0;
int skip_used = 0;
int fifty_used = 0;

// COLOURS

char red[] = "\033[1;31m";
char green[] = "\033[1;32m";
char yellow[] = "\033[1;33m";
char blue[] = "\033[1;34m";
char magenta[] = "\033[1;35m";
char cyan[] = "\033[1;36m";
char white[] = "\033[1;37m";
char colour_end[] = "\033[0m";

// STRUCTURE DEFINATION

typedef struct KBC
{
  char question[300];
  char options[4][100];
  char correct_op;
  int timeout;
  int prize;
} q_struct;

// FUNCTIONS

void read(q_struct questions[], int);
void qno(int *);
void print_quiz(q_struct questions[], int);
int play(q_struct questions[], int);
int lifeline();
void fifty_fifty(q_struct questions[], int);
char timed_input(int);

void read(q_struct questions[], int question_nos)
{
  FILE *ptr;
  ptr = fopen("questions.txt", "r");
  if (ptr == NULL)
  {
    printf("Cannot open questions.txt\n");
    return;
  }
  for (int i = 0; i < question_nos; i++)
  {
    fscanf(ptr, "Question: ");
    fgets(questions[i].question, 300, ptr);
    if (questions[i].question[strlen(questions[i].question) - 1] == '\n')
    {
      questions[i].question[strlen(questions[i].question) - 1] = '\0';
    }
    fscanf(ptr, "A. ");
    fgets(questions[i].options[0], 100, ptr);
    if (questions[i].options[0][strlen(questions[i].options[0]) - 1] == '\n')
    {
      questions[i].options[0][strlen(questions[i].options[0]) - 1] = '\0';
    }
    fscanf(ptr, "B. ");
    fgets(questions[i].options[1], 100, ptr);
    if (questions[i].options[1][strlen(questions[i].options[1]) - 1] == '\n')
    {
      questions[i].options[1][strlen(questions[i].options[1]) - 1] = '\0';
    }
    fscanf(ptr, "C. ");
    fgets(questions[i].options[2], 100, ptr);
    if (questions[i].options[2][strlen(questions[i].options[2]) - 1] == '\n')
    {
      questions[i].options[2][strlen(questions[i].options[2]) - 1] = '\0';
    }
    fscanf(ptr, "D. ");
    fgets(questions[i].options[3], 100, ptr);
    if (questions[i].options[3][strlen(questions[i].options[3]) - 1] == '\n')
    {
      questions[i].options[3][strlen(questions[i].options[3]) - 1] = '\0';
    }
    fscanf(ptr, "Correct: %c\n", &questions[i].correct_op);
    fscanf(ptr, "Time: %d\n", &questions[i].timeout);
    fscanf(ptr, "Prize: %d\n", &questions[i].prize);
  }
  fclose(ptr);
}

void qno(int *qn)
{
  int c = 0;
  FILE *ptr1;
  ptr1 = fopen("questions.txt", "r");
  if (ptr1 == NULL)
  {
    printf("Cannot open questions.txt\n");
    return;
  }
  while (1)
  {
    char ch = fgetc(ptr1);
    if (ch == EOF)
    {
      fclose(ptr1);
      break;
    }
    else
    {
      if (ch == '\n')
      {
        c++;
      }
    }
  }
  c++;
  *qn = c / 8;
}

void print_quiz(q_struct questions[], int i)
{
  printf("%sQuestion %d.%s\n\n", white, i + 1, colour_end);
  printf("%s%s%s\n\n", yellow, questions[i].question, colour_end);
  printf("%sA. %s%s\n", cyan, questions[i].options[0], colour_end);
  printf("%sB. %s%s\n", cyan, questions[i].options[1], colour_end);
  printf("%sC. %s%s\n", cyan, questions[i].options[2], colour_end);
  printf("%sD. %s%s\n\n", cyan, questions[i].options[3], colour_end);
  printf("%sHurry up!! You have only %d seconds to answer...%s\n\n", red, questions[i].timeout, colour_end);
  printf("%sEnter your answer (A,B,C OR D) or L for Lifeline : %s", magenta, colour_end);
}

int play(q_struct questions[], int i)
{
  char ans = timed_input(questions[i].timeout);
  if (ans=='T')
  {
    printf("%s\n\nTIME OVER!!!!!%s\n\n",red,colour_end);
    return 0;
  }
  if (ans == 'L')
  {
    int x = lifeline();
    if (x == 0)
    {
      lifeline();
    }
    else if (x == 1)
    {
      printf("%s\n\n========================================%s\n", blue, colour_end);
      printf("%s       SKIP QUESTION USED%s\n", yellow, colour_end);
      printf("%s========================================%s\n\n", blue, colour_end);
      printf("%sThis question has been skipped.%s\n", green, colour_end);
      printf("%sNo prize will be awarded for this question.%s\n", red, colour_end);
      printf("%sMoving to the next question...%s\n\n", cyan, colour_end);
      return 1;
    }
    else if (x == 2)
    {
      fifty_fifty(questions, i);
      printf("%sHurry up!! You have only %d seconds to answer...%s\n\n", red, questions[i].timeout, colour_end);
      char ans = timed_input(questions[i].timeout);
      if(ans=='T')
      {
        printf("%s\n\nTIME OVER!!!!!%s\n\n",red,colour_end);
        return 0;
      }
      if (ans == questions[i].correct_op)
      {
        printf("%s\nCorrect Answer!!!%s\n", green, colour_end);
        printf("%s\nYou have won Rs.%d%s\n\n",
               green,
               questions[i].prize,
               colour_end);

        earnings += questions[i].prize;

        printf("%sTotal Earnings : Rs.%d%s\n",
               magenta,
               earnings,
               colour_end);
      }
      else
      {
        printf("%s\nWrong Answer!!!%s\n",
               red,
               colour_end);

        printf("%sYour Earnings : Rs.%d%s\n",
               magenta,
               earnings,
               colour_end);

        return 0; 
      }
    }
    else
    {
      print_quiz(questions, i);
      play(questions, i);
    }
  }
  else if (ans == questions[i].correct_op)
  {
    printf("%s\nCorrect Answer!!!%s\n", green, colour_end);
    printf("%s\nYou have won Rs.%d%s\n\n", green, questions[i].prize, colour_end);
    earnings = earnings + questions[i].prize;
    printf("%sTotal Earning : Rs.%d%s\n", magenta, earnings, colour_end);
  }
  else
  {
    printf("%s\nWrong Answer!!!%s\n\n", red, colour_end);
    printf("%sYour Earning : %d%s", magenta, earnings, colour_end);
    return 0;
  }
}

int lifeline()
{
  int choice;
  printf("%s\n===== LIFELINES =====\n\n%s", cyan, colour_end);

  printf("%s1. Skip Question\n%s", blue, colour_end);
  printf("%s2. 50-50\n%s", blue, colour_end);

  printf("%s0. Cancel\n\n%s", red, colour_end);

  printf("%s\nChoose a lifeline : %s", magenta, colour_end);
  choice = getche();

  if (choice == '1' && skip_used == 1)
  {
    printf("Skip already used!\n");
    return 0;
  }
  else if (choice == '1' && skip_used == 0)
  {
    skip_used = 1;
    return 1;
  }
  else if (choice == '2' && fifty_used == 1)
  {
    printf("50-50 already used!\n");
    return 0;
  }
  else if (choice == '2' && fifty_used == 0)
  {
    fifty_used = 1;
    return 2;
  }
  else
  {
    return 3;
  }
}

void fifty_fifty(q_struct questions[], int i)
{
  char option[] = {'A', 'B', 'C', 'D'};
  int correct = questions[i].correct_op - 'A';
  int wrong[3];
  int k = 0;

  for (int j = 0; j < 4; j++)
  {
    if (j != correct)
      wrong[k++] = j;
  }

  int keep = wrong[rand() % 3];

  printf("%s\n\n========================================%s\n", blue, colour_end);
  printf("%s          FIFTY - FIFTY USED%s\n", yellow, colour_end);
  printf("%s========================================%s\n\n", blue, colour_end);

  printf("%sTwo incorrect options have been removed.%s\n\n", green, colour_end);

  // Print only the correct option and one random wrong option
  for (int j = 0; j < 4; j++)
  {
    if (j == correct || j == keep)
    {
      printf("%s%c. %s%s\n",
             cyan,
             option[j],
             questions[i].options[j],
             colour_end);
    }
  }

  printf("\n%sEnter your answer (A, B, C or D): %s",
         magenta,
         colour_end);
}

char timed_input(int sec)
{
  time_t start = time(NULL);
  while(time(NULL)-start<sec)
  {
    if (kbhit())
    {
      return toupper(getche());
    }
  }
  return 'T';
}

// MAIN

int main()
{
  srand(time(NULL));
  int r=0;
  printf("\n\t\t\t\t%sCHALO SURU KARE YEH ADBHUT KHEL KAUN BANEGA COREPATI !!!!%s\n\n", blue, colour_end);
  int question_nos;
  qno(&question_nos);
  q_struct questions[question_nos];
  read(questions, question_nos);
  for (int i = 0; i<question_nos; i++)
  {
    print_quiz(questions, i);
    int z = play(questions, i);
    if(z==1)
    {
      continue;
    }
    if(z==0)
    {
      r=1;
      break;
    }
    printf("\n%sEnter any key to go to the next question : %s\n",yellow,colour_end);
    char p = getch();
    printf("\n\n-------------------------------------------------------------\n\n");
  }
  if(r==0)
  {
    printf("%s\nCongratulations!!! You have won the game and a total cash prize of Rs.%d%s\n\n", yellow, earnings, colour_end);
  }
  printf("%s\n\nTHANKS FOR PLAYING%s\n\n",white,colour_end);
  
  return 0;
}