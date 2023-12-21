#include "Nidorina.h"
#include "Bite.h"
Nidorina::Nidorina(std::string var1, int var2) : NidoranF(var1, var2) {
	this->setStats(70, 62, 67, 55, 55, 56);
	Bite bite;
	this->addMove(std::make_shared<Bite>(bite));
}