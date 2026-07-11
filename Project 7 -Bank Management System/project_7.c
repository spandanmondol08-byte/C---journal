#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

typedef struct user_accounts
{
  int id;
  char account_name_f[30];
  char account_name_l[30];
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
  printf("Enter the first name of account holder : ");
  getchar();
  fgets(users[n].account_name_f, 30, stdin);
  users[n].account_name_f[strcspn(users[n].account_name_f, "\n")] = '\0';
  fprintf(ptr, "First Name: %s\n", users[n].account_name_f);
  printf("Enter the last name of account holder : ");
  fgets(users[n].account_name_l, 30, stdin);
  users[n].account_name_l[strcspn(users[n].account_name_l, "\n")] = '\0';
  fprintf(ptr, "Last Name: %s\n", users[n].account_name_l);
  printf("Enter your password : ");
  inputPassword(users[n].password);
  encrypter(users,n);
  fprintf(ptr, "Password: %s\n", users[n].password);
  fprintf(ptr, "Account Number: %d\n", users[n].account_number);
  fprintf(ptr, "Account Balance: %d\n", users[n].account_balance);
  fprintf(ptr,"---------------------------------\n");
  fprintf(ptr, "\n");
  fclose(ptr);
  printf("\nAccount created successfully!\n\n");
  printf("---------------------------------\n");
  printf("Account Holder Name : %s %s\n", users[n].account_name_f,users[n].account_name_l);
  printf("Account Number : %d\n", users[n].account_number);
  printf("Balance: %d\n", users[n].account_balance);
  printf("---------------------------------\n");
  sleep(2);
}

int login(uac users[30],int n)
{
  while (1)
  {
    int lac;
    printf("Enter your account number : ");
    scanf("%d",&lac);
    int f=0;
    for(int i=0;i<n;i++)
    {
      if(lac=users[i].account_number)
      {
        char lp[30];
        printf("Enter the Password : ");
        inputPassword(lp);
        if (lp=users[i].password)
        {
          printf("You are logged in !!\n");
          break;
        }
        else
        {
          f=1;
          break;
        }
      }
      else
      {
        f=1;
      }
    }
    if (f==1)
    {
      int x ;
      printf("Try again ?\n");
      printf("Enter 1 to TRY AGAIN and 2 to go back to MAIN MENU :");
      scanf("%d",&x);
      if (x==1)
      {
        sleep(1);
        continue;
      }
      else if (x==2)
      {
        return m;
      }
      else
      {
        printf("Invalid Input !!! going back to MAIN MENU\n");
        return m;
      }
    }
    else
    {
      return con;
    }
  }
}

// MAIN 

int main()
{
  srand(time(NULL));
  uac users[30];
  int n;
  FILE *ptr1;
  ptr1=fopen("userno.txt","r");
  fscanf(ptr1,"%d",&n);
  fclose(ptr1);
  FILE *ptr3;
  ptr3=fopen("Bank_Info.txt","r");
  for (int i = 0 ; i < n ; i++)
  {
   fscanf(ptr3,"%d\nFirst Name: %s\nLast Name: %s\nPassword: %s\nAccount Number: %d\nAccount Balance: %d\n---------------------------------\n\n",&users[i].id,users[i].account_name_f,users[i].account_name_l,users[i].password,&users[i].account_number,&users[i].account_balance);
   decrypter(users,i);
  }
  fclose(ptr3);
  int ch;
  while (1)
  {
    printf("---------------------------------\n");
    printf("          BANKING SYSTEM         \n");
    printf("---------------------------------\n");
    printf("1) Create Account\n");
    printf("2) Withdraw Money\n");
    printf("3) Deposit Money\n");
    printf("4) EXIT!!!\n");
    printf("---------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    sleep(1);

    if (ch == 1)
    {
      if (n == 30)
      {
        printf("Exceeded maximum limit for number of registration\n");
      }
      else
      {
        create_account(users, n);
        n++;
        FILE *ptr2;
        ptr2=fopen("userno.txt","w");
        fprintf(ptr2,"%d",n);
        fclose(ptr2);
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
      sleep(1);
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