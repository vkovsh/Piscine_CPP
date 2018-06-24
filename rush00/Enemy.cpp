#include <iostream>
#include "GameEntity.hpp"
#include "Enemy.hpp"

Enemy::Enemy() : GameEntity(){}

Enemy::Enemy(int n, chtype rsymb) : GameEntity()
{
  int i = 0;
	group = new Enemy[n];
	while (i < n)
  {
    group[i].if_died = 0;
    group[i].count = n;
    group[i].symb = rand() % 26 + 65;
    group[i].lives = 1;
    group[i].x = 54;
    std::srand(i);
    group[i].y = rand() % 12;
    group[i].y += i;
    bullets = 100 / n;
    current_bullet = 0;
    group[i].rockets.symb = rsymb;
    group[i].rockets.x = group[i].x - 2;
    group[i].rockets.y = group[i].y;
    group[i].rockets.if_died = 0;
    i++;
  }
}

Enemy::Enemy(Enemy const & copy) : GameEntity()
{
  *this = copy;
}

Enemy::~Enemy(){}

Enemy & Enemy::operator=(Enemy const & over)
{
  if (this != &over)
  {
    symb = over.symb;
    lives = over.lives;
    x = over.x;
    y = over.y;
    bullets = over.bullets;
    current_bullet = over.current_bullet;
    if_died = over.if_died;
    rockets = over.rockets;
  }
  return (*this);
}

void Enemy::makeShooting()
{
  if (bullets > 0)
  {
    bullets--;
    rockets.rocketMoving(x - 2, y);
    current_bullet++;
  }
}

void Enemy::clear()
{
  int i = 0;
  while (i < group[0].count)
  {
    group[i].if_died = 0;
    group[i].symb = rand() % 26 + 65;
    group[i].lives = 1;
    group[i].x = 54;
    std::srand(i);
    group[i].y = rand() % 12;
    group[i].y += i;
    //y1 += 2;
    this->bullets = 100 / group[0].count;
    this->current_bullet = 0;
    group[i].rockets.x = group[i].x - 2;
    group[i].rockets.y = group[i].y;
    group[i].rockets.if_died = 0;
    i++;
  }
}
