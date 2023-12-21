#include "Rest.h"
#include "Pokemon.h"
Rest::Rest() : StatusMove(Type::PSYCHIC, 0, 0) {

}
bool Rest::checkAccuracy(Pokemon& var1, Pokemon& var2) {
	return true;
}
void Rest::applySelfEffects(Pokemon& var1) {
	Effect::sleep(var1);
	int HP = std::round(var1.getStat(Stat::HP) - var1.getHP());
	var1.setMod(Stat::HP, -HP);
}
std::string Rest::describe() {
	return "performs Rest";
}