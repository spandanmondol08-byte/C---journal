// Grading students based on their marks

#include <stdio.h>

int main() {
  int marks;
  printf("Enter youe marks: ");
  scanf("%d",&marks);

  if (marks<=100 && marks >=90 )
  {
    printf("You get grade <<<<A>>>>");
  }
  else if (marks<90 && marks >=80 )
  {
    printf("You get grade <<<<B>>>>");
  }
  else if (marks<80 && marks >=70 )
  {
    printf("You get grade <<<<C>>>>");
  }
  else if (marks<70 && marks >=60 )
  {
    printf("You get grade <<<<D>>>>");
  }
  else if (marks<60 && marks >=50 )
  {
    printf("You get grade <<<<E>>>>");
  }
  else
  {
    printf("You Failed!!!!!!");
  }
  return 0;
}