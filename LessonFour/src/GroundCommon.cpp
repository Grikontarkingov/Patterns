#include <cstring>
#include <iostream>
#include "GroundCommon.h"
#include "ScreenSingleton.h"
#include "CraterFactoryCreate.h"
#include "enums/CraterSize.h"

void GroundCommon::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_Green);

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

AbstractCrater* GroundCommon::CreateCrater(int x, int y) const {
    CreateCraterCommon* creatCraterCommon = new CreateCraterCommon;

    CraterFactoryCreate* createCraters;
    createCraters = creatCraterCommon;

    return createCraters->CreateCrater(x, y, SMALL_CRATER_SIZE);
}