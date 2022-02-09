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

    /*static */void SetMediator(Mediator* mediator);

private:
    std::string GetRandomMessage() const;
    uint16_t GetRandomNumber(uint16_t upper) const;

    /*static */Mediator* pMediator;

    std::vector<std::string> allMessages;

	const uint16_t score = 30;
};

