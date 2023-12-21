#include "Confide.h"
#include "Pokemon.h"
Confide::Confide() : StatusMove(Type::NORMAL, 0, 0) {

}
void Confide::applyOppEffects(Pokemon& var1) {
	var1.setMod(Stat::SPECIAL_ATTACK, -1);
}
bool Confide::checkAccuracy(Pokemon& var1, Pokemon& var2) {
	return true;
}
std::string Confide::describe() {
	return "performs Confide";
}