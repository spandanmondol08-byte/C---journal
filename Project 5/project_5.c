#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int t_com_per = 0;
  int step = 3;
  int limit = 100 % 3;
  const int bar_lenght = 100;
  int id = 1;
  while (1)
  {
    system("cls");
    int bar_com_per = (bar_lenght * t_com_per) / 100;
    printf("Task %d : [", id);
    for (int i = 0; i < bar_lenght; i++)
    {
      if (i < bar_com_per)
      {
        printf("=");
      }
      else
      {
        printf(" ");
      }
    }
    printf("] %d%%\n", t_com_per);
    sleep(1);
    if (t_com_per < (100 - limit))
    {
      t_com_per = t_com_per + step;
    }
    else if (t_com_per == 100)
    {
      break;
    }
    else
    {
      t_com_per = t_com_per + limit;
    }
  }

  return 0;
}