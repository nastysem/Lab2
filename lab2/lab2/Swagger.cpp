#include "Swagger.h"
#include "Pokemon.h"
Swagger::Swagger(): StatusMove(Type::NORMAL, 0, 85) {

}
void Swagger::applyOppEffects(Pokemon& var1) {
	Effect::confuse(var1);
}
void Swagger::applySelfEffects(Pokemon& var2) {
	var2.setMod(Stat::ATTACK, 2);
}
std::string Swagger::describe() {
	return "performs Swagger";
}