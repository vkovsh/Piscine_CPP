#include "ft_retro.h"
#include "Window.hpp"
#include "FieldWindow.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>
#include <sys/ioctl.h>

void    init_info_window(Window *w) {
    w->PutStr("Game Info", 1, 15);
    w->PutStr("Controls: W - UP, D - RIGHT, ", 3, 2);
    w->PutStr("S - DOWN, A - LEFT to move", 4, 12);
    w->PutStr("and SPACE to shoot.", 5, 12);
    w->PutStr("Press ESC to exit", 6, 12);
    w->DrawBox('*' | A_BOLD, '*' | A_BOLD);
    w->Refresh();
}

void    init_stat_window(Window *w, Player *player) {
    w->PutStr("Game Stats", 1, 15);
    w->PutStr("Player name: ", 3, 2);
    w->PutStr(player->name, 3, 15);
    w->PutStr("Level: ", 5, 2);
    w->PutChar((player->level + '0') | A_BOLD | A_STANDOUT, 5, 15);
    w->PutStr("Lives: ", 7, 2);
    w->PutChar((player->lives + '0') | A_BOLD | A_STANDOUT, 7, 15);
    w->PutStr("Score: ", 9, 2);
    mvwprintw(w->getWindow(), 9, 15, "%d", player->score);
    w->PutStr("Rockets: ", 11, 2);
    mvwprintw(w->getWindow(), 11, 15, "%d", player->bullets);
    w->DrawBox('*' | A_BOLD, '*' | A_BOLD);
    w->Refresh();
}

void handle_winch(int sig){
    printf("%d\n", sig);
    signal(SIGWINCH, SIG_IGN);
    endwin();
    initscr();
    refresh();
    clear();
    char tmp[128];
    sprintf(tmp, "Too small! %dx%d", COLS, LINES);
    int x = COLS / 2 - strlen(tmp) / 2;
    int y = LINES / 2 - 1;
    mvaddstr(y, x, tmp);
    refresh();
    signal(SIGWINCH, handle_winch);
}

int	main(void)
{
	initscr();
    curs_set(0);
    start_color();
    noecho();
    signal(SIGWINCH, handle_winch);
    while(true){
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        if (w.ws_row >= RETRO_HEIGHT && w.ws_col >= RETRO_WIDTH)
            break ;
    }
    clear();
    refresh();
    FieldWindow gameWindow = FieldWindow(32, 60);
    Player player("nemesis");
    player.name = "nemesis";
    Enemy enemy("zork");
    enemy.x = 40;
    enemy.y = 4;
    player.x = 0;
    player.y = 0;
    player.score = 0;
    Window infoWindow = Window(11, 40, 21, 61);
    init_info_window(&infoWindow);
    Window statWindow = Window(20, 40, 0, 61);
    init_stat_window(&statWindow, &player);
    keypad(stdscr, true);
   // int x, y;
    halfdelay(2);
    player.current_bullet = -1;
    while (true) {
        int key = gameWindow.GetChar();
        player.move(key);
        if (key == 32) {
            player.makeShooting();
        }
        /*else if (key == KEY_EXIT)
            exit(0);*/
        //getmaxyx(stdscr, y, x);
        //gameWindow.Resize(y - 5, x - 5);
        gameWindow.Clear();
        gameWindow.DrawBox('*' | A_BOLD, '*' | A_BOLD);
        gameWindow.drawField();
        
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        wattron(gameWindow.getWindow(), COLOR_PAIR(3));
        gameWindow.PutChar(player.symb | A_BOLD,
                            player.y + Y_SPLIT, player.x + X_SPLIT);
        wattroff(gameWindow.getWindow(), COLOR_PAIR(3));
        
        init_pair(4, COLOR_RED, COLOR_BLACK);
        wattron(gameWindow.getWindow(), COLOR_PAIR(4));
        gameWindow.PutChar(enemy.symb | A_BOLD, enemy.y, enemy.x);
        wattroff(gameWindow.getWindow(), COLOR_PAIR(4));
        if (enemy.x)
            enemy.x -= 2;

        for (int i = 0; i <= player.current_bullet; ++i) {
            gameWindow.PutChar(player.rockets[i].symb | A_BOLD,
                                player.rockets[i].y + Y_SPLIT,
                                player.rockets[i].x + X_SPLIT);
            player.rockets[i].x += 2;
        }
        gameWindow.Refresh();
    }
    endwin();
    return 0;
}