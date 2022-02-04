#pragma once

#include "Ground.h"

class GroundWinter : public Ground {
public:
    AbstractCrater* CreateCrater() override;
    void Draw() const override;
};