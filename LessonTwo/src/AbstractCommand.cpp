#include "AbstractCommand.h"

IBomb* DropBombParent::CreateBomb() const{
    MyTools::WriteToLog(std::string(__func__) + " was invoked");

    double x = pPlane->GetX() + 4;
    double y = pPlane->GetY() + 2;

    std::unique_ptr<IBomb> pBomb = std::make_unique<Bomb>();
    pBomb->SetDirection(0.3, 1);
    pBomb->SetSpeed(2);
    pBomb->SetPos(x, y);
    pBomb->SetWidth(SMALL_CRATER_SIZE);

    return pBomb.release();
}

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
: dynamicObj(vecDynamicObj), m_score(score) {
    pPlane = plane;
}

void DropBombCommand::Execute() const {
    dynamicObj.push_back(CreateBomb());
    m_score -= Bomb::BombCost;
}

DropNewBombCommand::DropNewBombCommand(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score)
: dynamicObj(vecDynamicObj), m_score(score) {
    pPlane = plane;
}

void DropNewBombCommand::Execute() const {
    std::unique_ptr<IBomb> pBombDec = std::make_unique<BombDecorator>(CreateBomb());

    dynamicObj.push_back(pBombDec.release());
    m_score -= Bomb::BombCost;
}