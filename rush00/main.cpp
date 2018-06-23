#include "ft_retro.h"
#include "Window.hpp"
#include "FieldWindow.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>

int	main(void)
{
	initscr();
    FieldWindow a = FieldWindow(30, 60);
    curs_set(0);
    start_color();
    Player player("player");
    Enemy enemy("zork");
    enemy.x = 25;
    enemy.y = 4;
    FieldWindow b = FieldWindow(30, 40, 0, 61);
    b.DrawBox('*' | A_BOLD, '*' | A_BOLD);
    b.Refresh();
    int x, y;
    while (true) {
        halfdelay(2);
        getmaxyx(stdscr, y, x);
        a.Resize(y - 5, x - 5);
        a.GetChar();
        a.Clear();
        a.DrawBox('*' | A_BOLD, '*' | A_BOLD);
        a.drawField();
        a.PutChar(player.symb, player.y, player.x);
        a.PutChar(enemy.symb, enemy.y, enemy.x);
        if (enemy.x)
            enemy.x -= 2;
        a.Refresh();
    }
    a.GetChar();
    endwin();
    return 0;
}