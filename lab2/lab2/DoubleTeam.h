#include "StatusMove.h"
#pragma once
class DoubleTeam : public StatusMove {
public:
	DoubleTeam();
protected:
	bool checkAccuracy(Pokemon& var1, Pokemon& var2) override;
	void applySelfEffects(Pokemon& var1);
	std::string describe() override;
};