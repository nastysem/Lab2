#include "DoubleTeam.h"
#include "Pokemon.h"
DoubleTeam::DoubleTeam() : StatusMove(Type::NORMAL, 0, 0) {

}
bool DoubleTeam::checkAccuracy(Pokemon& var1, Pokemon& var2) {
	return true;
}
void DoubleTeam::applySelfEffects(Pokemon& var1) {
	var1.setMod(Stat::EVASION, 1);
}
std::string DoubleTeam::describe() {
	return "performs Double Team";
}