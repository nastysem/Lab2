#include "PhysicalMove.h"
#pragma once
class Bite: public PhysicalMove {
public:
	Bite();
protected:
	void applyOppEffects(Pokemon& var1) override;
	std::string describe() override;
};

