#include "SpecialMove.h"
#include "Pokemon.h"
SpecialMove::~SpecialMove() {}
double SpecialMove::calcAttDefFactor(Pokemon& var1, Pokemon& var2) {
	return var1.getStat(Stat::SPECIAL_ATTACK) / var2.getStat(Stat::SPECIAL_DEFENSE);
}