#include "FireMove.h"
#include "Pokemon.h"
FireMove::~FireMove() {}
void FireMove::applyOppEffects(Pokemon& var1) {
	Effect var2;
	var2 = var2.condition(Status::FREEZE).chance(0.8).attacks(0.0).setTurns(-1);
	var1.setCondition(var2);
}