#include "SpecialMove.h"
#pragma once
class FireMove : public SpecialMove {
public:
	virtual ~FireMove();
	using SpecialMove::SpecialMove;
	void applyOppEffects(Pokemon& var1) override;
};