#pragma once

#include <vector>
#include "DynamicObject.h"

class DestroyableGroundObject;

class Bomb : public DynamicObject
{
public:

	static const int16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;
    void Accept(const ILogVisitor& v) override;

    void AddObserver(DestroyableGroundObject* obj);
    DestroyableGroundObject* CheckDestoyableObjects();

private:
    std::vector<DestroyableGroundObject*> vecObserver;
};

