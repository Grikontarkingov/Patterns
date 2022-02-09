
#include <iostream>

#include "Plane.h"
#include "MyTools.h"
#include "ScreenSingleton.h"

void Plane::Draw()
{
    DrawBody();
    DrawWings();
    DrawTail();
}

void ColorPlane::DrawBody() const {
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x, y);
    std::cout << "=========>";
}
void ColorPlane::DrawWings() const {
    ScreenSingleton::getInstance().SetColor(CC_Yellow);
    ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    std::cout << "===";
}
void ColorPlane::DrawTail() const {
    ScreenSingleton::getInstance().SetColor(CC_White);
    ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    std::cout << "////";
}

void BigPlane::DrawBody() const {
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x, y);
    std::cout << "============>";
}
void BigPlane::DrawWings() const {
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    std::cout << "=====";
}
void BigPlane::DrawTail() const {
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\\\\\";
    ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    std::cout << "//////";
}