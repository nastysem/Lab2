#include "StoneEdge.h"
#include "Pokemon.h"
StoneEdge::StoneEdge() : PhysicalMove(Type::ROCK, 100, 80) {

}
double StoneEdge::calcCriticalHit(Pokemon& var1, Pokemon& var2) {
    if ((var1.getStat(Stat::SPEED) * 3.0) / 512.0 > (double)(rand()) / RAND_MAX) {
        std::cout << Writer::getMessage(Messages::critical) << std::endl;
        return 2.0;
    }
    else {
        return 1.0;
    }
}
std::string StoneEdge::describe() {
	return "performs Stone Edge";
}