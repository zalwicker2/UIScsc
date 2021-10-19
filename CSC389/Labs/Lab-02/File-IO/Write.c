#include <stdio.h> 

int main () 
{
    FILE *fp;
 
    fp = fopen("file.txt", "w+");
    fprintf(fp, "%s %s %s %d\n", "We", "are", "in", 2021);
    fputs("Test for fputs...\n", fp);
        
    fclose(fp);

    return 0;
}
