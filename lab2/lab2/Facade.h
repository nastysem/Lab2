#include "PhysicalMove.h"
#pragma once
class Facade : public PhysicalMove {
public:
	Facade();
protected:
	double calcBaseDamage(Pokemon& var1, Pokemon& var2) override;
	std::string describe() override;
};