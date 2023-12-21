#include "DamageMove.h"
#pragma once
class PhysicalMove : public DamageMove {
public:
	virtual ~PhysicalMove();
	using DamageMove::DamageMove;
protected:
	virtual double calcAttDefFactor(Pokemon& var1, Pokemon& var2) override final;
};