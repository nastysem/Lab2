#include "SludgeBomb.h"
#include "Pokemon.h"
SludgeBomb::SludgeBomb() : SpecialMove(Type::POISON, 90, 100) {

}
void SludgeBomb::applyOppEffects(Pokemon& var1) {
	if (0.3 > (double)(rand()) / RAND_MAX)
		Effect::poison(var1);
}
std::string SludgeBomb::describe() {
	return "performs Sludge Bomb";
}