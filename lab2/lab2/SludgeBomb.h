#include "SpecialMove.h"
#pragma once
class SludgeBomb : public SpecialMove {
public: 
	SludgeBomb();
protected:
	void applyOppEffects(Pokemon& var1) override;
	std::string describe() override;
};