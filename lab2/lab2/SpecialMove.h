#include "DamageMove.h"
#pragma once
class SpecialMove : public DamageMove {
public:
	virtual ~SpecialMove();
	using DamageMove::DamageMove;
	virtual double calcAttDefFactor(Pokemon& var1, Pokemon& var2) override final;
};