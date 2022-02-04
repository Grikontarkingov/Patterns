#include "Ground.h"
#include "CraterFactoryCreate.h"
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
    vecCrates.push_back(CreateCrater(int(xn), y));
}
