#pragma once

#include "IBomb.h"

class Bomb : public IBomb
{
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����

	void Draw() const override;

private:

};

