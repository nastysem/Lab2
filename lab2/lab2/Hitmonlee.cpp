#include "Hitmonlee.h"
#include "RockTomb.h"
Hitmonlee::Hitmonlee(std::string var1, int var2): Tyrogue(var1, var2) {
	this->setType(1, Type::FIGHTING);
	this->setStats(50, 120, 53, 35, 110, 87);
	RockTomb rockTomb;
	this->addMove(std::make_shared<RockTomb>(rockTomb));
}