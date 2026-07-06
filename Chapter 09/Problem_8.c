// Write a structure capable of storing date. Write a function to compare those
// dates

#include <stdio.h>
typedef struct date
{
  int dd;
  int mm;
  int yyyy;
} d;
void compare(d d1, d d2)
{
  {
    if (d1.yyyy > d2.yyyy)
        printf("Date 1 is greater than Date 2\n");
    else if (d1.yyyy < d2.yyyy)
        printf("Date 2 is greater than Date 1\n");
    else if (d1.mm > d2.mm)
        printf("Date 1 is greater than Date 2\n");
    else if (d1.mm < d2.mm)
        printf("Date 2 is greater than Date 1\n");
    else if (d1.dd > d2.dd)
        printf("Date 1 is greater than Date 2\n");
    else if (d1.dd < d2.dd)
        printf("Date 2 is greater than Date 1\n");
    else
        printf("Both the dates are equal\n");
  }
}

int main()
{
  d date1;
  date1.dd = 14;
  date1.mm = 02;
  date1.yyyy = 2008;
  d date2;
  date2.dd = 14;
  date2.mm = 02;
  date2.yyyy = 2008;
  compare(date1, date2);
  return 0;
}