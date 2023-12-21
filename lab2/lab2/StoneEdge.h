#include "PhysicalMove.h"
#pragma once
class StoneEdge : public PhysicalMove {
public:
	StoneEdge();
protected:
	std::string describe() override;
	double calcCriticalHit(Pokemon& var1, Pokemon& var2) override;
};
