#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "GameEntity.hpp"

class Enemy: public GameEntity
{
  public:
    Enemy();
    Enemy(std::string ustype);
    Enemy(int n, std::string ustype);
    Enemy(Enemy const & copy);
    ~Enemy();
    Enemy & operator=(Enemy const & over);
    Enemy *group;
    GameEntity *rockets;
    int count;
    int bullets;
    int current_bullet;
    int lives;
    void makeShooting();
    void clear();
};

#endif
