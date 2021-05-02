#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define A_MEGABYTE (1024 * 1024)    //内存大小为1MB

int main()
{
    char *some_memory;
    int megabyte = A_MEGABYTE;
    int exit_code = EXIT_FAILURE;

    some_memory = (char *) malloc(megabyte);    //void *需要转换为目标指针
    if(some_memory){
        sprintf(some_memory, "Hello World!\n");
        printf("%s", some_memory);
        exit_code = EXIT_SUCCESS;
    }
    exit(exit_code);
}
