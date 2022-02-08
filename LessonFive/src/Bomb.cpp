#include <iostream>

#include "Bomb.h"
#include "ScreenSingleton.h"
#include "ILogVisitor.h"
#include "DestroyableGroundObject.h"

void Bomb::Draw() const {
  //ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
  ScreenSingleton::getInstance().GotoXY(x, y);
  std::cout << "*";
}

void Bomb::Accept(const ILogVisitor& v) {
    v.Log(*this);
}

void Bomb::AddObserver(DestroyableGroundObject* obj) {
    vecObserver.push_back(obj);
}

DestroyableGroundObject* Bomb::CheckDestoyableObjects() {
    const double size = this->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecObserver.size(); i++) {
        const double x1 = this->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecObserver[i]->HandleInsideCheck(x1, x2)) {
            return vecObserver[i];
        }
    }

    return nullptr;
}