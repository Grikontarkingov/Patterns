#include "ICraterFactoryMethod.h"

AbstractCrater* ICraterFactoryMethod::CreateCrater(int x, int y, uint16_t widthN) const {
    std::unique_ptr<AbstractCrater> craters = std::move(FactoryMethod(x, y, widthN));
    return craters.release();
}

std::unique_ptr<AbstractCrater> CraterCommonFactory::FactoryMethod(int x, int y, uint16_t widthN) const {
    std::unique_ptr<CraterCommon> craters = std::make_unique<CraterCommon>(x, y, widthN);
    return craters;
}

std::unique_ptr<AbstractCrater> CraterWinterFactory::FactoryMethod(int x, int y, uint16_t widthN) const {
    std::unique_ptr<CraterWinter> craters = std::make_unique<CraterWinter>(x, y, widthN);
    return craters;
}