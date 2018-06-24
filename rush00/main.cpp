#include "ft_retro.h"
#include "Window.hpp"
#include "FieldWindow.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>

void    init_info_window(Window *w) {
    w->PutStr("Game Info", 1, 15);
    w->PutStr("Controls: LEFT UP RIGHT DOWN arrows" , 3, 2);
    w->PutStr("to move and SPACE to shoot.", 4, 2);
    w->PutStr("Press ESC to exit", 5, 2);
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
    w->DrawBox('*' | A_BOLD, '*' | A_BOLD);
    w->Refresh();
}

int	main(void)
{
	initscr();
    FieldWindow gameWindow = FieldWindow(32, 60);
    curs_set(0);
    start_color();
    noecho();
    Player player("nemesis");
    player.name = "nemesis";
    Enemy enemy("zork");
    enemy.x = 25;
    enemy.y = 4;
    player.x = 6;
    player.y = 4;
    player.score = 0;
    Window infoWindow = Window(15, 40, 17, 61);
    init_info_window(&infoWindow);
    Window statWindow = Window(16, 40, 0, 61);
    init_stat_window(&statWindow, &player);
   // int x, y;
    while (true) {
        halfdelay(2);
        gameWindow.GetChar();
        //getmaxyx(stdscr, y, x);
        //gameWindow.Resize(y - 5, x - 5);
        gameWindow.Clear();
        gameWindow.DrawBox('*' | A_BOLD, '*' | A_BOLD);
        gameWindow.drawField();
        gameWindow.PutChar(player.symb | A_BOLD, player.y, player.x);
        gameWindow.PutChar(enemy.symb | A_BOLD, enemy.y, enemy.x);
        if (enemy.x)
            enemy.x -= 2;
        gameWindow.Refresh();
    }
    endwin();
    return 0;
}