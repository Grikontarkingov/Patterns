#include "HouseDirector.h"

void HouseDirector::SetBuilder(IHouseBuilder* houseBuilder) {
    pHouseBuilder = houseBuilder;
}

void HouseDirector::BuildHouseDefault() {
    pHouseBuilder->BuildSomeFloor(7);
    pHouseBuilder->BuildWalls();
    pHouseBuilder->BuildSomeFloor(3);
    pHouseBuilder->BuildRoof();
}
void HouseDirector::BuildHouseWithPipe() {
    BuildHouseDefault();
    pHouseBuilder->BuildPipe();
}
void HouseDirector::BuildHouseWithOneBigWindow() {
    BuildHouseDefault();
    pHouseBuilder->BuildOneBigWindow();
}
void HouseDirector::BuildHouseWithTwoSmallWindows() {
    BuildHouseDefault();
    pHouseBuilder->BuildTwoSmallWindows();
}
void HouseDirector::BuildHouseWithPipeAndOneBigWindow() {
    BuildHouseDefault();
    pHouseBuilder->BuildPipe();
    pHouseBuilder->BuildOneBigWindow();
}
void HouseDirector::BuildHouseWithPipeAndTwoSmallWindows() {
    BuildHouseDefault();
    pHouseBuilder->BuildPipe();
    pHouseBuilder->BuildTwoSmallWindows();
}