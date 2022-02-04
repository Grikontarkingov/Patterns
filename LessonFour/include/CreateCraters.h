#pragma once

#include <memory>
#include "Craters.h"
#include "Crater.h"
#include "WinterCrater.h"

class CreateCraters {
public:
    virtual ~CreateCraters() = default;
    virtual Craters* CreateCrater(int x, int y, uint16_t widthN) = 0;
};

class CreateCraterCommon : public CreateCraters {
public:
    Craters* CreateCrater(int x, int y, uint16_t widthN) override;
};

class CreateCraterWinter : public CreateCraters {
public:
    Craters* CreateCrater(int x, int y, uint16_t widthN) override;
};