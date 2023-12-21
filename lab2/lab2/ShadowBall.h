#include "SpecialMove.h"
#pragma once
class ShadowBall : public SpecialMove {
public: 
	ShadowBall();
protected:
	void applyOppEffects(Pokemon& var1) override;
	std::string describe() override;
};
