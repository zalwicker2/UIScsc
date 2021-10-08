#include <stdio.h> 

 int main () 
{
    /* Local variable definition */ 
    int x = 20;
    int y = 10;
 
    /* Check the boolean condition */
    if( x < y ) 
    { 
        /* If condition is true then print the following */ 
        printf("x is less than y!\n");
    }
    else
   {
      /* If condition is false then print the following */
      printf("x is greater than y!\n");
   }
 
   printf("Values of x and y are: %d, %d\n", x, y);
   
   return 0;
}
