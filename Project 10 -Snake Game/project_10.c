#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Direction
{
  char up;
  char down;
  char right;
  char left;
  char stop;
}direction;
direction dir;
int height=20 , width =80;
int food_x;
int food_y;
int snake_x;
int snake_y;
int score = 0;
void entry(char);
void draw();
void setup();
void game_loop();

void entry(char ch)
{
  while (1)
  {
    int (kbhit())
    {
      ch = getch();
    }
    if (ch=='w')
    {
      snake_y--;
    }
    else if (ch=='w')
    {
      snake_y++;
    }
    
  }
}

void draw()
{
  system("cls");
  printf("\t\t\t\tSNAKE GAME\n\n");
  for (int i =0 ; i < width+2 ; i++)
  {
    printf("#");
  }
  printf("\n");

  for (int i = 0 ; i < height ; i++)
  {
    printf("#");
    for (int j = 0; j < width ; j++)
    {
      
      if (i==snake_y && j==snake_x)
      {
        printf("O");
      }
      else if (i==food_y && j==food_x)
      {
        printf("F");
      }
      else
      {
        printf(" ");
      }
      
    }
    printf("#\n");
  }

  for (int i =0 ; i < width+2 ; i++)
  {
    printf("#");
  }
  printf("\n\nScore : %d\n\n",score);

}

void setup()
{
  snake_y=height/2;
  snake_x=width/2;
  food_x=rand()%width;
  food_y=rand()%height;

}

void game_loop()
{

}

int main() {
  srand(time(NULL));
  setup();
  draw();
  dir.stop;
  return 0;
}