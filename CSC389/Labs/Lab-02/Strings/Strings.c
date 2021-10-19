#include <stdio.h> 
#include <string.h> 

int main () 
{  

   char str1[20] = "Good ";
   char str2[20] = "Evening";
   char str3[20]; 
   int Length;

   /* Copy str1 into str3 */ 
   strcpy(str3, str1);
   printf("String3: %s\n", str3);

  /* Concatenates str1 and str2 */ 
   strcat (str1, str2);
   printf("New string1: %s\n", str1);

  /* Length of str1 after concatenation */
   Length = strlen(str1);
   printf("Length of new string1: %d\n", Length);

   return 0;
}

