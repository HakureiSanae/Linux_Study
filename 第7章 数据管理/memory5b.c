//空指针
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char z = * (const char *) 0;
    printf("I read from location zero\n");
    exit(EXIT_SUCCESS);   
}
