#pragma once

#include "GameObject.h"
#include "Crater.h"
#include <vector>


class Ground : public GameObject {
public:
  Ground() = default;
  virtual ~Ground() = default;

  void Draw() const override = 0;

  void AddCrater(double xn);

protected:
    bool isInsideAnyCrater(double x) const;
    std::vector<Craters*> vecCrates;
};
