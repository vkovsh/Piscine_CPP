#include <iostream>
#include "Player.hpp"
#include "GameEntity.hpp"

Player::Player() : GameEntity()
{
  std::cout << "Game started!" << std::endl;
  this->score = 0;
  this->scoreOnLevel = 0;
  this->maxScoreOnLevel = 100;
  this->level = 0;
  this->lives = 5;
  this->symb = '#';
  this->type = "user";
  this->name = "Player 1";
  this->bullets = 100;
  this->x = 4;
  this->y = 14;
  this->current_bullet = -1;

  this->rockets = new GameEntity[bullets];
  int j = 0;
  while (j < bullets)
  {
    this->rockets[j].type = "rocket";
    this->rockets[j].symb = 'o';
    this->rockets[j].x = this->x + 2;
    this->rockets[j].y = this->y;
    j++;
  }
  std::cout << "Enter your name, please..." << std::endl;
  std::cin >> name;
}

Player::Player(std::string ustype) : GameEntity(ustype)
{
  //std::cout << "Game started!" << std::endl;
  this->type = ustype;
  this->score = 0;
  this->scoreOnLevel = 0;
  this->maxScoreOnLevel = 100;
  this->level = 0;
  this->lives = 5;
  this->symb = '#';
  this->bullets = 100;
  this->x = 4;
  this->y = 14;
  this->current_bullet = -1;

  this->rockets = new GameEntity[bullets];
  int j = 0;
  while (j < bullets)
  {
    this->rockets[j].type = "rocket";
    this->rockets[j].symb = 'o';
    this->rockets[j].x = this->x + 2;
    this->rockets[j].y = this->y;
    j++;
  }
  //std::cout << "Enter your name, please..." << std::endl;
  //std::cin >> name;
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
    this->type = over.type;
    this->score = over.score;
    this->scoreOnLevel = over.scoreOnLevel;
    this->maxScoreOnLevel = over.maxScoreOnLevel;
    this->level = over.level;
    this->lives = over.lives;
    this->symb = over.symb;
    this->name = over.name;
    this->bullets = over.bullets;
    this->x = over.x;
    this->y = over.y;
    this->current_bullet = over.current_bullet;
  }
  return (*this);
}

void Player::makeShooting()
{
  int j = 0;

  if (this->bullets > 0)
  {
    this->bullets--;
    if (this->current_bullet == 100)
      this->current_bullet = -1;
    rockets[current_bullet].rocketMoving(this->x + 2, this->y);
    this->current_bullet++;
    this->score += 5;
    this->scoreOnLevel += 5;
    if (this->scoreOnLevel == this->maxScoreOnLevel)
    {
      this->level++;
      this->lives++;
      this->maxScoreOnLevel += 100;
      this->scoreOnLevel = 0;
      this->bullets += 100;
      std::cout << "You riched " << this->level << " level!\n"
                << "Your ammunition was raised to " << this->bullets << "!" << std::endl;
    }
  }
  else if (this->bullets == 0)
  {
    std::cout << "Game over! Bullets ended before you won all enemies! Try again!" << std::endl;
    this->score = 0;
    this->scoreOnLevel = 0;
    this->maxScoreOnLevel = 100;
    this->level = 0;
    this->lives = 5;
    this->symb = '#';
    this->bullets = 100;
    this->x = 0;
    this->y = 0;
    this->current_bullet = -1;
    j = 0;
    while (j < bullets)
    {
      this->rockets[j].x = this->x + 2;
      this->rockets[j].y = this->y;
      j++;
    }
  }
  else if (this->lives == 0)
  {
    std::cout << "Game over! Your player died. Try again!" << std::endl;
    this->score = 0;
    this->scoreOnLevel = 0;
    this->maxScoreOnLevel = 100;
    this->level = 0;
    this->lives = 5;
    this->symb = '#';
    this->bullets = 100;
    this->x = 4;
    this->y = 14;
    this->current_bullet = -1;
    j = 0;
    while (j < bullets)
    {
      this->rockets[j].x = this->x + 2;
      this->rockets[j].y = this->y;
      j++;
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
