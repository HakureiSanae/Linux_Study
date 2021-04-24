#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>


int main()
{
    const char witch_one[] = " First Witch ";
    const char witch_two[] = "Second Witch ";
    const char *scan_ptr;
  
    initscr();        //初始化屏幕
    
    //以高亮度模式输出
    move(5,15);
    attron(A_BOLD);
    printw("%s", "Macbeth");
    attroff(A_BOLD);
    refresh();
    
    //以强调模式(反白)输出
    move(8,15);
    attron(A_STANDOUT);
    printw("%s", "Thunder and Lighting");
    attroff(A_STANDOUT);
    refresh();
    sleep(1);
    
    //标准模式输出
    move(10, 10);
    printw("%s", "When shall we three meet again");
    move(11, 23);
    printw("%s", "In thunder, lighting, or in rain?");
    move(13,10);
    printw("%s", "When the hurlyburly's done.");
    move(14, 23);
    printw("%s", "When the battle's lost and won.");
    refresh();
    sleep(1);
    
    //插入witch_one和witch_two两个字符串(以A_DIM模式)
    attron(A_DIM);      
    scan_ptr = witch_one + strlen(witch_one) - 1;
    while(scan_ptr != witch_one){
        move(10,10);
        insch(*scan_ptr--);
    }
    scan_ptr = witch_two + strlen(witch_two) - 1;
    while(scan_ptr != witch_two){
        move(13,10);
        insch(*scan_ptr--);
    }
    attroff(A_DIM);
    refresh();
    sleep(1);
    move(LINES-1, COLS-1);
 
    refresh();
    sleep(1);
    
    endwin();       //关闭窗口
    exit(EXIT_SUCCESS);
}

