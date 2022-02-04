#pragma once

#include <memory>
#include "AbstractCrater.h"
#include "CraterCommon.h"
#include "CraterWinter.h"

class CraterFactoryCreate {
public:
    virtual ~CraterFactoryCreate() = default;
    virtual AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) = 0;
};

class CreateCraterCommon : public CraterFactoryCreate {
public:
    AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) override;
};

class CreateCraterWinter : public CraterFactoryCreate {
public:
    AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) override;
};