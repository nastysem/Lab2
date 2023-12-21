#include "Move.h"
#pragma once
class StatusMove : public Move {
public:
	using Move::Move;
	virtual ~StatusMove();
	virtual void attack(Pokemon& var1, Pokemon& var2) override final;
protected:
	virtual void applyOppEffects(Pokemon& var2);
	virtual void applySelfEffects(Pokemon& var1);
};