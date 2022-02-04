#pragma once

#include "GameObject.h"
#include "AbstractCrater.h"
#include <vector>
#include <memory>


class Ground : public GameObject {
public:
  Ground() = default;
  virtual ~Ground() = default;

  void Draw() const override = 0;

  void AddCrater(double xn);

  virtual AbstractCrater* CreateCrater() = 0;

protected:
    bool isInsideAnyCrater(double x) const;
    std::vector<AbstractCrater*> vecCrates;
};
