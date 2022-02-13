#include "SBomber.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "ScreenSingleton.h"
#include "FileLogger.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "Bomb.h"
#include "enums/CraterSize.h"
#include <chrono>
#include <thread>

class SBomberImpl {
public:
    friend class SBomber;
    explicit SBomberImpl(FileLogger* fileLogger)
            : logger(fileLogger), exitFlag(false), startTime(0), finishTime(0), deltaTime(0), passedTime(0),
              fps(0), bombsNumber(10), score(0) {}
    void CheckPlaneAndLevelGUI() {
        if (FindPlane()->GetX() > FindLevelGUI()->GetFinishX()) {
            exitFlag = true;
        }
    }
    void CheckBombsAndGround() {
        std::vector<Bomb*> vecBombs = FindAllBombs();
        Ground* pGround = FindGround();
        const double y = pGround->GetY();
        for (size_t i = 0; i < vecBombs.size(); i++) {
            if (vecBombs[i]->GetY() >= y) {
                pGround->AddCrater(vecBombs[i]->GetX());
                CheckDestoyableObjects(vecBombs[i]);
                DeleteDynamicObj(vecBombs[i]);
            }
        }
    }
    void  CheckDestoyableObjects(Bomb* pBomb) {
        std::vector<DestroyableGroundObject*> vecDestoyableObjects =
                FindDestoyableGroundObjects();
        const double size = pBomb->GetWidth();
        const double size_2 = size / 2;
        for (size_t i = 0; i < vecDestoyableObjects.size(); i++) {
            const double x1 = pBomb->GetX() - size_2;
            const double x2 = x1 + size;
            if (vecDestoyableObjects[i]->isInside(x1, x2)) {
                score += vecDestoyableObjects[i]->GetScore();
                DeleteStaticObj(vecDestoyableObjects[i]);
            }
        }
    }

    void  DeleteDynamicObj(DynamicObject* pObj) {
        auto it = vecDynamicObj.begin();
        for (; it != vecDynamicObj.end(); it++) {
            if (*it == pObj) {
                vecDynamicObj.erase(it);
                break;
            }
        }
    }
    void  DeleteStaticObj(GameObject* pObj) {
        auto it = vecStaticObj.begin();
        for (; it != vecStaticObj.end(); it++) {
            if (*it == pObj) {
                vecStaticObj.erase(it);
                break;
            }
        }
    }

    Ground* FindGround() const {
        Ground* pGround;

        for (size_t i = 0; i < vecStaticObj.size(); i++) {
            pGround = dynamic_cast<Ground*>(vecStaticObj[i]);
            if (pGround != nullptr) {
                return pGround;
            }
        }

        return nullptr;
    }
    Plane* FindPlane() const {
        for (size_t i = 0; i < vecDynamicObj.size(); i++) {
            Plane* p = dynamic_cast<Plane*>(vecDynamicObj[i]);
            if (p != nullptr) {
                return p;
            }
        }

        return nullptr;
    }
    LevelGUI* FindLevelGUI() const {
        for (size_t i = 0; i < vecStaticObj.size(); i++) {
            LevelGUI* p = dynamic_cast<LevelGUI*>(vecStaticObj[i]);
            if (p != nullptr) {
                return p;
            }
        }

        return nullptr;
    }
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const {
        std::vector<DestroyableGroundObject*> vec;
        Tank* pTank;
        House* pHouse;
        for (size_t i = 0; i < vecStaticObj.size(); i++) {
            pTank = dynamic_cast<Tank*>(vecStaticObj[i]);
            if (pTank != nullptr) {
                vec.push_back(pTank);
                continue;
            }

            pHouse = dynamic_cast<House*>(vecStaticObj[i]);
            if (pHouse != nullptr) {
                vec.push_back(pHouse);
                continue;
            }
        }

        return vec;
    }
    std::vector<Bomb*> FindAllBombs() const {
        std::vector<Bomb*> vecBombs;

        for (size_t i = 0; i < vecDynamicObj.size(); i++) {
            Bomb* pBomb = dynamic_cast<Bomb*>(vecDynamicObj[i]);
            if (pBomb != nullptr) {
                vecBombs.push_back(pBomb);
            }
        }

        return vecBombs;
    }

    void DropBomb() {
        if (bombsNumber > 0) {
            logger->WriteToLog(std::string(__func__) + " was invoked");

            Plane* pPlane = FindPlane();
            double x = pPlane->GetX() + 4;
            double y = pPlane->GetY() + 2;

            Bomb* pBomb = new Bomb;
            pBomb->SetDirection(0.3, 1);
            pBomb->SetSpeed(2);
            pBomb->SetPos(x, y);
            pBomb->SetWidth(SMALL_CRATER_SIZE);

            vecDynamicObj.push_back(pBomb);
            bombsNumber--;
            score -= Bomb::BombCost;
        }
    }

private:
    std::vector<DynamicObject *> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    FileLogger* logger;

    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

SBomber::SBomber(FileLogger* fileLogger) : logger(fileLogger){
    sBomberImpl = std::make_unique<SBomberImpl>(logger);
    ScreenSingleton::getInstance().SetFileLogger(logger);
    logger->WriteToLog(std::string(__func__) + " was invoked");


  Plane* p = new Plane;
  p->SetDirection(1, 0.1);
  p->SetSpeed(4);
  p->SetPos(5, 10);
  sBomberImpl->vecDynamicObj.push_back(p);

  LevelGUI* pGUI = new LevelGUI;
  pGUI->SetParam(sBomberImpl->passedTime, sBomberImpl->fps, sBomberImpl->bombsNumber, sBomberImpl->score);
  const uint16_t maxX = ScreenSingleton::getInstance().GetMaxX();
  const uint16_t maxY = ScreenSingleton::getInstance().GetMaxY();
  const uint16_t offset = 3;
  const uint16_t width = maxX - 7;
  pGUI->SetPos(offset, offset);
  pGUI->SetWidth(width);
  pGUI->SetHeight(maxY - 4);
  pGUI->SetFinishX(offset + width - 4);
    sBomberImpl->vecStaticObj.push_back(pGUI);

  Ground* pGr = new Ground;
  const uint16_t groundY = maxY - 5;
  pGr->SetPos(offset + 1, groundY);
  pGr->SetWidth(width - 2);
    sBomberImpl->vecStaticObj.push_back(pGr);

  Tank* pTank = new Tank;
  pTank->SetWidth(13);
  pTank->SetPos(30, groundY - 1);
    sBomberImpl->vecStaticObj.push_back(pTank);

  pTank = new Tank;
  pTank->SetWidth(13);
  pTank->SetPos(50, groundY - 1);
    sBomberImpl->vecStaticObj.push_back(pTank);

  House* pHouse = new House;
  pHouse->SetWidth(13);
  pHouse->SetPos(80, groundY - 1);
    sBomberImpl->vecStaticObj.push_back(pHouse);

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
  for (size_t i = 0; i < sBomberImpl->vecDynamicObj.size(); i++) {
    if (sBomberImpl->vecDynamicObj[i] != nullptr) {
      delete sBomberImpl->vecDynamicObj[i];
    }
  }

  for (size_t i = 0; i < sBomberImpl->vecStaticObj.size(); i++) {
    if (sBomberImpl->vecStaticObj[i] != nullptr) {
      delete sBomberImpl->vecStaticObj[i];
    }
  }
}

void SBomber::MoveObjects() {
    logger->WriteToLog(std::string(__func__) + " was invoked");

  for (size_t i = 0; i < sBomberImpl->vecDynamicObj.size(); i++) {
    if (sBomberImpl->vecDynamicObj[i] != nullptr) {
        sBomberImpl->vecDynamicObj[i]->Move(sBomberImpl->deltaTime);
    }
  }
};

void SBomber::CheckObjects() {
    logger->WriteToLog(std::string(__func__) + " was invoked");

    sBomberImpl->CheckPlaneAndLevelGUI();
    sBomberImpl->CheckBombsAndGround();
};

void SBomber::ProcessKBHit() {
  int c = getchar();

  if (c == 224) {
    c = getchar();
  }

    logger->WriteToLog(std::string(__func__) + " was invoked. key = ", c);

  switch (c) {

    case 27: // esc
        sBomberImpl->exitFlag = true;
      break;

    case 72: // up
        sBomberImpl->FindPlane()->ChangePlaneY(-0.25);
      break;

    case 80: // down
        sBomberImpl->FindPlane()->ChangePlaneY(0.25);
      break;

    case 'b':
        sBomberImpl->DropBomb();
      break;

    case 'B':
        sBomberImpl->DropBomb();
      break;

    default:
      break;
  }
}

void SBomber::DrawFrame() {
    logger->WriteToLog(std::string(__func__) + " was invoked");

    for (size_t i = 0; i < sBomberImpl->vecDynamicObj.size(); i++) {
        if (sBomberImpl->vecDynamicObj[i] != nullptr) {
            sBomberImpl->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < sBomberImpl->vecStaticObj.size(); i++) {
        if (sBomberImpl->vecStaticObj[i] != nullptr) {
            sBomberImpl->vecStaticObj[i]->Draw();
        }
    }

    ScreenSingleton::getInstance().GotoXY(0, 0);
    sBomberImpl->fps++;

    sBomberImpl->FindLevelGUI()->SetParam(sBomberImpl->passedTime, sBomberImpl->fps, sBomberImpl->bombsNumber, sBomberImpl->score);
}

void SBomber::TimeStart() {
    logger->WriteToLog(std::string(__func__) + " was invoked");
    sBomberImpl->startTime = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

void SBomber::TimeFinish() {
    sBomberImpl->finishTime = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    sBomberImpl->deltaTime = uint16_t(sBomberImpl->finishTime - sBomberImpl->startTime);
    sBomberImpl->passedTime += sBomberImpl->deltaTime;

    logger->WriteToLog(std::string(__func__) + " deltaTime = ", (int)sBomberImpl->deltaTime);
}

bool SBomber::GetExitFlag() const {
    return sBomberImpl->exitFlag;
}