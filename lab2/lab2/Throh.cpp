#include "Throh.h"
#include "SeismicToss.h"
#include "Confide.h"
#include "StoneEdge.h"
#include "Swagger.h"
Throh::Throh(std::string var1, int var2) : Pokemon(var1, var2) {
	this->setType(1, Type::FIGHTING);
	this->setStats(120, 100, 85, 30, 85, 45);
	Confide confide;
	SeismicToss seismicToss;
	StoneEdge stoneEdge;
	Swagger swagger;
	this->setMove(4, std::make_shared<Confide>(confide), std::make_shared<SeismicToss>(seismicToss), std::make_shared<StoneEdge>(stoneEdge), std::make_shared<Swagger>(swagger));
}
