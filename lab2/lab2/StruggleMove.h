#include "PhysicalMove.h"
#pragma once
class StruggleMove : public PhysicalMove {
public:
	virtual ~StruggleMove();
	using PhysicalMove::PhysicalMove;
	static StruggleMove getStruggleMove();
protected:
	std::string describe() override;
	void applySelfDamage(Pokemon& var1, double var2) override;
};