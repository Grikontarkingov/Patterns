#pragma once

#include "DynamicObject.h"
#include "GameObject.h"
#include "MyTools.h"
#include "Plane.h"
#include "BombDecorator.h"
#include "enums/CraterSize.h"

#include <vector>

class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;

    virtual void Execute() const = 0;
};

class DeleteDynamicObjCommand : public AbstractCommand {
public:
   DeleteDynamicObjCommand(std::vector<DynamicObject*>& vecDynamicObj, DynamicObject* pObj);

    void Execute() const override;

private:
    std::vector<DynamicObject*>& dynamicObj;
    std::unique_ptr<DynamicObject> pDynamicObj;
};

class DeleteStaticObjCommand : public AbstractCommand {
public:
    DeleteStaticObjCommand(std::vector<GameObject*>& vecStaticObj, GameObject* pObj);

    void Execute() const override;

private:
    std::vector<GameObject*>& staticObj;
    std::unique_ptr<GameObject> pStaticObj;
};

class DropBombCommand : public AbstractCommand {
public:
DropBombCommand(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score);

void Execute() const override;

private:
    const Plane* pPlane;

    std::vector<DynamicObject*>& dynamicObj;

    int16_t& m_score;
};

class DropNewBombCommand : public AbstractCommand {
public:
    DropNewBombCommand(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score);

    void Execute() const override;

private:
    const Plane* pPlane;

    std::vector<DynamicObject*>& dynamicObj;

    int16_t& m_score;
};