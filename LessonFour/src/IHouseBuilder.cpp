#include "IHouseBuilder.h"

HouseBuilder::HouseBuilder() {
    Reset();
}

void HouseBuilder::BuildSomeFloor(uint16_t indexOfFloor) {
strncpy(pHouse->look[indexOfFloor], "############", sizeof (pHouse->look[indexOfFloor]));
}
void HouseBuilder::BuildWalls() {
strncpy(pHouse->look[6], "#          #", sizeof pHouse->look[6]);
strncpy(pHouse->look[5], "#          #", sizeof pHouse->look[5]);
strncpy(pHouse->look[4], "#          #", sizeof pHouse->look[4]);
}
void HouseBuilder::BuildRoof() {
strncpy(pHouse->look[2], "##        ##", sizeof pHouse->look[2]);
strncpy(pHouse->look[1], "  ########  ", sizeof pHouse->look[1]);
}
void HouseBuilder::BuildPipe() {
strncpy(pHouse->look[0], "       #    ", sizeof pHouse->look[0]);
}
void HouseBuilder::BuildTwoSmallWindows() {
strncpy(pHouse->look[5], "# ##    ## #", sizeof pHouse->look[5]);
}
void HouseBuilder::BuildOneBigWindow() {
strncpy(pHouse->look[5], "#   ####   #", sizeof pHouse->look[5]);
}

void HouseBuilder::Reset() {
    pHouse = std::make_unique<House>();
}

House* HouseBuilder::GetHouse() {
std::unique_ptr<House> result = std::move(pHouse);
Reset();
return result.release();
}