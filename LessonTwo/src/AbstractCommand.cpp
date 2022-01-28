#include "AbstractCommand.h"

DeleteDynamicObjCommand::DeleteDynamicObjCommand(std::vector<DynamicObject*>& vecDynamicObj, DynamicObject* pObj)
: dynamicObj(vecDynamicObj), pDynamicObj(pObj) {}

void DeleteDynamicObjCommand::Execute() const {
    auto it = dynamicObj.begin();
    for (; it != dynamicObj.end(); it++) {
        if (*it == pDynamicObj.get()) {
            dynamicObj.erase(it);
            break;
        }
    }
}

DeleteStaticObjCommand::DeleteStaticObjCommand(std::vector<GameObject*>& vecStaticObj, GameObject* pObj)
: staticObj(vecStaticObj), pStaticObj(pObj) {}

void DeleteStaticObjCommand::Execute() const {
    auto it = staticObj.begin();
    for (; it != staticObj.end(); it++) {
        if (*it == pStaticObj.get()) {
            staticObj.erase(it);
            break;
        }
    }
}

DropBombCommand::DropBombCommand(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score)
: pPlane(plane), dynamicObj(vecDynamicObj), m_score(score) {}

void DropBombCommand::Execute() const {
    MyTools::WriteToLog(std::string(__func__) + " was invoked");

    double x = pPlane->GetX() + 4;
    double y = pPlane->GetY() + 2;

    IBomb* pBomb = new Bomb;
    pBomb->SetDirection(0.3, 1);
    pBomb->SetSpeed(2);
    pBomb->SetPos(x, y);
    pBomb->SetWidth(SMALL_CRATER_SIZE);

    dynamicObj.push_back(pBomb);
    m_score -= Bomb::BombCost;
}

DropNewBombCommand::DropNewBombCommand(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score)
: pPlane(plane), dynamicObj(vecDynamicObj), m_score(score) {}

void DropNewBombCommand::Execute() const {
    MyTools::WriteToLog(std::string(__func__) + " was invoked");

    double x = pPlane->GetX() + 4;
    double y = pPlane->GetY() + 2;

    IBomb* pBomb = new Bomb;
    pBomb->SetDirection(0.3, 1);
    pBomb->SetSpeed(2);
    pBomb->SetPos(x, y);
    pBomb->SetWidth(SMALL_CRATER_SIZE);
    IBomb* pBombDec = new BombDecorator(pBomb);

    dynamicObj.push_back(pBombDec);
    m_score -= Bomb::BombCost;
}