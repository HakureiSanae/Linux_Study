#include<unistd.h>
#include<stdlib.h>
#include<curses.h>

int main()
{
    initscr();                  //初始化屏幕    

    move(5, 15);               //移动光标至坐标(行, 列)
    printw("%s", "Hello World");    //在屏幕中输出
    refresh();                      //刷新屏幕
    sleep(2);                       //睡眠2s

    endwin();                       //退出窗口
    exit(EXIT_SUCCESS);             //fork时只终止该子进程,而不会终止父进程和其他子进程
}
