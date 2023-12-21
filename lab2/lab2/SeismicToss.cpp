#include "SeismicToss.h"
#include "Pokemon.h"
SeismicToss::SeismicToss() : PhysicalMove(Type::FIGHTING, 0, 100) {

}
void SeismicToss::applyOppDamage(Pokemon& var1, double var2) {
	PhysicalMove::applyOppDamage(var1, var1.getLevel());
}
std::string SeismicToss::describe() {
	return "performs Seismic Toss";
}