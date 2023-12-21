#include "Tyrogue.h"
#include "DoubleTeam.h"
#include "Facade.h"
#include "Rest.h"
Tyrogue::Tyrogue(std::string var1, int var2) : Pokemon(var1, var2) {
	this->setType(1, Type::FIGHTING);
	this->setStats(35, 35, 35, 35, 35, 35);
	DoubleTeam doubleTeam;
	Facade facade;
	Rest rest;
	this->setMove(3, std::make_shared<DoubleTeam>(doubleTeam), std::make_shared<Facade>(facade), std::make_shared<Rest>(rest));
}