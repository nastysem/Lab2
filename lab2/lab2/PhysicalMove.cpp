#include "PhysicalMove.h"
#include "Pokemon.h"
PhysicalMove::~PhysicalMove() {}
double PhysicalMove::calcAttDefFactor(Pokemon& var1, Pokemon& var2) {
	return var1.getStat(Stat::ATTACK) / var2.getStat(Stat::DEFENSE);
}