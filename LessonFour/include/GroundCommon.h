#pragma once

#include "Ground.h"

class GroundCommon : public Ground {
public:
    AbstractCrater* CreateCrater(int x, int y) const override;
    void Draw() const override;
};