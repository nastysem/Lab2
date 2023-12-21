#include "ConfusionMove.h"
#include "Pokemon.h"
ConfusionMove::~ConfusionMove() {

}
ConfusionMove ConfusionMove::getConfusionMove() {
    static ConfusionMove confusionMove(Type::NONE, 40.0, 1.0);
    return confusionMove;
}
std::string ConfusionMove::describe() {
    return Writer::getMessage(Messages::confusion);
}
void ConfusionMove::applySelfDamage(Pokemon& var1, double var2) {
    var1.setMod(Stat::HP, (int)var2);
}
void ConfusionMove::applyOppDamage(Pokemon& var1, double var2) {
}
double ConfusionMove::calcCriticalHit(Pokemon& var1, Pokemon& var2) {
    return 1.0;
}