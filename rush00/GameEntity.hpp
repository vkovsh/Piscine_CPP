#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

#include <iostream>

class GameEntity
{
  public:
    GameEntity();
    GameEntity(std::string ustype);
    GameEntity(GameEntity const & copy);
    ~GameEntity();
    GameEntity & operator=(GameEntity const & over);
    std::string type;
    int x;
    int y;
    char symb;
    int if_died;
    void rocketMoving(int x1, int y1);
};

#endif
