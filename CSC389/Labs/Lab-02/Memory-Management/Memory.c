#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main () 
{  
   char CourseNo[100];
   char *description;

   strcpy(CourseNo, "CSC389");
 
  /* Allocate memory dynamically */ 
   description = malloc (30 * sizeof(char));
   if (description == NULL)
  {
    fprintf(stderr, "Error-unable to allocate required memory\n");    
  }
  else
  {
    strcpy(description, "Introduction to Operating Systems.");
  }

  /* Suppose bigger description are wanted */ 
  description = realloc (description, 100*sizeof (char));

  if (description == NULL)
  {
    fprintf(stderr, "Error-unable to allocate required memory\n");
  }
  else
  {
    strcat(description, "Lecture 03.");    
  }
  
  printf("CourseNo: %s\n", CourseNo);
  printf("Description: %s\n", description);

  /* Release memory using free() function */
  free(description);
 }
