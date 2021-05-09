#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

const char * test_file = "/tmp/test_lock";

int main()
{
    int file_desc;
    struct flock region_to_lock;
    int res;
    //打开文件描述符
    file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
    if(!file_desc){
        fprintf(stderr, "Unable to open %s for read/write\n", test_file);
        exit(EXIT_FAILURE);
    }
    /*指定文件的不同区域，并尝试在它们上面进行不同锁操作*/
    //第1次设置锁
    region_to_lock.l_type = F_RDLCK;    //读锁(共享锁)
    region_to_lock.l_whence = SEEK_SET; //设置锁
    region_to_lock.l_start = 10;        //从10字节开始
    region_to_lock.l_len = 5;           //长度为5字节
    printf("Process %d trying F_RDLCK, region %d to %d\n", getpid(),
            (int) region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    //检查锁是否设置成功
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d - failed to lock region\n", getpid());
    }
    else{
        printf("Process %d - obtained lcok region\n", getpid());
    }

    //第2次设置锁
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 40;
    region_to_lock.l_len = 10;
    printf("Process %d, trying F_RDLCK, region %d to %d\n", getpid(),
            (int)region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d - failed to lock region\n", getpid());
    }
    else{
        printf("Process %d - obtained lock on region\n", getpid());
    }

    //第3次设置锁
    region_to_lock.l_type = F_WRLCK;    //写锁(独占锁)
    region_to_lock.l_whence = SEEK_SET; //设置锁
    region_to_lock.l_start = 16;
    region_to_lock.l_len = 5;
    printf("Process %d, trying F_WRLCK with wait, region %d to %d\n", getpid(),
            (int) region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
     
    res = fcntl(file_desc, F_SETLKW, &region_to_lock);
   if(res == -1){
        printf("Process %d - failed to lock region\n", getpid());
    }
    else{
        printf("Process %d - obtained lock on region\n", getpid());
    }

    printf("Process %d ending\n", getpid());
    close(file_desc);
    exit(EXIT_SUCCESS);
}
