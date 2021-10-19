#include <stdio.h> 

 int main () 
{ 
    int i, j;
    int n[5];  /* n is an array of 10 integers */ 
  
   /* Initialize elements of array n to 0 */
   for(i = 0; i < 5; i++)
  {  
     n[i] = i + 10;
  }

  /* Output each array element's value */
   for (j = 0; j < 5; j++)
  {
    printf("Element[%d] = %d\n", j, n[j]);  
  }

   return 0; 
}

