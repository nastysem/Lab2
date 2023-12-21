#include "StatusMove.h"
#pragma once
class Confide : public StatusMove {
public:
	Confide();
protected:
	void applyOppEffects(Pokemon& var1) override;
	bool checkAccuracy(Pokemon& var1, Pokemon& var2) override;
	std::string describe() override;
};
