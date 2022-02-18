#pragma once

#include <stdint.h>

#include "GameObject.h"

class DestroyableGroundObject : public GameObject
{
public:

    virtual bool  isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

    virtual DestroyableGroundObject* Clone() = 0;

    virtual void SetX(double nx) = 0;

protected:

};