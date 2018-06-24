#include <iostream>
#include "GameEntity.hpp"

GameEntity::GameEntity()
{
  //std::cout << "GameEntity Default constructor." << std::endl;
}

GameEntity::GameEntity(std::string ustype)
{
  //std::cout << ustype << "GameEntity Name constructor" << std::endl;

  this->type = ustype;
  this->symb = 'o';
  this->x = 1;
  this->y = 1;
}

GameEntity::GameEntity(GameEntity const & copy)
{
  //std::cout << "GameEntity Copy constructor." << std::endl;
  *this = copy;
}

GameEntity::~GameEntity()
{
  //std::cout << "GameEntity Destructor" << std::endl;
  return ;
}

GameEntity & GameEntity::operator=(GameEntity const & over)
{
  if (this != &over)
  {
    this->type = over.type;
    this->symb = over.symb;
    this->x = over.x;
    this->y = over.y;
  }
  return (*this);
}

void GameEntity::rocketMoving(int x1, int y1)
{
  this->x = x1;
  this->y = y1;
}

/*void GameEntity::clear()
{
  this->symb = 'o';
  this->x = 1;
  this->y = 1;
}*/
