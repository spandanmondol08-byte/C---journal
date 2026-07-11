#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

typedef struct user_accounts
{
  char account_name[30];
  char password[30];
  int account_number;
  int account_balance;
} uac;

void inputPassword(char password[])
{
  int i = 0;
  char ch;
  while ((ch = getch()) != '\r')   // Enter key
  {
    if (ch == '\b' && i > 0)     // Backspace
      {
        i--;
        printf("\b \b");
      }
    else if (ch != '\b' && i < 29)
      {
        password[i++] = ch;
        printf("*");
      }
  }
  password[i] = '\0';
  printf("\n");
}

void create_account(uac users[3], int n)
{
  FILE *ptr;
  ptr = fopen("Bank_Info.txt", "a");
  fprintf(ptr, "%d\n", n);
  printf("Enter the account Name : ");
  getchar();
  fgets(users[n].account_name, 30, stdin);
  users[n].account_name[strcspn(users[n].account_name, "\n")] = '\0';
  fprintf(ptr, "Name: %s\n", users[n].account_name);
  printf("Enter your password : ");
  inputPassword(users[n].password);
  fprintf(ptr, "Password: %s\n", users[n].password);
  int a = 676900000;
  int rn = rand() % 90000 + 10000;
  users[n].account_number = a + rn;
  fprintf(ptr, "Account Number : %s\n", users[n].account_number);
  users[n].account_balance = 0;
  fprintf(ptr, "Account Balance : %s\n", users[n].account_balance);
  fprintf(ptr, "---------------------------------\n");
  fprintf(ptr, "\n");
  fclose(ptr);
}

int main()
{

  uac users[3];
  int n = 0;
  int ch;
  while (1)
  {

    printf("1) Create Account\n");
    printf("2) Withdraw Money\n");
    printf("3) Deposit Money\n");
    printf("4) EXIT!!!\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    sleep(1);
    if (ch == 1)
    {
      if (n == 3)
      {
        printf("Exceeded maximum limit for number of registration\n");
      }
      else
      {
        srand(time(NULL));
        create_account(users, n);
        n++;
      }
    }
    else if (ch == 2)
    {
    }
    else if (ch == 3)
    {
    }
    else if (ch == 4)
    {
      printf("EXITING !!!\n");
      break;
    }
    else
    {
      printf("Enter valid choice !!!\n");
      sleep(1);
    }
  }

  return 0;
}