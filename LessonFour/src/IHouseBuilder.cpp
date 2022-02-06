#include "IHouseBuilder.h"
#include <string>

HouseBuilder::HouseBuilder() {
    Reset();
}

void HouseBuilder::BuildSomeFloor(uint16_t indexOfFloor) {
    std::string temp = "############";
    std::copy(temp.begin(), temp.end(), pHouse->look[indexOfFloor]);
}
void HouseBuilder::BuildWalls() {
    std::string temp = "#          #";
    std::copy(temp.begin(), temp.end(), pHouse->look[6]);
    std::copy(temp.begin(), temp.end(), pHouse->look[5]);
    std::copy(temp.begin(), temp.end(), pHouse->look[4]);
}
void HouseBuilder::BuildRoof() {
    std::string temp = "##        ##";
    std::copy(temp.begin(), temp.end(), pHouse->look[2]);
    temp = "  ########  ";
    std::copy(temp.begin(), temp.end(), pHouse->look[1]);
}
void HouseBuilder::BuildPipe() {
    std::string temp = "       #    ";
    std::copy(temp.begin(), temp.end(), pHouse->look[0]);
}
void HouseBuilder::BuildTwoSmallWindows() {
    std::string temp = "# ##    ## #";
    std::copy(temp.begin(), temp.end(), pHouse->look[5]);
}
void HouseBuilder::BuildOneBigWindow() {
    std::string temp = "#   ####   #";
    std::copy(temp.begin(), temp.end(), pHouse->look[5]);
}

void HouseBuilder::Reset() {
    pHouse = std::make_unique<House>();
}

House* HouseBuilder::GetHouse() {
std::unique_ptr<House> result = std::move(pHouse);
Reset();
return result.release();
}