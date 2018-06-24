#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "GameEntity.hpp"
#include "ft_retro.h"

class Player: public GameEntity
{
  public:
    Player();
    Player(std::string ustype, chtype rsymb = '>' | A_BOLD);
    Player(Player const & copy);
    ~Player();
    Player & operator=(Player const & over);
    std::string name;
    int score;
    int level;
  //private:
    bool game_over;
    GameEntity *rockets;
    int scoreOnLevel;
    int maxScoreOnLevel;
    int bullets;
    int current_bullet;
    int lives;
    void move(int key);
    void makeShooting();
};

#endif
