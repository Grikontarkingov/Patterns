#pragma once

#include <memory>
#include "AbstractCrater.h"
#include "CraterCommon.h"
#include "CraterWinter.h"

class ICraterFactory {
public:
    virtual ~ICraterFactory() = default;
    virtual AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) = 0;
};

class CraterCommonFactory : public ICraterFactory {
public:
    AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) override;
};

class CraterWinterFactory : public ICraterFactory {
public:
    AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) override;
};