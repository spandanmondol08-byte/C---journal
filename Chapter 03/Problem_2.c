// Determine if a student passed or failed based on their exam

#include <stdio.h>

int main()
{
  int maths;
  int science;
  int st;
  printf("Enter your marks out of 80 in maths: ");
  scanf("%d", &maths);
  printf("Enter your marks out of 80 in science: ");
  scanf("%d", &science);
  printf("Enter your marks out of 80 in Social Studies: ");
  scanf("%d", &st);
  float mp = (maths / 80.0) * 100;
  float sp = (science / 80.0) * 100;
  float stp = (st / 80.0) * 100;
  float tp = ((maths + science + st) / 240.0) * 100;
  if (tp >= 40)
  {
    if (mp >= 33 && sp >= 33 && stp >= 33)
    {
      printf("You Passed the exam", tp);
    }
    else
    {
      printf("You Failed the exam because you didn't meet the minimum requirements in a subject", tp);
    }
  }
  else
  {
    printf("You Failed the exam because your total percentage is less than 40", tp);
  }

  return 0;
}