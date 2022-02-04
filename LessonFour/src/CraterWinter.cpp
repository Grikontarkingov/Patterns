#include "CraterWinter.h"
#include "ScreenSingleton.h"
#include <iostream>
#include "enums/CraterSize.h"

void CraterWinter::Draw() const {
    if (width == WINTER_CRATER_SIZE) {
        ScreenSingleton::getInstance().GotoXY(x - 4, y + 1);
        std::cout << "==     ==";
        ScreenSingleton::getInstance().GotoXY(x - 2, y + 2);
        std::cout << "== ==";
        ScreenSingleton::getInstance().GotoXY(x - 1 , y + 3);
        std::cout << "===";
    }
}