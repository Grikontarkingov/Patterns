#pragma once

#include <memory>
#include "AbstractCrater.h"
#include "CraterCommon.h"
#include "CraterWinter.h"

class ICraterFactoryMethod {
public:
    virtual ~ICraterFactoryMethod() = default;
    virtual std::unique_ptr<AbstractCrater> FactoryMethod(int x, int y, uint16_t widthN) const = 0;

    AbstractCrater* CreateCrater(int x, int y, uint16_t widthN) const;
};

class CraterCommonFactory : public ICraterFactoryMethod {
public:
    std::unique_ptr<AbstractCrater> FactoryMethod(int x, int y, uint16_t widthN) const override;
};

class CraterWinterFactory : public ICraterFactoryMethod {
public:
    std::unique_ptr<AbstractCrater> FactoryMethod(int x, int y, uint16_t widthN) const override;
};