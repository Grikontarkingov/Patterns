#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:
    Bomb() {}
    Bomb(const Bomb& bomb);
	static const uint16_t BombCost = 10; // bomb cost in points

	void Draw() const override;

    DynamicObject* Clone() const override;

private:

};

