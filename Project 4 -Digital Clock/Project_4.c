#include <stdio.h>
#include <time.h>


struct tm *current_time;
void gettime_1()
{
  time_t raw_time;
  time(&raw_time);
  current_time = localtime(&raw_time);
  printf("Current time : %02d:%02d:%02d", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}
void gettime_2()
{
  int hour;
  time_t raw_time;
  time(&raw_time);
  current_time = localtime(&raw_time);
  if (current_time->tm_hour == 0)
  {
    hour = 12;
  }
  else if (current_time->tm_hour / 12 > 0 && current_time->tm_hour / 12 <= 1)
  {
    hour = current_time->tm_hour;
  }
  else
  {
    hour = current_time->tm_hour % 12;
  }

  printf("Current time : %02d:%02d:%02d", hour, current_time->tm_min, current_time->tm_sec);
}

void ampm()
{
  if (current_time->tm_hour>=12)
  {
    printf(" PM\n");
  }
  else
  {
    printf(" AM\n");
  }
}
void getdate()
{
  char mon[10];
  char wd[10];
  char *months[] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  
  int year=current_time->tm_year+1900;

  char *weeks[] = {
    "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  
    printf("Current date : %s %02d %s, %d",weeks[current_time->tm_wday],current_time->tm_mday,months[current_time->tm_mon],year);

}

int main()
{
  /*int ch;
  printf("Enter 1 for 12 hrs / Enter 2 for 24 hrs format : ");
  scanf("%d", &ch);*/
  gettime_2();
  ampm();
  getdate();
  return 0;
}
