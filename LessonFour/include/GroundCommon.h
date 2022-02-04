#pragma once

#include "Ground.h"

class GroundCommon : public Ground {
public:
    AbstractCrater* CreateCrater() override;
    void Draw() const override;
};