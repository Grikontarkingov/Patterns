#pragma once

#include "DestroyableGroundObject.h"
#include <cstdint>

class House : public DestroyableGroundObject {
public:
    House() {}
    House(const House& house);

  bool isInside(double x1, double x2) const override;

  inline uint16_t GetScore() const override {
    return score;
  }

  void Draw() const override;

  DestroyableGroundObject* Clone() override;

  void SetX(double x) override;

private:
  const uint16_t score = 40;
};
