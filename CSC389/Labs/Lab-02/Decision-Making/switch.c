#include <stdio.h> 

int main () 
{  
   /* Local variable definition */
   char grade = 'A';
 
   switch (grade)
  {
    case 'A':
    case 'B':
      printf("Good job!\n"); break;
    case 'C':
    case 'D':
      printf("Pass!\n"); break;
    case 'F':
      printf("Better try again!\n"); break;
    default:
       printf("Invalid grade!\n"); 
   }
    
   printf("Your grade is %c\n", grade);
   return 0; 
}

