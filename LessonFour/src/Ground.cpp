#include "Ground.h"
#include "CreateCraters.h"
#include "enums/CraterSize.h"
#include <cstring>

bool Ground::isInsideAnyCrater(double x) const
{
    bool isInside = false;
    for (size_t i = 0; i < vecCrates.size(); i++)
    {
        if (vecCrates[i]->isInside(x))
        {
            isInside = true;
            break;
        }
    }

    return isInside;
}

void Ground::AddCrater(double xn)
{
    CreatCraterWinter* creatCraterWinter = new CreatCraterWinter;

    CreateCraters* createCraters;
    createCraters = creatCraterWinter;
    vecCrates.push_back(createCraters->CreateCrater(int(xn), y, WINTER_CRATER_SIZE));
}
