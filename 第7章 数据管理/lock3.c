#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

const char * test_file = "/tmp/test_lock";

int main()
{
    int file_desc;
    int byte_count;
    char *byte_to_write = "A";
    struct flock region_1;
    struct flock region_2;
    int res;

    //打开一个文件描述符
    file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
    if(!file_desc){
        fprintf(stderr, "Unable to open %s for read/write\n", test_file);
        exit(EXIT_FAILURE);
    }
    //给文件添加数据
    for(byte_count = 0; byte_count < 100; byte_count++){
        (void) write(file_desc, byte_to_write, 1);
    }
    //把文件10~30字节设置为区域1，并在其上设置共享锁
    region_1.l_type = F_RDLCK;          //共享锁
    region_1.l_whence = SEEK_SET;       //设置
    region_1.l_start = 10;              //从10字节开始
    region_1.l_len = 20;                //长度为20字节
    //把文件的40~50字节设为区域2，并在其上设置独占锁
    region_2.l_type = F_WRLCK;          //独占锁
    region_2.l_whence = SEEK_SET;       //设置
    region_2.l_start = 40;              //从40字节开始
    region_2.l_len = 10;                //长度为10字节

    sleep(10);
    printf("Process %d closing file\n", getpid());
    close(file_desc);
    exit(EXIT_SUCCESS);
}
