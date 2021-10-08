#include <stdio.h> 
#include <string.h> 

struct Books
{ 
      char title[50]; 
      char author[50]; 
      char subject[100];
      int  ID;
};

int main() 
{
  struct Books Book1;
 
  /* Book 1 specification */
  strcpy(Book1.title,"C Programming"); 
  strcpy(Book1.author,"Nuha Ali");
  strcpy(Book1.subject,"C Programming Tutorial");
  Book1.ID = 6495407;

  /* Print Book1 info */
  printf("Book 1 title: %s\n", Book1.title);
  printf("Book 1 author: %s\n", Book1.author);
  printf("Book 1 subject: %s\n", Book1.subject);
  printf("Book 1 ID: %d\n", Book1.ID);

  return 0;
}


