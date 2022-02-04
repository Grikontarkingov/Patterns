#pragma once

#include "GameObject.h"

class AbstractCrater : public GameObject{
public:
    virtual ~AbstractCrater() = default;

    virtual void Draw() const = 0;
    bool isInside(double xn) const;
};