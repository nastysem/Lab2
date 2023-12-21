#include "PhysicalMove.h"
#pragma once
class SeismicToss : public PhysicalMove {
public:
	SeismicToss();
protected:
	void applyOppDamage(Pokemon& var1, double var2) override;
	std::string describe() override;
};