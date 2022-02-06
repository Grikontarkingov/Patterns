#pragma once

#include "GameObject.h"
#include "Crater.h"
#include <vector>
#include <memory>


class Ground : public GameObject {
public:
  Ground() = default;
  virtual ~Ground() = default;

  void AddCrater(double xn);

  virtual Crater* CreateCrater() = 0;

protected:
    bool isInsideAnyCrater(double x) const;
    std::vector<Crater*> vecCrates;
};
