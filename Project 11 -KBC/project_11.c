#include <stdio.h>

typedef struct KBC
{
  char question[300];
  char options[4][100];
  int timeout;
  int prize;
}q_struct;

int question_nos=20;

void read(quest questions[])
{
  FILE * ptr;
  ptr = fopen("questions.txt","r");
  for(int i = 0 ; i<question_nos; i++)
  {
    fscanf(ptr,"Question: %s\nA. %s\nB. %s\nC. %s\nD. %s\nTime: %d\nPrize: %d\n",questions[i].question,questions[i].options[1],questions[i].options[2],questions[i].options[3],questions[i].options[4],&questions[i].timeout,&questions[i].prize);
  }
  fclose(ptr);
}


int main() {

  return 0;
}