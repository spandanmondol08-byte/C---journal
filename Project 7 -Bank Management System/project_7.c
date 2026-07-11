#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

typedef struct user_accounts
{
  int id;
  char account_name[30];
  char password[30];
  int account_number;
  int account_balance;
} uac;

void encrypter(uac users[30],int n)
{
  int shift = (users[n].account_number % 9) + 3;
  for(int i = 0 ; users[n].password[i] != '\0';i++)
  {
    users[n].password[i] = users[n].password[i] + shift;
  }
}

void decrypter(uac users[30],int n)
{
  int shift = (users[n].account_number % 9) + 3;
  for(int i = 0 ; users[n].password[i] != '\0';i++)
  {
    users[n].password[i] = users[n].password[i] - shift;
  }
}


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

void create_account(uac users[30], int n)
{
  while (1)
  {
    int a = 676900000;
    int rn = rand() % 90000 + 10000;
    users[n].account_number = a + rn;
    int ok=0;
    for (int i = 0; i < n; i++)
    {
      if (users[i].account_number == users[n].account_number)
      {
        ok=ok+0;
      }
      else
      {
        ok++;
      }
    }
    if (ok==n)
    {
      break;
    }
  }
  users[n].account_balance = 0;
  FILE *ptr;
  ptr = fopen("Bank_Info.txt", "a");
  users[n].id=n+1;
  fprintf(ptr, "%d\n", users[n].id);
  printf("Enter the name of account holder : ");
  getchar();
  fgets(users[n].account_name, 30, stdin);
  users[n].account_name[strcspn(users[n].account_name, "\n")] = '\0';
  fprintf(ptr, "Name: %s\n", users[n].account_name);
  printf("Enter your password : ");
  inputPassword(users[n].password);
  encrypter(users,n);
  fprintf(ptr, "Password: %s\n", users[n].password);
  fprintf(ptr, "Account Number : %d\n", users[n].account_number);
  fprintf(ptr, "Account Balance : %d\n", users[n].account_balance);
  fprintf(ptr, "---------------------------------\n");
  fprintf(ptr, "\n");
  fclose(ptr);
  printf("\nAccount created successfully!\n\n");
  printf("---------------------------------\n");
  printf("Account Holder Name : %s\n", users[n].account_name);
  printf("Account Number : %d\n", users[n].account_number);
  printf("Balance        : %d\n", users[n].account_balance);
  printf("---------------------------------\n");
  sleep(2);
}

int main()
{
  uac users[30];
  int n;
  FILE *ptr1;
  ptr1=fopen("userno.txt","r");
  fscanf(ptr1,"%d",&n);
  int ch;
  while (1)
  {
    printf("1) Create Account\n");
    printf("2) Withdraw Money\n");
    printf("3) Deposit Money\n");
    printf("4) EXIT!!!\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    fclose(ptr1);
    sleep(1);
    if (ch == 1)
    {
      if (n == 30)
      {
        printf("Exceeded maximum limit for number of registration\n");
      }
      else
      {
        srand(time(NULL));
        create_account(users, n);
        n++;
        FILE *ptr1;
        ptr1=fopen("userno.txt","w");
        fprintf(ptr1,"%d",n);
        fclose(ptr1);
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
    else if (scanf("%d", &ch) != 1)
    {
      printf("Invalid input!\n");
      while (getchar() != '\n');   // Clear the input buffer
      continue;
    }
    else
    {
      printf("Enter valid choice !!!\n");
      sleep(1);
    }
  }

  return 0;
}