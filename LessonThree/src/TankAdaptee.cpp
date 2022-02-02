#include "TankAdaptee.h"
#include <iostream>
#include "ScreenSingleton.h"

TankAdaptee::TankAdaptee() : m_x(0.0), m_y(0.0), width(0) {}

void TankAdaptee::Paint() {
    ScreenSingleton::getInstance().SetColor(CC_Cyan);
    ScreenSingleton::getInstance().GotoXY(m_x, m_y - 3);
    std::cout << "    #####";
    ScreenSingleton::getInstance().GotoXY(m_x-2, m_y - 2);
    std::cout << "#######   #";
    ScreenSingleton::getInstance().GotoXY(m_x, m_y - 1);
    std::cout << "    #####";
    ScreenSingleton::getInstance().GotoXY(m_x,m_y);
    std::cout << " ###########";
}

bool TankAdaptee::isInRange(double x1, double x2) const {
    const double XBeg = m_x + 2;
    const double XEnd = m_x + width - 1;

    if (x1 < XBeg && x2 > XEnd)
    {
        return true;
    }

    if (x1 > XBeg && x1 < XEnd)
    {
        return true;
    }

    if (x2 > XBeg && x2 < XEnd)
    {
        return true;
    }

    return false;
}

uint16_t TankAdaptee::GetScore() const {
    return score;
}

void TankAdaptee::SetPos(double nx, double ny) {
    m_x = nx;
    m_y = ny;
}
double TankAdaptee::GetY() const {
    return m_y;
}
double TankAdaptee::GetX() const {
    return m_x;
}

void TankAdaptee::SetWidth(uint16_t widthN) {
    width = widthN;
}
uint16_t TankAdaptee::GetWidth() const {
    return width;
}