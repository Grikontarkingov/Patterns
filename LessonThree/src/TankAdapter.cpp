#include "TankAdapter.h"

TankAdapter::TankAdapter(TankAdaptee* tank) : pTank(tank) {}

void TankAdapter::SetPos(double nx, double ny) {
    pTank->SetPos(nx, ny);
}
double TankAdapter::GetY() const {
    return pTank->GetY();
}
double TankAdapter::GetX() const {
    return pTank->GetX();
}

void TankAdapter::SetWidth(uint16_t widthN) {
    pTank->SetWidth(widthN);
}
uint16_t TankAdapter::GetWidth() const {
    return pTank->GetWidth();
}

uint16_t TankAdapter::GetScore() const {
    return pTank->GetScore();
}

void TankAdapter::Draw() const {
    pTank->Paint();
}
bool TankAdapter::isInside(double x1, double x2) const {
    return pTank->isInRange(x1, x2);
}