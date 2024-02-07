//Name: Krisha Joshi
//PRN:21070122078(CSE-B1)
//Question 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    FILE *fptr;
    fptr=fopen("program.txt","w");
    fprintf(fptr,"This is SYCSC FILE-FISRT PROGRAM");
    fclose(fptr);
    return 0;
}
