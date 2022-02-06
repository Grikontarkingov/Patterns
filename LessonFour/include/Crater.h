#pragma once

#include "GameObject.h"

class Crater : public GameObject{
public:
    virtual ~Crater() = default;

    bool isInside(double xn) const;
};