#pragma once

#include <vector>
#include <cstdint>

class Bomb;
class DynamicObject;
class GameObject;
class Ground;
class Plane;
class LevelGUI;
class DestroyableGroundObject;

class SBomberImpl {
public:
    SBomberImpl();
    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void  CheckDestoyableObjects(Bomb* pBomb);

    void  DeleteDynamicObj(DynamicObject * pBomb);
    void  DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject *> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};


