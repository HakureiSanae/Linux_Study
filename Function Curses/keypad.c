#include<unistd.h>
#include<stdlib.h>
#include<curses.h>

#define LOCAL_ESCAPE_KEY 27

int main()
{
    int key;

    initscr();
    crmode();   //进入cbreak模式,读取除DELETE和CTRL以外任何字符
    keypad(stdscr, TRUE);
    noecho();   //控制是否显示在终端上
    clear();
    mvprintw(5, 5, "Key pad demonstration. Press 'q' to quit");
    move(7, 5);
    refresh();
    key = getch();
    
    while(key != ERR & key != 'q'){
        move(7, 5);
        clrtoeol();     //将当前行从光标位置擦除到末尾

        if((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')){
            printw("Key was %c", (char) key);
        }
        else{
            switch(key){
                case LOCAL_ESCAPE_KEY: printw("%s", "Escape key"); break;
                case KEY_END: printw("%s", "END key"); break;
                case KEY_BEG: printw("%s", "BEGINIG key"); break;
                case KEY_RIGHT: printw("%s", "RIGHT key"); break;
                case KEY_LEFT:  printw("%s", "LEFT key"); break;
                case KEY_UP:    printw("%s", "UP key"); break;
                case KEY_DOWN:  printw("%s", "DOWN key"); break;
                default: printw("Unmatched - %d", key); break;
            }
        }//else
        refresh();
        key = getch();
    }//while
    endwin();
    exit(EXIT_SUCCESS);
}
