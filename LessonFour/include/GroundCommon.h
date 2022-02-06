#pragma once

#include "Ground.h"

class GroundCommon : public Ground {
public:
    Crater* CreateCrater() override;
    void Draw() const override;
};