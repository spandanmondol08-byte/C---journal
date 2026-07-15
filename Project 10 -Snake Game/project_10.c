#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int tail_x[100];
int tail_y[100];
int tail_length = 0;
int height = 20, width = 60;
int food_x;
int food_y;
int snake_x;
int snake_y;
int score = 0;
int speed = 200;
void entry();
void draw();
void setup();
int isTail(int, int);
void updateTail();

void gotoxy(int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void hideCursor()
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;

  info.dwSize = 100;
  info.bVisible = FALSE;

  SetConsoleCursorInfo(h, &info);
}
void entry()
{
  char ch = 'x';
  setup();
  draw();
  while (1)
  {
    if (kbhit())
    {
      ch = getch();
    }
    if (ch == 'w')
    {
      updateTail();
      snake_y--;
    }
    else if (ch == 's')
    {
      updateTail();
      snake_y++;
    }
    else if (ch == 'a')
    {
      updateTail();
      snake_x--;
    }
    else if (ch == 'd')
    {
      updateTail();
      snake_x++;
    }
    if (snake_y < 0)
    {
      snake_y = height - 1;
    }

    if (snake_y >= height)
    {
      snake_y = 0;
    }

    if (snake_x < 0)
    {
      snake_x = width - 1;
    }

    if (snake_x >= width)
    {
      snake_x = 0;
    }

    if (snake_x == food_x && snake_y == food_y)
    {
      tail_length++;
      score += 10;
      speed -= 10;
      if (speed < 50)
      {
        speed = 50;
      }
      food_x = rand() % width;
      food_y = rand() % height;
    }

    Sleep(speed);
    draw();
  }
}

void draw()
{
  gotoxy(0, 0);
  // printf("\t\t\t\tSNAKE GAME\n\n");
  for (int i = 0; i < width + 2; i++)
  {
    printf("#");
  }
  printf("\n");

  for (int i = 0; i < height; i++)
  {
    printf("#");
    for (int j = 0; j < width; j++)
    {

      if (i == snake_y && j == snake_x)
      {
        printf("O");
      }
      else if (i == food_y && j == food_x)
      {
        printf("F");
      }
      else if (isTail(j,i))
      {
        printf("o");
      }
      else
      {
        printf(" ");
      }
    }
    printf("#\n");
  }

  for (int i = 0; i < width + 2; i++)
  {
    printf("#");
  }
  printf("\n\nScore : %d\n\n", score);
}

void setup()
{
  snake_y = height / 2;
  snake_x = width / 2;
  food_x = rand() % width;
  food_y = rand() % height;
}

void updateTail()
{
    for (int i = tail_length - 1; i > 0; i--)
    {
        tail_x[i] = tail_x[i - 1];
        tail_y[i] = tail_y[i - 1];
    }

    tail_x[0] = snake_x;
    tail_y[0] = snake_y;
}

int isTail(int x, int y)
{
  for (int i = 0; i < tail_length; i++)
  {
    if (tail_x[i] == x && tail_y[i] == y)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  hideCursor();
  srand(time(NULL));
  entry();
  return 0;
}