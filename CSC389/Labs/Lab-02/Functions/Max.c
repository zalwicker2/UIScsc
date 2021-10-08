#include <stdio.h> 

/* Function declaration */ 
int max(int num1, int num2); 

int main () 
{  
   /* Local variable definition */
   int a = 300; int b = 200;  int ret; 

  /* Calling a function to get max value */ 
   ret = max(a, b); 

   printf( "Max value is : %d\n", ret);
   return 0; 
}

/* Defining a function returning the max between two numbers */ 

int max(int num1, int num2) 
{ 
   /* Local variable declaration */ 
   int result; 

   if (num1 > num2) 
     result = num1; 
   
   else 
     result = num2;

   return result; 
} 


