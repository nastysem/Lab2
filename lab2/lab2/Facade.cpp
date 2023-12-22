#include "Facade.h"
#include "Pokemon.h"
Facade::Facade() : PhysicalMove(Type::NORMAL, 70, 100) {

}
double Facade::calcBaseDamage(Pokemon& var1, Pokemon& var2) {
	if (var2.getCondition() == Status::POISON || var2.getCondition() == Status::BURN || var2.getCondition() == Status::PARALYZE) {
		std::cout << "Pokemon acts with double power!";
		return PhysicalMove::calcBaseDamage(var1, var2) * 2;
	}
	else {
		return PhysicalMove::calcBaseDamage(var1, var2);
	}
}
std::string Facade::describe() {
	return "performs Facade";
}