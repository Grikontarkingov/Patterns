#include "CreateCraters.h"

Craters* CreateCraterCommon::CreateCrater(int x, int y, uint16_t widthN) {
std::unique_ptr<Craters> craters = std::make_unique<Crater>();
craters->SetPos(x, y);
craters->SetWidth(widthN);
return craters.release();
}

Craters* CreateCraterWinter::CreateCrater(int x, int y, uint16_t widthN) {
std::unique_ptr<Craters> craters = std::make_unique<WinterCrater>();
craters->SetPos(x, y);
craters->SetWidth(widthN);
return craters.release();
}