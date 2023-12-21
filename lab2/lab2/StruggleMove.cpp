#include "StruggleMove.h"
#include "Pokemon.h"
StruggleMove::~StruggleMove() {

}
StruggleMove StruggleMove::getStruggleMove() {
	static StruggleMove struggleMove(Type::NONE, 50.0, 1.0);
	return struggleMove;
}
void StruggleMove::applySelfDamage(Pokemon& var1, double var2) {
	var1.setMod(Stat::HP, (int)std::round(var2 / 4.0));
}
std::string StruggleMove::describe() {
	return Writer::getMessage(Messages::struggle);
}