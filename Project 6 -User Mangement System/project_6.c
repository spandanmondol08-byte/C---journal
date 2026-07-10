#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct User_List
{
  char username[30];
  char password[30];
}user_list;

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
    else if (ch != '\b')
      {
        password[i++] = ch;
        printf("*");
      }
  }
  password[i] = '\0';
  printf("\n");
}

void registration(user_list users[3],int uno)
{
  getchar();
  printf("Enter the username : ");
  fgets(users[uno].username, 30, stdin);
  users[uno].username[strcspn(users[uno].username,"\n")]='\0';
  printf("Enter the password : ");
  inputPassword(users[uno].password);
}

void login(user_list users[3],int uno)
{
  int found=0;
  char login_un[30];
  char login_pw[30];
  getchar();
  printf("Enter the username : ");
  fgets(login_un, 30, stdin);
  login_un[strcspn(login_un,"\n")]='\0';
  for (int i =0 ; i < uno;i++)
  {
    if (strcmp(login_un,users[i].username)==0)
    {
      printf("Enter the password : ");
      inputPassword(login_pw);
      if (strcmp(login_pw,users[i].password)==0)
      {
        printf("You are logged in successfully !!!\n");
        return;
      }
      else
      {
        printf("Invalid Password!!!\n");
        return;
      }  
    }
    else
    {
      found = 1;
    }
  }
  if (found!=0)
  {
    printf("Username not found !!!!\n");
  }
  
}

int main() {
  printf("-----------------------------WELCOME------------------------------\n");
  int uno = 0;
  user_list users[3];

  while (1)
  {
    int ch ;
    printf("------------------------------------------------------------------\n");
    printf("Enter 1 to REGISTER new user\n");
    printf("Enter 2 to LOGIN existing user\n");
    printf("Enter 3 to EXIT!!\n");
    printf("------------------------------------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    if (ch==1)
    {
      if (uno==3)
      {
        printf("Exceeded maximum limit for number of registration\n");
      }
      else
      {
      registration(users , uno);
      printf("Successfully Registered !!!\n");
      uno++;
      }
      
    }
    else if (ch == 2)
    {
      if (uno==0)
      {
        printf("No Records stored yet !!!\n");
      }
      else
      {
        login(users,uno);
      }
      
    }
    else if (ch==3)
    {
      printf("EXITING!!!!!\n");
      break;
    }
    else
    {
      printf("Enter a valid choice !!!\n");
    }
  }
  

  return 0;
}