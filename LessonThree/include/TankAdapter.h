#pragma once

#include "TankAdaptee.h"
#include "DestroyableGroundObject.h"

class TankAdapter : public DestroyableGroundObject {
public:
    TankAdapter(TankAdaptee* tank);

    void SetPos(double nx, double ny) override;
    double GetY() const override;
    double GetX() const override;

    void SetWidth(uint16_t widthN) override;
    uint16_t GetWidth() const override;

    uint16_t GetScore() const override;

    void Draw() const override;
    bool isInside(double x1, double x2) const override;

private:
    TankAdaptee* pTank;
};