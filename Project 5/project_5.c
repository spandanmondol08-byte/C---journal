#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct task_progress_bar
{
  int id;
  int step;
  int progress;
} pbar;

int main()
{
  srand(time(NULL));
  const int bar_lenght = 50;
  pbar task[5] = {
      {1, rand() % 5 + 1, 0},
      {2, rand() % 5 + 1, 0},
      {3, rand() % 5 + 1, 0},
      {4, rand() % 5 + 1, 0},
      {5, rand() % 5 + 1, 0}};

  while (1)
  {
    int c = 0;
    system("cls");
    for (int i = 0; i < 5; i++)
    {
      if (task[i].progress + task[i].step >= 100)
      {
        task[i].progress = 100;
      }
      else
      {
        task[i].progress = task[i].progress + task[i].step;
      }
      int bar_com_per = (bar_lenght * task[i].progress) / 100;
      printf("Task %d : [", task[i].id);

      for (int j = 0; j < bar_lenght; j++)
      {
        if (j < bar_com_per)
        {
          printf("=");
        }
        else
        {
          printf(" ");
        }
      }
      if (task[i].progress == 100)
      {
        printf("] %3d%%  DONE\n", task[i].progress);
      }
      else
      {
        printf("] %3d%%\n", task[i].progress);
      }
      if (task[i].progress == 100)
      {
        c++;
      }
    }
    if (c == 5)
    {
      printf("ALL TASKS COMPLETED !!!");
      break;
    }
    sleep(1);
  }

  return 0;
}

