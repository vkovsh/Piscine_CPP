#include "ft_retro.h"
#include "Window.hpp"
#include "FieldWindow.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>
#include <sys/ioctl.h>

void    init_info_window(Window *w) {
    w->Clear();
    w->PutStr("Game Info", 1, 15);
    w->PutStr("Controls: W - UP, D - RIGHT, ", 3, 2);
    w->PutStr("S - DOWN, A - LEFT to move", 4, 12);
    w->PutStr("and SPACE to shoot.", 5, 12);
    w->PutStr("Press ESC to exit", 6, 12);
    w->DrawBox('*' | A_BOLD, '*' | A_BOLD);
    w->Refresh();
}

void    init_stat_window(Window *w, Player *player) {
    w->Clear();
    w->PutStr("Game Stats", 1, 15);
    w->PutStr("Player name: ", 3, 2);
    w->PutStr(player->name, 3, 15);
    w->PutStr("Level: ", 5, 2);
    w->PutChar((player->level + '0') | A_BOLD | A_STANDOUT, 5, 15);
    w->PutStr("Lives: ", 7, 2);
    mvwprintw(w->getWindow(), 7, 15, "%d", player->lives);
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

void  waiting_for_start(FieldWindow *w) {
  init_pair(5, COLOR_RED, COLOR_BLACK);
  wattron(w->getWindow(), COLOR_PAIR(5));
  w->PutStr("Press any key to start", w->getRows() / 3, w->getColumns() / 2);
  w->GetChar();
  wattroff(w->getWindow(), COLOR_PAIR(5));
}

void fill_coords(Enemy &enemy)
{
  int i = 0;
  int j = 0;

  while (i < enemy.group[0].count)
  {
    j = 0;
    while (j < enemy.group[0].count)
    {
      enemy.group[i].rockets.rocketMoving(enemy.group[i].x - 2, enemy.group[i].y);
      j++;
    }
    i++;
  }
}

int enemies_shooting(Player &player, Enemy &enemy, FieldWindow &gameWindow, bool flag, int *enemies)
{
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < enemy.group[0].count)
  {
    if (enemy.group[i].x > 3 && !enemy.group[i].if_died)
      gameWindow.PutChar(enemy.group[i].symb | A_BOLD, enemy.group[i].y, enemy.group[i].x);
    else
      (*enemies)--;
    if (*enemies <= 0)
    {
      std::srand(time(NULL));
      *enemies = 3 + rand() % 10;
      k = 0;
      while (k < 12)
      {
      enemy.group[k].count = *enemies;
        k++;
      }
      fill_coords(enemy);
      enemy.clear();
    }
    if (enemy.group[i].rockets.x > 3 && !enemy.group[i].if_died && !enemy.group[i].rockets.if_died)
      gameWindow.PutChar(enemy.group[i].rockets.symb | A_BOLD, enemy.group[i].rockets.y, enemy.group[i].rockets.x);
    else
    {
      j = 0;
      while (j < enemy.group[0].count)
      {
        enemy.group[j].rockets.x = enemy.group[j].x;
        enemy.group[j].rockets.y = enemy.group[j].y;
        j++;
      }
    }
    if (player.x == enemy.group[i].rockets.x && player.y == enemy.group[i].rockets.y)
      player.lives--;
    if (player.lives == 0)
    {
      gameWindow.PutStr("GAME OVER: ", 29, 25);
      return (0);
    }
    if ((player.y == enemy.group[i].y && (player.x == enemy.group[i].x + 1 || player.x == enemy.group[i].x - 1))
    || ((player.y == enemy.group[i].y + 1 || player.y == enemy.group[i].y - 1) && player.x == enemy.group[i].x))
      player.lives--;
    if (player.lives == 0)
    {
      gameWindow.PutStr("GAME OVER: ", 29, 25);
      return (0);
    }
    enemy.group[i].rockets.x -= 2;
    if (flag)
        enemy.group[i].x -= 2;
    i++;
  }
  return (1);
}

int	main(void)
{
    std::srand(time(NULL));
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
    waiting_for_start(&gameWindow);
    Player player("nemesis");
    player.name = "nemesis";
    Window infoWindow = Window(11, 40, 21, 61);
    Window statWindow = Window(20, 40, 0, 61);
    player.current_bullet = 0;
    
    int enemies = 3 + rand() % 10;
    int copy_en = enemies;
    Enemy enemy(12);
    fill_coords(enemy);
    bool enemy_render = true;
    nodelay(gameWindow.getWindow(), true);
    raw();
    player.game_over = false;
    while (true) {
        if (player.lives <= 0)
          player.game_over = true;
        while (!player.game_over){
          usleep(7 * MICROSECONDS_BY_FRAME);
          int key = gameWindow.GetChar();
        if (key == KEY_SPACE) {
            player.makeShooting();
        }
        else if (key == KEY_ESC) {
          endwin();
          return 0;
        }
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
        int j = 0;
        while (j < 12)
        {
          enemy.group[j].count = enemies;
          j++;
        }
        int k = 0;
        enemies_shooting(player, enemy, gameWindow, enemy_render, &copy_en);
        enemy_render = !enemy_render;
        wattroff(gameWindow.getWindow(), COLOR_PAIR(4));

         j = 0;
        for (int i = 0; i < player.current_bullet; ++i) {

            gameWindow.PutChar(player.rockets[i].symb | A_BOLD,
                                player.rockets[i].y + Y_SPLIT,
                                player.rockets[i].x + X_SPLIT);
            j = 0;
            while (j < enemies)
            {
              if (player.rockets[i].y == enemy.group[j].y && (player.rockets[i].x == enemy.group[j].x
                || player.rockets[i].x == enemy.group[j].x - 2 || player.rockets[i].x == enemy.group[j].x + 2))
                {
                  if (j + 2 < enemies)
                    enemy.group[j + 2].if_died = 1;
                  player.score += 10;
                  player.scoreOnLevel += 10;
                  copy_en--;
                  if (copy_en <= 0)
                  {
                    std::srand(time(NULL));
                    enemies = 3 + rand() % 10;
                    copy_en = enemies;
                    k = 0;
                    while (k < 12)
                    {
                      enemy.group[k].count = enemies;
                      k++;
                    }
                    fill_coords(enemy);
                    enemy.clear();
                  }

                }
                if (player.rockets[i].y == enemy.group[j].rockets.y &&
                  (player.rockets[i].x == enemy.group[j].rockets.x - 2 ||
                  player.rockets[i].x == enemy.group[j].rockets.x + 2))
                  {
                    enemy.group[j].rockets.if_died = 1;
                    player.score += 5;
                    player.scoreOnLevel += 5;
                  }
              j++;
            }
            player.rockets[i].x += 2;
        }
        player.move(key);
        init_info_window(&infoWindow);
        init_stat_window(&statWindow, &player);
        gameWindow.Refresh();
    }
    }
    endwin();
    return 0;
}