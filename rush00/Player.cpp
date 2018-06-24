#include <iostream>
#include "Player.hpp"
#include "GameEntity.hpp"

Player::Player() : GameEntity()
{
  std::cout << "Game started!" << std::endl;
  score = 0;
  scoreOnLevel = 0;
  maxScoreOnLevel = 100;
  level = 0;
  lives = 5;
  symb = '#';
  type = "user";
  name = "Player 1";
  bullets = 100;
  x = 0;
  y = 10;
  current_bullet = -1;

  rockets = new GameEntity[bullets];
  int j = 0;
  while (j < bullets)
  {
    rockets[j].type = "rocket";
    rockets[j].x = this->x + 2;
    rockets[j].y = this->y;
    j++;
  }
  std::cout << "Enter your name, please..." << std::endl;
  std::cin >> name;
}

Player::Player(std::string ustype, chtype rsymb) : GameEntity(ustype)
{
  type = ustype;
  game_over = false;
  score = 0;
  scoreOnLevel = 0;
  maxScoreOnLevel = 100;
  level = 0;
  lives = 5;
  symb = '#';
  bullets = 100;
  x = 0;
  y = 10;
  current_bullet = -1;

  rockets = new GameEntity[bullets];
  int j = 0;
  while (j < bullets)
  {
    rockets[j].type = "rocket";
    rockets[j].symb = rsymb;
    rockets[j].x = this->x + 2;
    rockets[j].y = this->y;
    j++;
  }
}

Player::Player(Player const & copy) : GameEntity()
{
  std::cout << "Game started!" << std::endl;
  *this = copy;
}

Player::~Player()
{
  std::cout << "Good bye!" << std::endl;
  return ;
}

Player & Player::operator=(Player const & over)
{
  if (this != &over)
  {
    type = over.type;
    score = over.score;
    scoreOnLevel = over.scoreOnLevel;
    maxScoreOnLevel = over.maxScoreOnLevel;
    level = over.level;
    lives = over.lives;
    symb = over.symb;
    name = over.name;
    bullets = over.bullets;
    x = over.x;
    y = over.y;
    current_bullet = over.current_bullet;
  }
  return (*this);
}

void Player::makeShooting()
{
  if (bullets > 0)
  {
    bullets--;
    if (current_bullet == 100)
      current_bullet = -1;
    rockets[current_bullet].rocketMoving(x + 2, y);
    current_bullet++;
    if (scoreOnLevel >= maxScoreOnLevel)
    {
      level++;
      lives++;
      maxScoreOnLevel += 100;
      scoreOnLevel = 0;
      bullets += 100;
    }
  }
}

void Player::move(int key) {
  if (key == KEY_W)
    y -= (y != 0) ? 2 : 0;
  else if (key == KEY_S)
    y += (y != FIELD_HEIGHT - 2) ? 2 : 0;
  else if (key == KEY_D)
    x += (x != FIELD_WIDTH - 2) ? 2 : 0;
  else if (key == KEY_A)
    x -= (x != 0) ? 2 : 0;
}
