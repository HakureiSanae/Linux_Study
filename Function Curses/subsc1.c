//有运行bug

#include<unistd.h>
#include<stdlib.h>
#include<curses.h>

int main()
{
    WINDOW *sub_window_ptr;
    int x_loop;
    int y_loop;
    int counter;
    char a_letter = '1';

    initscr();      //初始化窗口
    //输出数字
    for(y_loop = 0; y_loop < LINES - 1; y_loop++){
        for(x_loop = 0; x_loop < COLS - 1; x_loop++){
            mvwaddch(stdscr, y_loop, x_loop, a_letter);
            a_letter++;
            if (a_letter > '9') a_letter = '1';
        }
    }
    /*创建一个新的卷动子窗口*/
    sub_window_ptr = subwin(stdscr, 10, 20, 10, 10);
    scrollok(sub_window_ptr, 1);    //卷动子窗口

    touchwin(stdscr);
    refresh();
    sleep(1);
    /*删除子窗口任荣,重新输出*/
    werase(sub_window_ptr);
    mvwprintw(sub_window_ptr, 2, 0, "%s", "This window will now scroll.");
    wrefresh(sub_window_ptr);
    sleep(1);
    //输出文字
    for(counter = 1; counter < 10; counter++){
        wprintw(sub_window_ptr, "%s", "This text is both wrapping and scrolling.");
        wrefresh(sub_window_ptr);
        sleep(1);
    }
    /*删除子窗口, 再次刷新屏幕*/
    delwin(sub_window_ptr);     //删除窗口

    touchwin(stdscr);   //新建窗口
    refresh();          //刷新
    sleep(1);

    endwin();           //结束窗口
    exit(EXIT_SUCCESS);
}
