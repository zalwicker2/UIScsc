#include <stdio.h>

 int main () 
{
    /* Actual variable declaration */ 
    int var = 20;

   /* Pointer variable declaration */ 
   int *ip;

   /* Store address of var in pointer variable */ 
   ip = &var;

   printf("Address of var variable: %x\n", &var);

   /* Address stored in pointer variable */    
   printf("Address stored in ip variable: %x\n", ip);

   /* Access the value using the pointer */    
   printf("Value of *ip variable: %d\n", *ip);

   return 0; 
}

