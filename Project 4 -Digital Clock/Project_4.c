#include <stdio.h>
#include <time.h>

struct tm *current_time;
void gettime_1()
{
  time_t raw_time;
  time(&raw_time);
  current_time = localtime(&raw_time);
  printf("Current time : %02d:%02d:%02d ", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}
void gettime_2()
{
  time_t raw_time;
  time(&raw_time);
  current_time = localtime(&raw_time);
  if (current_time->tm_hour / 12 == 0)
  {
    current_time->tm_hour = 12;
  }
  else if (current_time->tm_hour / 12 <= 1)
  {
    current_time->tm_hour = current_time->tm_hour;
  }
  else
  {
    current_time->tm_hour = current_time->tm_hour % 12;
  }

  printf("Current time : %02d:%02d:%02d ", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}

int main()
{
  int ch;
  printf("Enter 1 for 12 hrs / Enter 2 for 24 hrs format : ");
  scanf("%d", &ch);
  
  return 0;
}
