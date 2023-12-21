#include "RockTomb.h"
#include "Pokemon.h"
RockTomb::RockTomb() : PhysicalMove(Type::ROCK, 60, 95) {

}
void RockTomb::applyOppEffects(Pokemon& var1) {
	var1.setMod(Stat::SPEED, -1);
}
std::string RockTomb::describe() {
	return "performs Rock Tomb";
}