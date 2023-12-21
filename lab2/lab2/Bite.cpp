#include "Bite.h"
#include "Pokemon.h"
Bite::Bite() : PhysicalMove(Type::DARK, 60, 100) {

}
void Bite::applyOppEffects(Pokemon& var1) {
	if (0.3 > (double)(rand()) / RAND_MAX) {
		Effect::flinch(var1);
		std::cout << "The enemy is scared" << std::endl;
	}
}
std::string Bite::describe() {
	return "performs Bite";
}