#include <stdio.h>
#include <string.h>

// STRUCTURE DEFINATION

typedef struct KBC
{
  char question[300];
  char options[4][100];
  char correct_op;
  int timeout;
  int prize;
}q_struct;

q_struct questions[20];

// FUNCTIONS


void read(q_struct questions[],int);
void qno(int);

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

void qno(int question_nos)
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
  question_nos=c/8;
}

// MAIN

int main() {
  int question_nos ;
  qno(question_nos);
  read(questions,question_nos);
  return 0;
}