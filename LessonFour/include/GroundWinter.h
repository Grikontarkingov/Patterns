#pragma once

#include "Ground.h"

class GroundWinter : public Ground {
public:
    AbstractCrater* CreateCrater(int x, int y) const override;
    void Draw() const override;
};