#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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
void entry();
void draw();
void setup();
void game_loop();

void entry()
{
  char ch='x';
  setup();
  draw();
  while (1)
  {
    if (kbhit())
    {
      ch = getch();
    }
    if (ch=='w')
    {
      snake_y--;
      draw();
    }
    else if (ch=='s')
    {
      snake_y++;
      draw();
    }
    else if (ch=='a')
    {
      snake_x--;
      draw();
    }
    else if (ch=='d')
    {
      snake_x++;
      draw();
    }
    Sleep(1000);
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
  entry();
  return 0;
}