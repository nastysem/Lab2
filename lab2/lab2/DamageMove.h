#include "Move.h"
#pragma once
class DamageMove : public Move {
public:
	using Move::Move;
	virtual ~DamageMove();
	virtual void  attack(Pokemon& var1, Pokemon& var2) override;
protected:
	virtual double calcBaseDamage(Pokemon& var1, Pokemon& var2);
	virtual double calcAttDefFactor(Pokemon& var1, Pokemon& var2) = 0;
	virtual double calcTypeEffect(Pokemon& var1, Pokemon& var2);
	virtual double calcCriticalHit(Pokemon& var1, Pokemon& var2);
	virtual double calcSameTypeAttackBonus(Pokemon& var1, Pokemon& var2);
	virtual double calcRandomDamage(Pokemon& var1, Pokemon& var2);
	virtual void applyOppDamage(Pokemon& var1, double var2);
	virtual void applySelfDamage(Pokemon& var1, double var2);
};