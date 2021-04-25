#include<unistd.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

#define PW_LEN 256
#define NAME_LEN 256

int main()
{
    char name[NAME_LEN];            //输入的用户名
    char password[NAME_LEN];        //输入的密码
    const char *real_password = "xyzzy";  //正确密码
    int i = 0;

    initscr();      //初始化屏幕
    //提示词
    move(5,10);
    printw("%s", "Please login:");
    //输入用户名
    move(7,10);
    printw("%s", "User name:");
    getstr(name);    

    move(8,10);
    printw("%s", "Password:");
    refresh();      //刷新

    cbreak();   //禁止行缓冲
    noecho();   //输入的字符(密码)不输出在终端上

    memset(password, '\0', sizeof(password)); //分配内存空间
    while(i < PW_LEN){
        password[i] = getch();    //读入密码
        if (password[i] == '\n') break;
        move(8, 20+i);
        addch('*');
        refresh();
        i++;
    }
    echo();       //允许输出
    nocbreak();   //解除行缓冲禁止

    move(11,10);
    if(strncmp(real_password, password, strlen(real_password)) == 0)
        printw("%s", "Correct");
    else
        printw("%s", "Wrong");
    printw("%s", " password");
    refresh();
    sleep(2);

    endwin();     //关闭屏幕
    exit(EXIT_SUCCESS);
}
