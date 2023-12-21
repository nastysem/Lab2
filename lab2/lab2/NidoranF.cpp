#include "NidoranF.h"
#include "SludgeBomb.h"
#include "Confide.h"
#include "Bite.h"
#include "ShadowBall.h"
NidoranF::NidoranF(std::string var1, int var2) : Pokemon(var1, var2) {
	this->setType(1, Type::POISON);
	this->setStats(55, 47, 52, 40, 40, 41);
	Confide confide;
	SludgeBomb sludgeBomb;
	this->setMove(2, std::make_shared<Confide>(confide), std::make_shared<SludgeBomb>(sludgeBomb));
}
