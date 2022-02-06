#pragma once

#include "IHouseBuilder.h"

class HouseDirector {
public:
    void SetBuilder(IHouseBuilder* houseBuilder);

    void BuildHouseDefault();
    void BuildHouseWithPipe();
    void BuildHouseWithOneBigWindow();
    void BuildHouseWithTwoSmallWindows();
    void BuildHouseWithPipeAndOneBigWindow();
    void BuildHouseWithPipeAndTwoSmallWindows();

private:
    IHouseBuilder* pHouseBuilder;
};