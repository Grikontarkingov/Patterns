#pragma once

#include "IBomb.h"
#include "Bomb.h"
#include "ScreenSingleton.h"
#include <memory>

class BombDecorator : public IBomb{
public:
    BombDecorator(IBomb* bomb);

    void Move(uint16_t time) override;
    void Draw() const override;

    void SetPos(double nx, double ny) override;
    double GetY() const override;
    double GetX() const override;
    void SetWidth(uint16_t widthN) override;
    uint16_t GetWidth() const override;



private:
    std::unique_ptr<IBomb> pBomb;
};