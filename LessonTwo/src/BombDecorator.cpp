#include "BombDecorator.h"
#include <iostream>


BombDecorator::BombDecorator(IBomb* bomb) : pBomb(bomb){}

void BombDecorator::Move(uint16_t time) {
    pBomb->Move(time * 1.6);
}
void BombDecorator::Draw() const {
    pBomb->Draw();
    ScreenSingleton::getInstance().GotoXY(pBomb->GetX(), pBomb->GetY() - 1);
    std::cout << "|";
}

void BombDecorator::SetPos(double nx, double ny) {
    pBomb->SetPos(nx, ny);
}
double BombDecorator::GetY() const {
    return pBomb->GetY();
}
double BombDecorator::GetX() const {
    return pBomb->GetX();
}
void BombDecorator::SetWidth(uint16_t widthN) {
    pBomb->SetWidth(widthN);
}
uint16_t BombDecorator::GetWidth() const {
    return pBomb->GetWidth();
}