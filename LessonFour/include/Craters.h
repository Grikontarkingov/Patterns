#pragma once

#include "GameObject.h"

class Craters : public GameObject{
public:
    virtual ~Craters() = default;

    virtual void Draw() const = 0;
    bool isInside(double xn) const;
};