#include "StatusMove.h"
#pragma once
class Rest : public StatusMove {
public:
	Rest();
protected:
	bool checkAccuracy(Pokemon& var1, Pokemon& var2) override;
	void applySelfEffects(Pokemon& var1);
	std::string describe();
};
