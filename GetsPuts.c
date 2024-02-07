//Name: Krisha Joshi(CSE-B1)
//PRN:21070122078
//Question 3

#include <stdio.h>
int main() 
{
    FILE *fptr;
    char str[] = "Using fgets() and fputs() functions.\n";
    char buffer[100];
    fptr = fopen("function.txt", "w");  
    if (fptr != NULL) 
    {
        fputs(str, fptr);
        fclose(fptr);
    }
    fptr = fopen("function.txt", "r");    
    if (fptr != NULL) 
    {
        fgets(buffer, 100, fptr);
        printf("\n%s\n", buffer);
        fclose(fptr);
    }
    return 0;
}






































