#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:
    Tank() {}
    Tank(const Tank& house);

	bool  isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

    DestroyableGroundObject* Clone() override;

    void SetX(double nx) override;

private:

	const uint16_t score = 30;
};

