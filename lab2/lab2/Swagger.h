#include "StatusMove.h"
#pragma once
class Swagger : public StatusMove {
public:
	Swagger();
protected:
	void applyOppEffects(Pokemon& var1) override;
	void applySelfEffects(Pokemon& var1) override;
	std::string describe() override;
};