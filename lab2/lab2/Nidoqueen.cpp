#include "Nidoqueen.h"
#include "ShadowBall.h"
Nidoqueen::Nidoqueen(std::string var1, int var2) : Nidorina(var1, var2) {
	this->addType(Type::GROUND);
	this->setStats(90, 92, 87, 75, 85, 76);
	ShadowBall shadowBall;
	this->addMove(std::make_shared<ShadowBall>(shadowBall));
}