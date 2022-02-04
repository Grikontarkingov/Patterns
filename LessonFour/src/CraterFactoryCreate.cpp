#include "CraterFactoryCreate.h"

AbstractCrater* CreateCraterCommon::CreateCrater(int x, int y, uint16_t widthN) {
std::unique_ptr<AbstractCrater> craters = std::make_unique<CraterCommon>();
craters->SetPos(x, y);
craters->SetWidth(widthN);
return craters.release();
}

AbstractCrater* CreateCraterWinter::CreateCrater(int x, int y, uint16_t widthN) {
std::unique_ptr<AbstractCrater> craters = std::make_unique<CraterWinter>();
craters->SetPos(x, y);
craters->SetWidth(widthN);
return craters.release();
}