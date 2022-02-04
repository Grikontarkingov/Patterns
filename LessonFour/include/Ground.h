#pragma once

#include "GameObject.h"
#include "CraterCommon.h"
#include <vector>


class Ground : public GameObject {
public:
  Ground() = default;
  virtual ~Ground() = default;

  void Draw() const override = 0;

  void AddCrater(double xn);

  virtual AbstractCrater* CreateCrater(int x, int y) const = 0;

protected:
    bool isInsideAnyCrater(double x) const;
    std::vector<AbstractCrater*> vecCrates;
};
