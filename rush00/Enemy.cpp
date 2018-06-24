#include <iostream>
#include "GameEntity.hpp"
#include "Enemy.hpp"

Enemy::Enemy() : GameEntity()
{
  //std::cout << "Enemy Default constructor." << std::endl;
}

Enemy::Enemy(std::string ustype) : GameEntity()
{
  int j = 0;
  //std::cout << "Enemy Name constructor" << std::endl;

  this->type = ustype;
  this->count = 1;
  this->symb = 'X';
  this->lives = 3;
  this->x = 54;
  this->y = 4;
  this->bullets = 100;
  this->current_bullet = 0;
  this->rockets = new GameEntity[bullets];
  while (j < bullets)
  {
    this->rockets[j].type = "rocket";
    this->rockets[j].symb = 'o';
    this->rockets[j].x = this->x - 2;
    this->rockets[j].y = this->y;
    j++;
  }
}

Enemy::Enemy(int n, std::string ustype) : GameEntity()
{
  int i = 0;
  int j = 0;
  //std::cout << ustype << "Enemy Name constructor" << std::endl;
  int x = 54;
  int y0 = 16;
  int y1 = 14;
	group = new Enemy[n];
	while (i < n)
  {
    group[i].count = n;
    group[i].type = ustype;
    group[i].symb = 'X';
    group[i].lives = 3;
    group[i].x = x;
    if ((i % 2) == 0)
    {
      group[i].y = y0;
      y0 += 2;
    }
    else
    {
      group[i].y = y1;
      y1 -= 2;
    }
    this->bullets = 100 / n;
    this->current_bullet = 0;
    group[i].rockets = new GameEntity[bullets];
    j = 0;
    while (j < bullets)
    {
      group[i].rockets[j].type = "rocket";
      group[i].rockets[j].symb = 'o';
      group[i].rockets[j].x = group[i].x - 2;
      group[i].rockets[j].y = group[i].y;
      j++;
    }
    i++;
  }
}

Enemy::Enemy(Enemy const & copy) : GameEntity()
{
  //std::cout << "Enemy Copy constructor." << std::endl;
  *this = copy;
}

Enemy::~Enemy()
{
  //std::cout << "Enemy Destructor" << std::endl;
  return ;
}

Enemy & Enemy::operator=(Enemy const & over)
{
  if (this != &over)
  {
    this->type = over.type;
    this->symb = over.symb;
    this->lives = over.lives;
    this->x = over.x;
    this->y = over.y;
    this->bullets = over.bullets;
    this->current_bullet = over.current_bullet;
  }
  return (*this);
}

void Enemy::makeShooting()
{
  if (this->bullets > 0)
  {
    this->bullets--;
    rockets[this->current_bullet].rocketMoving(this->x - 2, this->y);
    this->current_bullet++;
  }
}

/*void Enemy::clear()
{
  while (i < group[i].count)
  {
    group[i].symb = 'X';
    group[i].lives = 3;
    group[i].x = 1;
    group[i].y = 1;
    this->bullets = 100 / n;
    this->current_bullet = 0;
    group[i].rockets = new GameEntity[bullets];
    j = 0;
    while (j < bullets)
    {
      group[i].rockets[j].type = "rocket";
      group[i].rockets[j].symb = 'o';
      group[i].rockets[j].x = group[i].x + 1;
      group[i].rockets[j].y = group[i].y;
      j++;
    }
    i++;
  }
}*/
