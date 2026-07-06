// Modify the program above to check whether the file exists or not before
// opening the file.

#include <stdio.h>

int main() {
  FILE * ptr;
  ptr=fopen("file2.txt","r");
  if (ptr==NULL){
    printf("The file does'nt exist!!!");
  }
  else{
    printf("The file is present!!!");
  }

  return 0;
}