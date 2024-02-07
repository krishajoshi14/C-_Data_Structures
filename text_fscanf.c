//Name: Krisha Joshi
//PRN:21070122078(CSE-B1)
//Question 2
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    FILE *fptr;
    if((fptr=fopen("/Users/krishajoshi/Desktop/DS/program.txt","r"))==NULL)
    {
        printf("\nError!opening file\n");
        exit(1);
    }

    fscanf(fptr,"%d",&num);
    printf("\nvalue =%d\n\n",num);
    fclose(fptr);
    return 0;
}