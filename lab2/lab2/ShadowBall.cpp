#include "ShadowBall.h"
#include "Pokemon.h"
ShadowBall::ShadowBall() : SpecialMove(Type::GHOST, 80, 100) {

}
void ShadowBall::applyOppEffects(Pokemon& var1) {
	if (0.2 > (double)(rand()) / RAND_MAX)
		var1.setMod(Stat::SPECIAL_DEFENSE, -1);
}
std::string ShadowBall::describe() {
	return "performs Shadow Ball";
}