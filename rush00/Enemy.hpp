#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "GameEntity.hpp"
#include "ft_retro.h"

class Enemy: public GameEntity
{
  public:
    Enemy();
    Enemy(int n, chtype ustype = '<' | A_BOLD);
    Enemy(Enemy const & copy);
    ~Enemy();
    Enemy & operator=(Enemy const & over);
    Enemy *group;
    GameEntity rockets;
    int count;
    int bullets;
    int current_bullet;
    int lives;
    void makeShooting();
    void clear();
};

#endif
