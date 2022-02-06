#pragma once

#include "Ground.h"

class GroundWinter : public Ground {
public:
    Crater* CreateCrater() override;
    void Draw() const override;
};