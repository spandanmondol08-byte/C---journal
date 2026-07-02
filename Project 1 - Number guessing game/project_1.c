#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("----------------------------------------------------------NUMBER GUESSING GAME-----------------------------------------------------------\n\n\n");
  printf("Game Description : A random number is generated. Try to guess it. If the guess is less than the actual number it will show HIGHER!!!. If the guess is more than the actual number it will show LOWER!!!. Try to figure out the number in the least amount of guesses. ENJOY!! and BEST OF LUCK!! \n\n\n");
  while (1)
  {
    char ch;
    printf("Press Y to play and N to EXIT!! game : ");
    scanf(" %c", &ch);  
    if (ch=='Y')
    {
      srand(time(NULL));   

      int num = rand() % 100 + 1;
      int c=0;
      while(1)
      {
        int guess;
        while(1)
        {
          printf("Enter a guess number between 1 to 100 : ");
          scanf("%d",&guess);
          if (guess > 100 || guess < 1 )
          {
            printf("**** Enter a Valid guess between 1 to 100 ****\n");
            continue;
          }
          else
          {
            break;
          }
        }
        
        if (guess>num)
        {
          printf("LOWER!!!\n");
          c=c+1;
        }
        else if (guess<num)
        {
          printf("HIGHER!!!\n");
          c=c+1;
        }
        else
        {
          c=c+1;
          printf("YOU WON!!!!\n");
          printf("You guessed the number\n");
          printf("You took %d chances to guess correctly....\n",c);
          break;
        }
    
      }

    }
    else
    {
      printf("EXITING!!!\n");
      break;
    }
  }
  return 0;
}