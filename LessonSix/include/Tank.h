#pragma once

#include <stdint.h>
#include <vector>

#include "DestroyableGroundObject.h"

class Mediator;

class Tank : public DestroyableGroundObject
{
public:
    Tank();

	bool  isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() override;

    void SetStaticMediator(Mediator* mediator);

private:
    std::string GetMessage() const;
    uint16_t GetRandomNumber(uint16_t upper) const;

    Mediator* pMediator;

    std::vector<std::string> vecAllMessagesOfTank;

	const uint16_t score = 30;
};

