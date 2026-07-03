// Create a 2-d array by taking input from the user. Write a display function to
// print the content of this 2-d array on the screen.

#include <stdio.h>

int main() {
  int n ;
  printf("Enter the number of student : ");
  scanf("%d",&n);
  int stu[n][2];
  for (int i =0;i<n;i=i+1 )
  {
    for (int j = 0;j<2;j=j+1 )
    {
      printf("Enter the marks of subject %d of student %d : ",j+1,i+1);
      scanf("%d",&stu[i][j]);
    }
  }
  for (int i =0;i<n;i=i+1 )
  {
    for (int j = 0;j<2;j=j+1 )
    {
      printf("The marks of the subjects of student %d in subject %d is %d\n",i+1,j+1,stu[i][j]);
    }
  }

  return 0;
}