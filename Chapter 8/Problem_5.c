// Write a program to encrypt a string by adding 1 to the ascii value of its
// characters.

#include <stdio.h>
#include <string.h>

int main()
{
  // ENCRYPTER

  char str[30];
  printf("Enter the string : ");
  gets(str);
  char estr[30];
  for (int i = 0; str[i] != '\0'; i++)
  {
    int a = (int)str[i];
    estr[i] = (char)(a + 1);
  }
  estr[strlen(str)] = '\0';
  printf("The encrypted string : %s\n", estr);
  // Decrypter

  char dstr[30];
  for (int i = 0; estr[i] != '\0'; i++)
  {
    int b = (int)estr[i];
    dstr[i] = (char)(b - 1);
  }
  dstr[strlen(estr)] = '\0';
  printf("The decrypted string : %s\n", dstr);
  return 0;
}