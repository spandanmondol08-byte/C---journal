#include <stdio.h>

int main() {
  int a;
  printf("Enter a no.: ");
  scanf("%d", &a);

  switch(a) 
  {
    case 1:
      printf("One\n");
      break;
    case 2:
      printf("Two\n");
      break;
    case 3:
      printf("Three\n");
      break;
    default:
      printf("Not between 1 and 3\n");
  }

  return 0;
}