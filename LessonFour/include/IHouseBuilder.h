#pragma once

#include <memory>
#include "House.h"

class IHouseBuilder {
public:
    virtual ~IHouseBuilder() = default;
    virtual void BuildSomeFloor(uint16_t indexOfFloor) = 0;
    virtual void BuildWalls() = 0;
    virtual void BuildRoof() = 0;
    virtual void BuildPipe() = 0;
    virtual void BuildTwoSmallWindows() = 0;
    virtual void BuildOneBigWindow() = 0;
    virtual House* GetHouse() = 0;
};

class HouseBuilder : public IHouseBuilder {
public:
    HouseBuilder();

    void BuildSomeFloor(uint16_t indexOfFloor) override;
    void BuildWalls() override;
    void BuildRoof() override;
    void BuildPipe() override;
    void BuildTwoSmallWindows() override;
    void BuildOneBigWindow() override;

    House* GetHouse() override;

    void Reset();

private:
    std::unique_ptr<House> pHouse;
};