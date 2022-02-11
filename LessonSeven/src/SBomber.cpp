
#include "SBomber.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "ScreenSingleton.h"
#include "FileLogger.h"
#include "SBomberImpl.h"
#include "Plane.h"
#include "LevelGUI.h"
#include <chrono>
#include <thread>

SBomber::SBomber() {
    FileLogger::WriteToLog(std::string(__func__) + " was invoked");

    sBomber = new SBomberImpl;

  Plane* p = new Plane;
  p->SetDirection(1, 0.1);
  p->SetSpeed(4);
  p->SetPos(5, 10);
  sBomber->vecDynamicObj.push_back(p);

  LevelGUI* pGUI = new LevelGUI;
  pGUI->SetParam(sBomber->passedTime, sBomber->fps, sBomber->bombsNumber, sBomber->score);
  const uint16_t maxX = ScreenSingleton::getInstance().GetMaxX();
  const uint16_t maxY = ScreenSingleton::getInstance().GetMaxY();
  const uint16_t offset = 3;
  const uint16_t width = maxX - 7;
  pGUI->SetPos(offset, offset);
  pGUI->SetWidth(width);
  pGUI->SetHeight(maxY - 4);
  pGUI->SetFinishX(offset + width - 4);
    sBomber->vecStaticObj.push_back(pGUI);

  Ground* pGr = new Ground;
  const uint16_t groundY = maxY - 5;
  pGr->SetPos(offset + 1, groundY);
  pGr->SetWidth(width - 2);
    sBomber->vecStaticObj.push_back(pGr);

  Tank* pTank = new Tank;
  pTank->SetWidth(13);
  pTank->SetPos(30, groundY - 1);
    sBomber->vecStaticObj.push_back(pTank);

  pTank = new Tank;
  pTank->SetWidth(13);
  pTank->SetPos(50, groundY - 1);
    sBomber->vecStaticObj.push_back(pTank);

  House* pHouse = new House;
  pHouse->SetWidth(13);
  pHouse->SetPos(80, groundY - 1);
    sBomber->vecStaticObj.push_back(pHouse);

  /*
  Bomb* pBomb = new Bomb;
  pBomb->SetDirection(0.3, 1);
  pBomb->SetSpeed(2);
  pBomb->SetPos(51, 5);
  pBomb->SetSize(SMALL_CRATER_SIZE);
  vecDynamicObj.push_back(pBomb);
  */
}

SBomber::~SBomber() {
  for (size_t i = 0; i < sBomber->vecDynamicObj.size(); i++) {
    if (sBomber->vecDynamicObj[i] != nullptr) {
      delete sBomber->vecDynamicObj[i];
    }
  }

  for (size_t i = 0; i < sBomber->vecStaticObj.size(); i++) {
    if (sBomber->vecStaticObj[i] != nullptr) {
      delete sBomber->vecStaticObj[i];
    }
  }
}

void SBomber::MoveObjects() {
    FileLogger::WriteToLog(std::string(__func__) + " was invoked");

  for (size_t i = 0; i < sBomber->vecDynamicObj.size(); i++) {
    if (sBomber->vecDynamicObj[i] != nullptr) {
        sBomber->vecDynamicObj[i]->Move(sBomber->deltaTime);
    }
  }
};

void SBomber::CheckObjects() {
    FileLogger::WriteToLog(std::string(__func__) + " was invoked");

    sBomber->CheckPlaneAndLevelGUI();
    sBomber->CheckBombsAndGround();
};

void SBomber::ProcessKBHit() {
  int c = getchar();

  if (c == 224) {
    c = getchar();
  }

    FileLogger::WriteToLog(std::string(__func__) + " was invoked. key = ", c);

  switch (c) {

    case 27: // esc
        sBomber->exitFlag = true;
      break;

    case 72: // up
        sBomber->FindPlane()->ChangePlaneY(-0.25);
      break;

    case 80: // down
        sBomber->FindPlane()->ChangePlaneY(0.25);
      break;

    case 'b':
        sBomber->DropBomb();
      break;

    case 'B':
        sBomber->DropBomb();
      break;

    default:
      break;
  }
}

void SBomber::DrawFrame() {
    FileLogger::WriteToLog(std::string(__func__) + " was invoked");

    for (size_t i = 0; i < sBomber->vecDynamicObj.size(); i++) {
        if (sBomber->vecDynamicObj[i] != nullptr) {
            sBomber->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < sBomber->vecStaticObj.size(); i++) {
        if (sBomber->vecStaticObj[i] != nullptr) {
            sBomber->vecStaticObj[i]->Draw();
        }
    }

    ScreenSingleton::getInstance().GotoXY(0, 0);
    sBomber->fps++;

    sBomber->FindLevelGUI()->SetParam(sBomber->passedTime, sBomber->fps, sBomber->bombsNumber, sBomber->score);
}

void SBomber::TimeStart() {
    FileLogger::WriteToLog(std::string(__func__) + " was invoked");
    sBomber->startTime = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

void SBomber::TimeFinish() {
    sBomber->finishTime = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    sBomber->deltaTime = uint16_t(sBomber->finishTime - sBomber->startTime);
    sBomber->passedTime += sBomber->deltaTime;

    FileLogger::WriteToLog(std::string(__func__) + " deltaTime = ", (int)sBomber->deltaTime);
}

bool SBomber::GetExitFlag() const {
    return sBomber->exitFlag;
}