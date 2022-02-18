#include "Bomb.h"
#include <iostream>
#include "ScreenSingleton.h"

Bomb::Bomb(const Bomb& bomb) {
    this->x = bomb.x + 1;
    this->y = bomb.y;
    this->xDirction = bomb.xDirction;
    this->yDirection = bomb.yDirection;
    this->width = bomb.width;
    this->speed = bomb.speed;
}

DynamicObject* Bomb::Clone() const {
    return new Bomb(*this);
}

void Bomb::Draw() const {
  //ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
  ScreenSingleton::getInstance().GotoXY(x, y);
  std::cout << "*";
}
