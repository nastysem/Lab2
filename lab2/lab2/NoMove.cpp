#include "NoMove.h"
#include "Pokemon.h"
NoMove::~NoMove() {

}
NoMove NoMove::getNoMove() {
	static NoMove noMove(Type::NONE, 0.0, 0.0, -100, 0);
	return noMove;
}

void NoMove::attack(Pokemon& var1, Pokemon& var2) {
}
std::string NoMove::describe() {
	return Writer::getMessage(Messages::noattack);
}