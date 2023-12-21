#include "PhysicalMove.h"
#pragma once
class RockTomb : public PhysicalMove {
public:
	RockTomb();
protected:
	void applyOppEffects(Pokemon& var1) override;
	std::string describe() override;
};