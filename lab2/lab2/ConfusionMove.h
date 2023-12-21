#include "PhysicalMove.h"
#pragma once
class ConfusionMove : public PhysicalMove {
public:
	virtual ~ConfusionMove();
	using PhysicalMove::PhysicalMove;
	static ConfusionMove getConfusionMove();
protected:
	std::string describe() override;
	void applySelfDamage(Pokemon& var1, double var2) override;
	void applyOppDamage(Pokemon& var1, double var2) override;
	double calcCriticalHit(Pokemon& var1, Pokemon& var2) override;

};
