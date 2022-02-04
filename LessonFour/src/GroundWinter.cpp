#include "GroundWinter.h"
#include <cstring>
#include <iostream>
#include "ScreenSingleton.h"
#include "CraterFactoryCreate.h"
#include "enums/CraterSize.h"

void GroundWinter::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_Blue);

    const size_t bufSize = width + 1;
    char* buf = new (std::nothrow) char[bufSize];
    if (buf == nullptr)
    {
        return;
    }

    if (vecCrates.size() == 0)
    {
        ScreenSingleton::getInstance().GotoXY(x, y);
        memset(buf, '=', bufSize);
        buf[bufSize - 1] = '\0';
        std::cout << buf;
    }
    else
    {
        const size_t X = size_t(x);
        char c;
        for (size_t i = X; i < width + X; i++)
        {
            c = (isInsideAnyCrater((double)i)) ? ' ' : '=';
            buf[i - X] = c;
        }

        ScreenSingleton::getInstance().GotoXY((double)X, y);
        buf[bufSize-1] = '\0';
        std::cout << buf;

        for (size_t i = 0; i < vecCrates.size(); i++)
        {
            vecCrates[i]->Draw();
        }
    }

    delete[] buf;
}

AbstractCrater* GroundWinter::CreateCrater(int x, int y) const {
    CreateCraterWinter* creatCraterWinter = new CreateCraterWinter;

    CraterFactoryCreate* createCraters;
    createCraters = creatCraterWinter;

    return createCraters->CreateCrater(x, y, WINTER_CRATER_SIZE);
}