#include <stdio.h>
#include <string.h>
#include <conio.h>

int earnings=0;

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
}q_struct;


// FUNCTIONS


void read(q_struct questions[],int);
void qno(int *);
void print_quiz(q_struct questions[],int);
void play(q_struct questions[],int);

void read(q_struct questions[],int question_nos)
{
  FILE * ptr;
  ptr = fopen("questions.txt","r");
  if (ptr == NULL)
  {
    printf("Cannot open questions.txt\n");
    return;
  }
  for(int i = 0 ; i<question_nos; i++)
  {
    fscanf(ptr,"Question: ");
    fgets(questions[i].question,300,ptr);
    if (questions[i].question[strlen(questions[i].question)-1]=='\n')
    {
      questions[i].question[strlen(questions[i].question)-1]='\0';
    }
    fscanf(ptr,"A. ");
    fgets(questions[i].options[0],100,ptr);
    if (questions[i].options[0][strlen(questions[i].options[0])-1]=='\n')
    {
      questions[i].options[0][strlen(questions[i].options[0])-1]='\0';
    }
    fscanf(ptr,"B. ");
    fgets(questions[i].options[1],100,ptr);
    if (questions[i].options[1][strlen(questions[i].options[1])-1]=='\n')
    {
      questions[i].options[1][strlen(questions[i].options[1])-1]='\0';
    }
    fscanf(ptr,"C. ");
    fgets(questions[i].options[2],100,ptr);
    if (questions[i].options[2][strlen(questions[i].options[2])-1]=='\n')
    {
      questions[i].options[2][strlen(questions[i].options[2])-1]='\0';
    }
    fscanf(ptr,"D. ");
    fgets(questions[i].options[3],100,ptr);
    if (questions[i].options[3][strlen(questions[i].options[3])-1]=='\n')
    {
      questions[i].options[3][strlen(questions[i].options[3])-1]='\0';
    }
    fscanf(ptr,"Correct: %c\n",&questions[i].correct_op);
    fscanf(ptr,"Time: %d\n",&questions[i].timeout);
    fscanf(ptr,"Prize: %d\n",&questions[i].prize);
  }
  fclose(ptr);
}

void qno(int * qn)
{
  int c=0;
  FILE * ptr1;
  ptr1=fopen("questions.txt","r");
  if (ptr1 == NULL)
  {
    printf("Cannot open questions.txt\n");
    return;
  }
  while (1)
  {
    char ch=fgetc(ptr1);
    if (ch==EOF)
    {
      fclose(ptr1);
      break;
    }
    else
    {
      if (ch=='\n')
      {
        c++;
      }
    }
  }
  c++;
  *qn=c/8;
}

void print_quiz(q_struct questions[],int i)
{
  printf("%sQuestion %d.%s\n\n",white,i+1,colour_end);
  printf("%s%s%s\n\n",yellow,questions[i].question,colour_end);
  printf("%sA. %s%s\n",cyan,questions[i].options[0],colour_end);
  printf("%sB. %s%s\n",cyan,questions[i].options[1],colour_end);
  printf("%sC. %s%s\n",cyan,questions[i].options[2],colour_end);
  printf("%sD. %s%s\n\n",cyan,questions[i].options[3],colour_end);
  printf("%sHurry up!! You have only %d seconds to answer...%s\n\n",red,questions[i].timeout,colour_end);
  printf("%sEnter your answer (A,B,C OR D) or L for Lifeline : %s",magenta,colour_end);
}

void play(q_struct questions[],int i)
{
  char ans=getch();
  if (ans=='L')
  {
    lifeline();
  }
  else if (ans==questions[i].correct_op)
  {
    printf("%sCorrect Answer!!!%s\n"green,colour_end);
    printf("%sYou have won Rs.%d%s\n\n",green,questions[i].prize,colour_end);
    earnings=earnings+questions[i].prize;
    printf("%sTotal Earning : Rs.%d%s\n",magenta,earnings,colour_end);
  }
  else{
    printf("%sWrong Answer!!!%s",red,colour_end);
    printf("%sYour Earning : %d%s",magenta,earnings,colour_end);
  }

}

// MAIN

int main() {
  printf("\n\t\t\t\t%sCHALO SURU KARE YEH ADBHUT KHEL KAUN BANEGA COREPATI !!!!%s\n\n",blue,colour_end);
  int question_nos ;
  qno(&question_nos);
  q_struct questions[question_nos];
  read(questions,question_nos);
  int i =0;
  print_quiz(questions,i);
  return 0;
}